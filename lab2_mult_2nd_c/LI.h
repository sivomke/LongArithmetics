#pragma once
#include <vector>
#include "Multiplier.h"
#include <iostream>
using namespace std;

class LI {
	friend class Multiplier;
public:
	static void check(LI a, LI b) {
		std::cout <<boolalpha<< (a.value[a.value.size() - 1] == b.value[b.value.size() - 1] )<< endl;
	} 
	LI(string number);
	LI(LI&b);
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
	bool Rabin_Miller(LI & is_prime);
	bool less(LI &b);

	vector <int> value;
private:

	LI  substraction(LI &b);
	static const int Base = 10;

};