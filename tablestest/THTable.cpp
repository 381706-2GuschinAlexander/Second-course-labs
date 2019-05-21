#include <gtest.h>
#include "THTable.h"

TEST(THTable, can_create)
{
	ASSERT_NO_THROW(THTable<int> A);
}

TEST(THTable, can_add_with_same_hash)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTable<int> A(2);
	A.AddElem(a);
	ASSERT_NO_THROW(A.AddElem(b));
}

TEST(THTable, throw_add_with_over_size)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THElem<int> c("ca", 23);
	THTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.AddElem(c));
}

TEST(THTable, can_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	EXPECT_EQ(A.Find("bb") == a , 1);
}

TEST(THTable, throw_when_cannot_find_elem)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	ASSERT_ANY_THROW(A.Find("zzz"));
}

TEST(THTable, throw_when_cannot_find_elem_ather_delete)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	ASSERT_ANY_THROW(A.Find("c"));
}

TEST(THTable, can_count)
{
	THElem<int> a("bb", 3);
	THElem<int> b("c", 3);
	THTable<int> A(2);
	A.AddElem(a);
	A.AddElem(b);
	A.DeleteElem("c");
	EXPECT_EQ(A.GetCount(),1);
}

