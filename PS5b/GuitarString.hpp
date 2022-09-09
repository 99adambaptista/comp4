#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <cstdlib>
#include <cmath>

#include "RingBuffer.hpp"

using namespace std;
using namespace sf;

class GuitarString {
public:
    GuitarString(double frequency);
    GuitarString(vector<Int16> init);

    void pluck();

    void tic();
    Int16 sample();
    int time();

private:
    RingBuffer rb;
    int count;

};