#include <gtest.h>
#include "TCTable.h"


TEST(TCTable, can_create)
{
	ASSERT_NO_THROW(TCTable<int> A);
}

TEST(TCTable, can_create_with_another_table)
{
	TCTable<int> A(4);
	A.AddElem("a", 12);
	bool flag = 1;
	TCTable<int> B(A);
	if (A.Find("a") != B.Find("a"))
		flag = 0;
	if (A.GetCount() != B.GetCount())
		flag = 0;
	EXPECT_EQ(flag, 1);
}

TEST(TCTable, can_add_with_same_hash)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TCTable<int> A(2);
	A.AddElem(a);
	ASSERT_NO_THROW(A.AddElem(b));
}

TEST(TCTable, can_add_with_key_and_value)
{

	TCTable<int> A(2);
	A.AddElem("bb", 3);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(TCTable, throw_add_with_over_size)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THElem<int> c("ca", 23);
	TCTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.AddElem(c));
}

TEST(TCTable, can_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TCTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(TCTable, throw_when_cannot_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TCTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.Find("zzz"));
}

TEST(TCTable, throw_when_cannot_find_elem_ather_delete)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TCTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	ASSERT_ANY_THROW(A.Find("c"));
}

TEST(TCTable, can_count)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	TCTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	EXPECT_EQ(A.GetCount(), 1);
}