#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <vector>
#include <queue>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
#include <iostream>

namespace tp
{

#define MAX_THREAD 128

    class threadPool
    {
    private:
        using Task = std::function<void()>;
        std::vector<std::thread> pool;
        //lvalue
        std::queue<Task> tasks;
        std::mutex m_lock;
        std::condition_variable cv;
        std::atomic<bool> isPoolClosed;
        std::atomic<int> numOfIdleThread;

    public:
        threadPool(size_t size = 5) : isPoolClosed(false)
        {
            numOfIdleThread = size < 1 ? 5 : size;
            for (size = 0; size < numOfIdleThread; ++size)
            {
                //开始添加工作线程
                pool.emplace_back([this]() {
                    //在当前线程池未关闭的情况下
                    while (!this->isPoolClosed)
                    {
                        Task task;
                        {
                            std::unique_lock<std::mutex> u_lock(m_lock);
                            //若有工作则继续执行，否则阻塞当前线程
                            //线程池被销毁时继续执行
                            this->cv.wait(u_lock, [this] {
                                return this->isPoolClosed || !this->tasks.empty();
                            });
                            //判断是哪种继续的情况
                            if (this->isPoolClosed && this->tasks.empty())
                            {
                                return;
                            }
                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }
                        this->numOfIdleThread--;
                        task();
                        this->numOfIdleThread++;
                    }
                });
                // std::cout << "thread " << size + 1 << " is created" << std::endl;
            }
        }

        //析构时唤醒所有线程并等待其执行完
        ~threadPool()
        {
            isPoolClosed.store(true);
            cv.notify_all();
            for (auto &thread : pool)
            {
                //若线程为执行的线程，则等待其执行完毕。
                //若销毁一个joinable的线程会跳错，需调用join或detach
                if (thread.joinable())
                {
                    thread.join();
                }
            }
        }

        //接受可变参数的commit
        //使用future来接受线程的未来返回值
        template <class F, class... Args>
        auto commit(F &&f, Args &&... args) -> std::future<decltype(f(args...))>
        {
            using reType = decltype(f(args...));
            using task = std::packaged_task<reType()>;
            //封装任务函数及其参数,成为一个future的智能指针
            auto t = std::make_shared<task>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
            auto ret = t->get_future();
            {
                std::lock_guard<std::mutex> g_lock(m_lock);
                tasks.emplace([t] { (*t)(); });
            }
            cv.notify_one();
            return ret;
        }
    };
    template <typename T>
    void print(T &t)
    {
        std::cout << "lvalue" << std::endl;
    }

    template <typename T>
    void print(const T &t)
    {
        std::cout << "rvalue" << std::endl;
    }

} // namespace tp

#endif