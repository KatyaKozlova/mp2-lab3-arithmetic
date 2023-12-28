// реализация пользовательского приложения
#include <iostream>
#include <string>
#include "arithmetic.h"

using namespace std;

int main()
{
	string expression;
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "Введите арифметическое выражение: ";
	getline(cin, expression);
	TArithmetic postfix(expression) ;
	//cout << expression << endl;
	cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
	postfix.ToPostfix();
	cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
	try {
		res = postfix.Calculate();
		cout << "Результат: " << res << endl;
	}
	catch (exception) {
		cout << "Ошибка, не найдено значение соответствующей буквы";
	}
	return 0;
}