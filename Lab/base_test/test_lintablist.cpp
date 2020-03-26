#include <gtest.h>
#include "LinTabList.h"
#include "LTL_Metd.cpp"

TEST(LinTabList, can_create_linear_table)
{
	ASSERT_NO_THROW(LinTabList testTab);
}
