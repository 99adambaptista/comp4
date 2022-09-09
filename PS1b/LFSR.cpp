//#include <iostream>
//#include <string>
#include "LFSR.hpp"
using namespace std;

LFSR::LFSR(string seed, int tap) {
	for (unsigned int i = 0; i < seed.length(); i++)
		this->seed.push_back(seed[i]);
	//save_seed = seed;
	//since the tap is counted from right to left, must take total length
	//and subtract it from the input tap
	this->tap = seed.length() - tap - 1;
}
	
int LFSR::step() {
	int first = seed.at(0),
	    _tap = seed.at(tap),
		n_bit = first ^ _tap;
	seed.erase(seed.begin());
	seed.push_back(n_bit);
	return n_bit;
}

int LFSR::generate(int k) {
	int val, output = 0;
	for (int i = 0; i < k; i++) {
		val = step();
		output = (output * 2) + val;
	}
	return output;
}

ostream& operator<< (ostream &out, const LFSR &obj) {
	for (unsigned int i = 0; i < obj.seed.size(); i++) {
		out << obj.seed[i];
	}
	
	return out;
}

//LFSR::~LFSR() {}
