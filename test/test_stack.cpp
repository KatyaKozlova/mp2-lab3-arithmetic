// тесты для стека

#include "stack.h"
#include <gtest.h>
TEST(TStack, can_create_matrix_with_positive_length) {
	ASSERT_NO_THROW(TStack<int> st(10));
}
TEST(TStack, can_create_matrix_with_negativ_length) {
	ASSERT_ANY_THROW(TStack<int> st(-10));

}
TEST(TStack, can_push_elem_to_stack) {
	TStack<int> st(10);
	ASSERT_NO_THROW(st.push(1));
}
TEST(TStack, can_pop_elem_to_stack) {
	TStack<int> st(10);
	st.push(1);
	EXPECT_EQ(1, st.pop());
}
TEST(TStack, can_top_elem_to_stack) {
	TStack<int> st(10);
	st.push(3);
	EXPECT_EQ(3, st.Top());
}
TEST(TStack, can_check_the_state_of_the_stack_isEmpty) {
	TStack<int> st(5);
	EXPECT_EQ(true, st.isEmpty());
}
TEST(TStack, can_get_size) {
	TStack<int> st(5);
	int i;
	for ( i = 0; i < 3; i++) {
		st.push(2);
	}
	EXPECT_EQ(i, st.ssize());
}
