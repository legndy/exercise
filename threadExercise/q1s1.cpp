#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

const int count = 50;
int flag = 10;
std::mutex mtex;

void fun(int num, string &str) {
    for (int i = 0; i < count; ++i) {
        while (num != flag) {
            std::this_thread::yield();
        }
        mtex.lock();
        for (int j = 0; j < num; ++j) {
            cout << str << endl;
        }
        flag = (flag == 10) ? 100 : 10;
        mtex.unlock();
    }
}

int main(int argc, char const *argv[])
{
    thread child(fun, 10, "child");
    fun(100, "father");
    child.join();
    return 0;
}
