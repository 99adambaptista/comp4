#include "GuitarString.hpp"

#define DECAY 0.996

GuitarString::GuitarString(double frequency) : rb(ceil(44100/frequency)) {
    count = 0;
}
GuitarString::GuitarString(vector<Int16> init) : rb(init.size()) {
    for (unsigned i = 0; i < init.size(); i++)
        rb.enqueue(init[i]);
    count = 0;
}

void GuitarString::pluck() {
    rb.empty();
    while (!rb.isFull())
        rb.enqueue((int16_t)(rand() & 0xffff));
}

void GuitarString::tic() {
    int N1 = rb.dequeue();
    int N2 = rb.peek();
    rb.enqueue(DECAY * 0.5 * (N1 + N2));
    count++;
}
Int16 GuitarString::sample() {
    return rb.peek();
}
int GuitarString::time() {
    return count;
}