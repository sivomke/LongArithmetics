#pragma once
#include <vector>
#include "Multiplier.h"
using namespace std;

class LI {
	friend class Multiplier;
public:
	
	LI(long int input);
	LI(int length,  int def_val);
	LI();
	void set_value(long int input);
	void out();
	LI  operator+ ( LI & b);
	//LI  operator* ( LI & b);
	LI operator = (LI & b);
	void add_zeros( int add);
	void erase_zeros();
private:
	vector <int> value;
	const int Base = 10;
};