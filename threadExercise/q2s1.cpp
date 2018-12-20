#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int main(int argc, char const *argv[])
{
    int cnt = 0;
    std::mutex mtx;
    auto fun = [&] (char ch, int num) {
        while (num--) {
            while (ch != cnt + 'A') {
                std::this_thread::yield();
            }
            mtx.lock();
            cout<< ch;
            cnt = (cnt + 1) % 3;
            mtx.unlock();
        }
    };
    thread A(fun, 'A', 10);
    thread B(fun, 'B', 10);
    fun('C', 10);
    A.join();
    B.join();
    return 0;
}
