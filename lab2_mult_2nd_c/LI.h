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
	LI(vector<int> input);
	void set_value(long int input);
	void out();
	LI  operator+ ( LI & b);
	LI  operator- (LI & b);
	LI  operator* ( LI & b);
	LI operator = (LI & b);
	LI operator / (LI & b) ;
	bool operator == (LI & b);
	void add_zeros( int add);
	void erase_zeros();
	LI ordinary_mul(LI& b);
	LI Karatsuba_mul(LI & b);
	void left_half(LI &from);
	void right_half(LI &from);
	bool Rabin_Miller();
	bool less(LI &b);
	LI  substraction(LI &b);
	vector <int> value;
	int LI_to_int(); //auxillary for Rabin Miller but can be used independently


private:
	static const int Base = 10;
	int sufficient_loop_num(); //auxillary for Rabin Miller
	int find_power_of_2(int&odd_component);//auxillary for Rabin Miller
	static void expand_cur(LI & cur, LI & a, LI & b, int & count_expand); //auxiliary for division
	static int find_multiplier(LI & cur,  LI & b); //auxiliary for division


};