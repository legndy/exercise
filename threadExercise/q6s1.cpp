#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

condition_variable cv;
mutex mtx;
int gFlag = 0;
int cnt = 0;
bool flag = false;

int main(int argc, char const *argv[])
{
    thread t1([&] {
        std::unique_lock<std::mutex> lk(mtx);
        cout << "thread1" << endl;
        gFlag = 1;
        cv.wait(lk, [&] {
            return flag;
        });
        ++cnt;
        cout << "thread1 exit" << endl;
    });

    thread t2([&] {
        std::this_thread::sleep_for(std::chrono::microseconds(10));
        std::unique_lock<std::mutex> lk(mtx);
        cout << "thread2" << endl;
        ++cnt;
        gFlag = 2;
        flag = true;
        cv.notify_all();
        cout << "thread2 exit" << endl;
    });

    t1.detach();
    t2.detach();

    unique_lock<mutex> lk(mtx);
    cv.wait(lk, [&] {
        return cnt == 2;
    });
    cout << "main exit" << endl;
    return 0;
}
