#include "../../mp2-lab5-list_stack/mp2-lab5-list_stack/TListStack.h"
#include "gtest.h"

TEST(TListStack, can_create_stack)
{
	ASSERT_NO_THROW(TListStack<int> s);
}

TEST(TListStack, stack_is_empty_after_create)
{
	TListStack<int> s;
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TListStack, can_create_copied_stack)
{
  TListStack<int> m;
  ASSERT_NO_THROW(TListStack<int> m1(m));
}

TEST(TListStack, copied_stack_is_equal_to_source_one)
{
	TListStack<int> m;
	for (int i = 0; i < 9; i++)
	{
		m.Push(i);
		//mm.Push(i+1);
	}
	TListStack<int> mm(m);
	
	EXPECT_EQ(m, mm);
}

TEST(TListStack, copied_stack_has_its_own_memory)
{
	TListStack<int> m;
	TListStack<int> mm(m);
	EXPECT_NE(&m, &mm);
}

TEST(TListStack, can_assign_stack_to_itself)
{
	TListStack<int> m;
	ASSERT_NO_THROW(m = m);
}

TEST(TListStack, compare_equal_stacks_return_true)
{
	TListStack<int> m;
	TListStack<int> mm;
	for (int i = 0; i < 9; i++)
	{
		m.Push(i);
		mm.Push(i);
	}
	EXPECT_EQ(true, m == mm);
}

TEST(TListStack, compare_stack_with_itself_return_true)
{
	TListStack<int> m;

	EXPECT_EQ(true, m == m);
}

TEST(TListStack, compare_not_equal_stacks_return_false)
{
	TListStack<int> m;
	TListStack<int> mm;
	for (int i = 0; i < 9; i++)
	{
		m.Push(i);
		mm.Push(i+1);
	}
	EXPECT_EQ(false, m == mm);
}

TEST(TListStack, can_push_if_stack_isnt_full)
{
	TListStack<int> m;
	m.Push(1);

	EXPECT_EQ(m.Pop(), 1);
}

TEST(TListStack, can_pop_if_stack_isnt_empty)
{
	TListStack<int> m;
	m.Push(1);
	EXPECT_EQ(m.Pop(), 1);
}

TEST(TListStack, cant_pop_if_stack_is_empty)
{
	TListStack<int> m;
	ASSERT_ANY_THROW(m.Pop());
}

TEST(TListStack, can_assign_stacks)
{
	TListStack<int> m;
	TListStack<int> mm;
	for (int i = 0; i < 9; i++)
	{
		m.Push(i);
		mm.Push(i+1);
	}
	m = mm;
	EXPECT_EQ(m, mm);
}

TEST(TListStack, stack_is_empty_after_clear)
{
	TListStack<int> m;
	for (int i = 0; i < 9; i++)
	{
		m.Push(i);
	}
	m.Clear();
	EXPECT_EQ(m.IsEmpty(), true);
}