#include <iostream>
#include <string>
#include "LSFR.hpp"
using namespace std;

LSFR::LSFR(string seed, int tap) {
	this->seed = seed;
	save_seed = seed;
	//since the tap is counted from right to left, must take total length
	//and subtract it from the input tap
	this->tap = seed.length() - tap - 1;
}
	
int LSFR:: step() {
	int n_bit,
	    //-'0' because seed[0] gives the char '1' or '0', and in order to get the
	    //int value of 1 or 0, must subtract ascii value 48 or '0'
	    first = seed[0] - '0',
	    _tap = seed[tap] - '0';
		n_bit = first ^ _tap;
	seed.erase(seed.begin());
	//+'0' because now we want to convert the int 1 or 0, to char '1'/'0', so adding
	//'0' or 48 will give the ascii value of '1' or '0'
	seed += (n_bit + '0');
	return n_bit;
}

int LSFR::generate(int k) {
	int val, output = 0;
	string save = "";
	for (int i = 0; i < k; i++) {
		val = step();
		//save += (val + '0');
		output = (output * 2) + val;
	}
	return output;
}

ostream& operator<< (ostream &out, const LSFR &obj) {
	//int len = (obj.seed).length();
	//out << obj.seed << " " << obj.seed[len - 1];
	for (unsigned int i = 0; i < obj.seed.size(); i++) {
		out << obj.seed[i];
	}
	
	return out;
}

LSFR::~LSFR() {}
/*
int main() 
{
	
	LSFR lsfr("01101000010", 8);
	LSFR a("0", 0);

	for (int i = 0; i < 10; i++) {
		//lsfr.step();
		cout << lsfr << " " << lsfr.generate(5) << endl;
	}

	//cout << lsfr << " " << lsfr.generate(5) << endl;

	//cout << a << " " << a.generate(5) << endl;
	
	return 0;
}*/
