#include <stdint.h>
#include <iostream>
#include <vector>
#include <stdexcept>

#define DECAY 0.996

using namespace std;

class RingBuffer {
public:
    RingBuffer(int capacity);

    int ringSize();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
    int get(int x);
    //void print();

    void empty();

private:
    int capacity, size, first, last;
    int16_t temp_first;
    std::vector<int16_t> vector;
    
};