#include <iostream>
#include <string.h>
using namespace std;

class LSFR 
{
public:
	LSFR(string seed, int tap) { 
		this->seed = seed;
		save_seed = seed;
		//since the tap is counted from right to left, must take total length
		//and subtract it from the input tap
		this->tap = seed.length() - tap - 1;
	}
	
	int step() {
		int n_bit,
		    last,
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

	int generate(int k) {
		int val, output = 0;
		string save = "";
		for (int i = 0; i < k; i++) {
			val = step();
			save += (val + '0');
			output = (output * 2) + val;
		}
		reset();
		return output;
	}
	
	//I included this function so that the seed can be reset back to its original number because
	//of the way I coded the functions, it changes the original seed.
	void reset() {
		seed = save_seed;
	}

	string get_seed() { return seed; }
	
	friend ostream& operator<< (ostream &out, const LSFR &obj) {
		int len = (obj.seed).length();
		out << obj.seed << " " << obj.seed[len - 1];
		return out;
	}

private:
	string seed, save_seed, out_seed;
	int tap;
};

int main() 
{
	LSFR lsfr("01101000010", 8);

	for (int i = 0; i < 10; i++) {
		lsfr.step();
		cout << lsfr << endl;
	}

	lsfr.reset();

	cout << lsfr << " " << lsfr.generate(5) << endl;
	
	return 0;
}
