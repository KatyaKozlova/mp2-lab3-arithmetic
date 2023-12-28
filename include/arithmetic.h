// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#include<string>
#include"stack.h"

using namespace std;
class TArithmetic {
	string infix;
	string postfix;
public:
	TArithmetic();
	TArithmetic()
	{
		infix = "a + b";
	}
	TArithmetic(string infx) {
		infix = infx;
	}
	string GetInfix() {
		return infix;
	}
	string GetPostfix() {
		return postfix;
	}
	string ToPostfix();
	bool isDigit(char number)const;
	bool letter(char abs)const;
	bool Operator(char op)const;
	
	int precedence(const char op) const;
	double Calculate();


};