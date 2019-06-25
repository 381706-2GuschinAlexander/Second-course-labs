#include <gtest.h>
#include "TSTable.h"


TEST(TSTable, can_create)
{
	ASSERT_NO_THROW(TSTable<int> A);
}

TEST(TSTable, can_create_with_another_table)
{
	TSTable<int> A(4);
	A.AddElem("a", 12);
	bool flag = 1;
	TSTable<int> B(A);
	if (A.Find("a") != B.Find("a"))
		flag = 0;
	if (A.GetCount() != B.GetCount())
		flag = 0;
	EXPECT_EQ(flag, 1);
}

TEST(TSTable, can_create_with_another_unsorted_table)
{
	TCTable<int> A(4);
	A.AddElem("a", 12);
	bool flag = 1;
	TSTable<int> B(A);
	if (A.Find("a") != B.Find("a"))
		flag = 0;
	if (A.GetCount() != B.GetCount())
		flag = 0;
	EXPECT_EQ(flag, 1);
}

TEST(TSTable, can_add)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TSTable<int> A(2);
	A.AddElem(a);
	ASSERT_NO_THROW(A.AddElem(b));
}

TEST(TSTable, can_add_with_key_and_value)
{

	TSTable<int> A(2);
	A.AddElem("bb", 3);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(TSTable, throw_add_with_over_size)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THElem<int> c("ca", 23);
	TSTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.AddElem(c));
}

TEST(TSTable, can_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TSTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}


TEST(TSTable, can_count)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TSTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	EXPECT_EQ(A.GetCount(), 1);
}

TEST(TSTable, is_sorted)
{
	TSTable<int> A(5);
	A.AddElem("aaa",10);
	A.AddElem("as", 10);
	A.AddElem("d", 10);
	A.AddElem("sa", 10);
	A.AddElem("saa", 10);
	EXPECT_EQ(A.GetCount(), 5);
}