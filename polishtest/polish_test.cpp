#include <gtest.h>
#include "Polish.h"

TEST(Polish, can_create)
{
	ASSERT_NO_THROW(Polish A("12+2="));
}

TEST(Polish, can_convert)
{
	char A[] = { "12 2 +=" };
	bool flag = true;
	char* B = Polish("12+2=").Convert("12+2=");
	for (int i = 0; i < 8; i++)
		if (A[i] != B[i])
			flag = false;

	delete[] B;
	EXPECT_EQ(1, flag);
}

TEST(Polish, can_calculate)
{
	Polish A("12*(13+67*2)=");
	EXPECT_EQ(1764, A.Calculate());
}