// реализация функций и классов для вычисления арифметических выражений
#include <iostream>
#include "C:\Users\katya\source\mp2-lab3-arithmetic1\include\stack.h"
#include "C:\Users\katya\source\mp2-lab3-arithmetic1\include\arithmetic.h"


 bool TArithmetic::isDigit(const char num) const
{
	return(num >= '0' && num <= '9');
}
 bool TArithmetic::letter(const char a) const
{
	return((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'));
}

 bool TArithmetic::Operator(const char op) const
{
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

int TArithmetic::precedence(const char op) const
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else
		return 0;
}

string TArithmetic::ToPostfix()
{
	TStack<char> stk;
	postfix = "";

	for (char c:infix)
	{
		if (c == ' ') {
			continue;
		}

		if (isDigit(c) || letter(c))
		{
			postfix += c;
		}
		else if (Operator(c))
		{
			if (postfix == "" || postfix == " ") throw "Отсутствие операндов";
			while (!stk.isEmpty() && stk.Top() != '(' && precedence(c) <= precedence(stk.Top()))
			{
				postfix += stk.pop();
			}
			stk.push(c);
			postfix += " ";
		}
		else if (c == '(')
		{
			stk.push(c);
		}
		else if (c == ')')
		{
			while (!stk.isEmpty() && stk.Top() != '(')
			{
				postfix += stk.pop();
			}
			stk.pop();
		}
	}

	while (!stk.isEmpty())
	{
		postfix += " ";
		postfix += stk.pop();
	}
	return postfix;
}

double TArithmetic::Calculate()
{
	TStack<double> operands;
	bool flag = false;

	for (int i = 0; i < postfix.length(); i++) {

		if (postfix[i] == ' ') {
			continue;
		}

		if (letter(postfix[i]) && flag == false)
			throw exception("");

		if (isDigit(postfix[i])) {
			operands.push(stod(postfix.substr(i)));
			while (isDigit(postfix[i + 1])) {
				i++;
			}
		}
		if (Operator(postfix[i])) {
			double operand2 = operands.pop();
			double operand1 = operands.pop();

			switch (postfix[i]) {
			case '+':
				operands.push(operand1 + operand2);
				break;
			case '-':
				operands.push(operand1 - operand2);
				break;
			case '*':
				operands.push(operand1 * operand2);
				break;
			case '/':
				operands.push(operand1 / operand2);
				break;
			}
		}
		flag = false;
	}

	return operands.Top();
}