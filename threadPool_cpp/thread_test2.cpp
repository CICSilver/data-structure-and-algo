#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <iostream>
#include <condition_variable>
#include <list>

using namespace std;

class thread_test
{
    mutex m_lock;
    condition_variable cv;
    list<int> msgList;

public:
    void inMsgList()
    {
        unique_lock<mutex> u_lock(m_lock);
        for (int i = 0; i < 100; ++i)
        {
            cout << "[W] : writing " << i << " into the msgList." << endl;
            msgList.emplace_back(i);
        }
        //写完后尝试唤醒被wait阻塞的线程
        cv.notify_all();
    }

    void outMskList()
    {
        int res = 0;
        while (1)
        {
            unique_lock<mutex> u_lock(m_lock);
            //判断消息队列是否为空，不为空则继续，否则阻塞线程等待写线程
            cv.wait(u_lock, [this]() { return !msgList.empty(); });
            res = msgList.front();
            msgList.pop_front();
            cout << "[R] : reading " << res << " from the msgList." << endl;
            u_lock.unlock();
            if(msgList.empty())
            {
                break;
            }
        }
    }
};

int main()
{
    thread_test t;
    cout << "main thread's id : " << this_thread::get_id() << endl;

    thread in_thread(&thread_test::outMskList, &t);
    thread out_thread(&thread_test::inMsgList, &t);


    out_thread.detach();
    in_thread.detach();
    // in_thread.join();
    // out_thread.join();
    cout << "main is done..." << endl;
    chrono::milliseconds(100000);
    while(1)
    {}
    return 0;
}