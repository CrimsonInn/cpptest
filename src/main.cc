#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <string>
#include "./func.h"
#include "./func2.h"
#include "./test_protobuf.h"

using namespace std;

void calc(float *A, size_t n) {
  float tmp = 0.0;
  for (size_t i = 0;i < n; ++i)
    tmp += A[i];
}


int main() {

  print();
  print2();
  vector<thread> th;

  float *A = new float[1<<28];
  size_t num_threads = 3;
  for (size_t i = 0;i < num_threads; ++i)
    th.push_back(thread(calc, A, 1<<28));
  for (auto &t : th) {
      t.join();
    }
  cout << thread::hardware_concurrency() << endl;

  write_protobuf();

  read_protobuf();

  return 0;
}

