#pragma once
#include <vector>
using namespace std;

class LI {
public:
	LI(long int input);
	void set_value(long int input);
	void out();
private:
	vector <int> value;
};