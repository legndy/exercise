#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
using namespace std;

atomic<int> g_Flag(0), cnt(0);

void thread1(future<int> fu) {
    cout << "thread1" << endl;
    g_Flag = 1;
    fu.get();
    cout << "thread1 exit" << endl;
    ++cnt;
}

void thread2(promise<int> pro) {
    std::this_thread::sleep_for(chrono::microseconds(10));
    cout << "thread2" << endl;
    g_Flag = 2;
    ++cnt;
    cout << "thread2 exit" << endl;
    pro.set_value(1);
}

int main(int argc, char const *argv[])
{
    promise<int> prom;
    future<int> fu = prom.get_future();
    thread t1(thread1, move(fu));
    thread t2(thread2, move(prom));
    t1.detach();
    t2.detach();
    while (cnt < 2);
    cout << "main thread exit" << endl;

    return 0;
}

