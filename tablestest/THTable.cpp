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
	THTable<int> A(2);
	A.AddElem(a);
	A.AddElem(a);
	ASSERT_ANY_THROW(A.AddElem(b));
}