// Copyright 2021 NNTU-CS

#include <iostream>

template<typename T, int size>
class TPQueue {
private:
T arr[50];
int write;
int read;
public:
TPQueue() :write(0), read(0) { }
void push(T x) {
int cur = read++;
while ((--cur >= write) && (arr[cur % size].prior < x.prior)) {
arr[(cur + 1) % size] = arr[cur % size];
}
arr[(cur + 1) % size] = x;
}
T pop() {
return arr[(write++) % size];
}
};

struct SYM {
char ch;
int prior;
