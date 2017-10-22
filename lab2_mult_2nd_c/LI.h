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
	LI  operator- (LI & b);
	LI  operator* ( LI & b);
	LI operator = (LI & b);
	void add_zeros( int add);
	void erase_zeros();
	LI ordinary_mul(LI& b);
	LI Karatsuba_mul(LI & b);
	void left_half(LI &from);
	void right_half(LI &from);
private:
	vector <int> value;
	const int Base = 10;
};