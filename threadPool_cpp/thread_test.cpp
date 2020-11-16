#include "threadPool.h"

using std::cout;
using std::endl;

void thread_proc1()
{
    cout << "here is thread_proc1(), return nothing;\n" << endl;
}

int thread_proc2(int a)
{
    cout << "here is thread_proc2(int) , return an int;\n" << endl;
    return a;
}

int main()
{
    int a = 10;
    int b = 20;
    tp::threadPool thread_pool(50);
    std::future<void> res1 =  thread_pool.commit(thread_proc1);
    std::future<int> res2 = thread_pool.commit(thread_proc2, a);
    std::future<int> res3 = thread_pool.commit([](int a, int b) {cout << "here is thread_3(int,int) , return int + int;\n" << endl;return a + b; }, a, b);
    cout << res2.get() << endl;
    cout << res3.get() << endl;

    return 0;
}