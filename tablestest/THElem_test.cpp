#include <gtest.h>
#include "THElem.h"

TEST(THElem, can_create)
{
	ASSERT_NO_THROW(THElem<int> A);
}

