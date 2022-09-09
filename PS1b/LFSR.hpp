#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class LFSR 
{
public:
  	LFSR(string seed, int tap);

  	int step();
	
  	int generate(int k);
	
  	friend ostream& operator<< (ostream &out, const LFSR &obj);

	//~LFSR();

private:
	vector<int> seed;
	int tap;
};
