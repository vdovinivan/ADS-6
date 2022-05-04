// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T a[100];
  int start;
  int stop;
 public:
TPQueue() :start(0), stop(0) { }
  void push(T x) {
      int i = stop++;
      while ((--i >= start) && (a[i % size].prior < x.prior)) {
        a[(i + 1) % size] = a[i % size];
      }
      a[(i + 1) % size] = x;
  }
  T pop() {
    return a[(start++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
