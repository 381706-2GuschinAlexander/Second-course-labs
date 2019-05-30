#include <gtest.h>
#include "TBTable.h"

TEST(TBTableList, can_create)
{
	ASSERT_NO_THROW(TBTable<int> A);
}

TEST(TBTableList, can_create_with_another_table)
{
	TBTable<int> A;
	A.AddElem(TBElem<int>("a", 12));
	bool flag = 1;
	TBTable<int> B(A);
	if (A.Find("a") != B.Find("a"))
		flag = 0;
	if (A.GetCount() != B.GetCount())
		flag = 0;
	EXPECT_EQ(flag, 1);
}

TEST(TBTableList, can_add_with_key_and_value)
{

	TBTable<int> A;
	A.AddElem(TBElem<int>("bb", 3));
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(TBTableList, can_find_elem)
{
	TBElem<int> a("bb", 3);
	TBElem<int> b("c", 3);
	TBTable<int> A;
	A.AddElem(a);
	A.AddElem(b);
	EXPECT_EQ(A.Find("bb") == 3, 1);
}

TEST(TBTableList, throw_when_cannot_find_elem)
{
	TBElem<int> a("bb", 3);
	TBElem<int> b("c", 3);
	TBTable<int> A;
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.Find("zzz"));
}

TEST(TBTableList, throw_when_cannot_find_elem_ather_delete)
{
	TBElem<int> a("bb", 3);
	TBElem<int> b("c", 3);
	TBElem<int> ab("a", 3);
	TBElem<int> ba("d", 3);
	TBElem<int> abc("f", 3);
	TBTable<int> A;
	A.AddElem(a);
	A.AddElem(b);
	A.AddElem(ab);
	A.AddElem(ba);
	A.AddElem(abc);
	A.DeleteElem("c");
	ASSERT_ANY_THROW(A.Find("c"));
}

TEST(TBTableList, can_delete_node)
{
	TBElem<int> a("bb", 3);
	TBElem<int> b("c", 3);
	TBTable<int> A;
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("bb");
	ASSERT_NO_THROW(A.Find("c"));
}

TEST(TBTableList, can_count)
{
	TBElem<int> a("bb", 3);
	TBElem<int> b("c", 3);
	TBTable<int> A;
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	EXPECT_EQ(A.GetCount(), 1);
}
