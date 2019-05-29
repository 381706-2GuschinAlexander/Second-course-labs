#include <gtest.h>
#include "Plex.h"

TEST(Plex, can_create)
{
	ASSERT_NO_THROW(Plex a);
}

TEST(Plex, can_add_and_delete)
{
	Line a(12, 22, 50, 54);
	Plex A;
	A += a;
	Line b(12, 22, 41, 44);
	A += b;
	EXPECT_EQ(A.DeleteLine(Line(12, 22, 41, 44)), 1);
}

TEST(Plex, throw_when_invalid_line)
{
	Line a(12, 22, 50, 54);
	Plex A;
	A += a;
	Line b(1222, 212, 41, 44);
	ASSERT_ANY_THROW(A += b);
	
}
