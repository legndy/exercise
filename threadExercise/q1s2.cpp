#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

const int count = 50;
int flag = 10;
condition_variable cv;
std::mutex mtex;

void fun(int num, string str) {
    for (int i = 0; i < count; ++i) {
        unique_lock<std::mutex> lk(mtex);
        cv.wait(lk, [&] {
            return num == flag;
        });
        for (int j = 0; j < num; ++j) {
            cout << str << endl;
            cout << str << "count:" << i << "cnt:" << j << endl;
        }
        flag = (flag == 10) ? 100 : 10;
        //mtex.unlock();
        cv.notify_one();
    }
}

int main() {
    thread child(fun, 10, "child");
    fun(100, "father");
    child.join();
    return 0;
}