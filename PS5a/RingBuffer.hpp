#include <stdint.h>
#include <iostream>

#define DECAY 0.996

using namespace std;

class RingBuffer {
public:
    RingBuffer(int capacity);

    int size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
    int get(int x);
    void print();

private:
    int capacity;
    int16_t temp_first;
    int* vector;
};