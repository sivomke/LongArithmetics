#include "stdafx.h"
#include "LI.h"
#include <algorithm>
#include <iostream>
using namespace std;

LI::LI(long int input) {
	set_value(input);
	//reverse(value.begin(), value.end());
}

LI::LI(int length, int def_val): value(length, 0)
{
}


//LI::LI(int length):value(length, 0)
//{
//}

LI::LI():value(0,0)
{
}

void LI:: set_value(long int input) {
	value.push_back(input % this->Base);
	int temp = input / this->Base;
	if (temp == 0) return;
	set_value(temp);
}

void LI::out() {
	reverse(value.begin(), value.end());
	for (auto elem : value)
		cout << elem;
	cout << endl;
	reverse(value.begin(), value.end());
} 

LI  LI::operator+( LI & b)
{

	int n = max(this->value.size(), b.value.size());
	this->add_zeros(n - this->value.size());
	b.add_zeros(n - b.value.size());
	LI sum(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		sum.value[i] += (value[i] + b.value[i]) % Base;
		sum.value[i + 1] = (value[i] + b.value[i]) / Base;

	}
	this->erase_zeros();
	b.erase_zeros();
	sum.erase_zeros();
	return sum;
}

LI LI::operator-(LI & b) //works only if a>b!
{
	int n = max(this->value.size(), b.value.size());
	this->add_zeros(n - this->value.size());
	b.add_zeros(n - b.value.size());
	LI sub(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (value[i]>=b.value[i])
			sub.value[i] = (value[i] - b.value[i]) % Base;
		else {
			value[i + 1] -= 1%Base; //WHAT TO DO IF THE BASE != 10
			sub.value[i] = (Base + value[i] - b.value[i])%Base;

		}
	

	}
	this->erase_zeros();
	b.erase_zeros();
	sub.erase_zeros();
	return sub;
}


LI LI::operator=(LI & b)
{
	this->value = b.value;
	return LI();
}



LI  LI::operator*(LI & b)
{

	int l_a = value.size();

	int l_b = b.value.size();

	LI mul(l_a + l_b, 0);

	this->value.push_back(0);

	int remember = 0;

	for (int j = 0; j < l_b; ++j) {

		for (int i = 0; i<l_a + 1; ++i) {



			mul.value[i + j] += (remember + value[i] * b.value[j]);



			remember = mul.value[i + j] / Base;

			mul.value[i + j] %= Base;



		}

	}

	mul.erase_zeros();

	return mul;
}
 
void LI::add_zeros(int add)
{
	while (add--)
		value.push_back(0);
}

void LI::erase_zeros()
{
	while (this->value.back() ==0)
		this->value.pop_back();
}

LI LI::ordinary_mul(LI & b)
{

	int l_a = value.size();

	int l_b = b.value.size();

	LI mul(l_a + l_b, 0);

	this->value.push_back(0);

	int remember = 0;

	for (int j = 0; j < l_b; ++j) {

		for (int i = 0; i<l_a + 1; ++i) {


			mul.value[i + j] += (remember + value[i] * b.value[j]);


			remember = mul.value[i + j] / Base;

			mul.value[i + j] %= Base;

		}

	}

	mul.erase_zeros();

	return mul;
}

LI LI::Karatsuba_mul(LI & b)
{
	int n = max(this->value.size(), b.value.size());
	if (n == 1) return this->ordinary_mul(b);
	if (n % 2)n += 1; //is odd, makes it even
	this->add_zeros(n - this->value.size());
	b.add_zeros(n - b.value.size());
	LI a_left;
	LI a_right;
	LI b_left;
	LI b_right;
	LI  Prod_1 = a_left.Karatsuba_mul(b_left);
	LI Prod_2 = a_right.Karatsuba_mul(b_right);
	LI sum_1 = a_left + a_right;
	LI sum_2 = b_left + b_right;
	LI Prod_3 = sum_1.Karatsuba_mul(sum_2);
	LI ten_in_n = pow(10, n); //10^n
	LI ten_in_n_over_2 = pow(10, n / 2); //10^(n/2)
	LI res = Prod_1.ordinary_mul(ten_in_n) + ten_in_n_over_2;

	
}
