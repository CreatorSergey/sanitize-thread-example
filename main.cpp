#include <iostream>
#include <thread>
#include <mutex>

int x = 0;
std::mutex mutex_;

void print_x() { std::cerr << "x is " << x << std::endl; }

void set_x(int new_x) { x = new_x; }

void thread1() { 
 // std::lock_guard<std::mutex> lk(mutex_); 
print_x(); }

void thread2() { 
  // std::lock_guard<std::mutex> lk(mutex_); 
    set_x(1); }

int main() {
  std::thread t1(thread1);
  std::thread t2(thread2);

  t1.join();
  t2.join();

  return 0;
}