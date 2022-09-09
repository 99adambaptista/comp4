#include <iostream>
#include <string.h>
using namespace std;

class LSFR 
{
public:
  	LSFR(string seed, int tap);

  	int step();
	
  	int generate(int k);
	
  	friend ostream& operator<< (ostream &out, const LSFR &obj);

	//boosttest wont run without this, idk what it does
	~LSFR();

private:
	string seed, save_seed, out_seed;
	int tap;
};
