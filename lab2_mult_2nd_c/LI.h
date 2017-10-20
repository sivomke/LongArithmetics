#pragma once
#include <vector>
#include "Multiplier.h"
using namespace std;

class LI {
	friend class Multiplier;
public:
	
	LI(long int input);
	LI() = default;
	void set_value(long int input);
	void out();
	const LI operator+ (const LI & b);
	const LI operator* (const LI & b);
	void add_zeros( int add);
private:
	vector <int> value;
	const int Base = 10;
};