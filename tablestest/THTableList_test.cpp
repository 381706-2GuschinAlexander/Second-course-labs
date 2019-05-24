#include <gtest.h>
#include "THTableList.h"

TEST(THTableList, can_create)
{
	ASSERT_NO_THROW(THTableList<int> A);
}

TEST(THTableList, can_create_with_another_table)
{
	THTableList<int> A(4);
	A.AddElem("a", 12);
	bool flag = 1;
	THTableList<int> B(A);
	if (A.Find("a") != B.Find("a"))
		flag = 0;
	if (A.GetCount() != B.GetCount())
		flag = 0;
	EXPECT_EQ(flag, 1);
}

TEST(THTableList, can_add_with_same_hash)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTableList<int> A(2);
	A.AddElem(a);
	ASSERT_NO_THROW(A.AddElem(b));
}

TEST(THTableList, can_add_with_key_and_value)
{

	THTableList<int> A(2);
	A.AddElem("bb", 3);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(THTableList, can_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTableList<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(THTableList, throw_when_cannot_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTableList<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.Find("zzz"));
}

TEST(THTableList, throw_when_cannot_find_elem_ather_delete)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTableList<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	ASSERT_ANY_THROW(A.Find("c"));
}

TEST(THTableList, can_count)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTableList<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	EXPECT_EQ(A.GetCount(), 1);
}

