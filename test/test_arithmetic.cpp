// тесты для вычисления арифметических выражений

#include "arithmetic.h"
#include "stack.h"
#include <gtest.h>


TEST(TArithmetic, can_create_postfix_obj)
{
	ASSERT_NO_THROW(TArithmetic p);
}

TEST(TArithmetic, can_get_infix) {
	TArithmetic p;
	ASSERT_NO_THROW(p.GetInfix());
}

TEST(TArithmetic, can_create_postfix_form) {
	TArithmetic p;
	ASSERT_NO_THROW(p.ToPostfix());
}

TEST(TArithmetic, can_get_postfix) {
	TArithmetic p;
	p.ToPostfix();
	ASSERT_NO_THROW(p.GetPostfix());
}

TEST(TArithmetic, can_calculate_expression_with_abc) {
	TArithmetic p("a+b+c");
	p.ToPostfix();
	ASSERT_NO_THROW(p.Calculate());
	
}

TEST(TArithmetic, can_calculate_standard_expression) {
	TArithmetic p("1+2+3+4*5-(6*7)/8");
	p.ToPostfix();
	ASSERT_NO_THROW(p.Calculate());
}

TEST(TArithmetic, can_create_postfix_if_expression_is_written_with_or_without_spaces) {
	TArithmetic p("1+ 2+3 + 4*5 -( 6* 7 )/ 8");
	ASSERT_NO_THROW(p.ToPostfix());
}

TEST(TArithmetic, throw_when_expression_without_operands) {
	TArithmetic p("+");
	ASSERT_ANY_THROW(p.ToPostfix());
}

TEST(TArithmetic, can_calculate_expression_with_letters_from_table_and_numbers) {
	TArithmetic p("(a - 5) + b * 3");
	ASSERT_NO_THROW(p.Calculate());
}