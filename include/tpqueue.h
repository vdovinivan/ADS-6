// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T a[100];
  int sta;
  int sto;
 public:
TPQueue() :sta(0), sto(0) { }
  void push(T val) {
      int i = sto++;
      while ((--i >= sta) && (a[i % size].prior < val.prior)) {
        a[(i + 1) % size] = a[i % size];
      }
      a[(i + 1) % size] = val;
  }
  T pop() {
    return a[(sta++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
