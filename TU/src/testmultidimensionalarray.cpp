#include "basetest.h"

#include "misbmultidimensionalarray.h"

TEST_F(TestMultiDimensionalArray, ConstructorTest)
{
	std::vector<uint32_t> l_dimensions;
	l_dimensions.push_back(1);
	MDArray l_mdarray(l_dimensions);

	l_mdarray.SetValue(15.041981, 0);

	EXPECT_NEAR(15.041981, l_mdarray.GetValue(0), 1e-5);
}

TEST_F(TestMultiDimensionalArray, Sophie4CaseTest)
{
	std::vector<uint32_t> l_dimensions;
	l_dimensions.push_back(1);
	l_dimensions.push_back(1);
	l_dimensions.push_back(2);
	MDArray l_mdarray(l_dimensions);

	l_mdarray.SetValue(17.121986, 0, 0, 0);
	l_mdarray.SetValue(14.021995, 0, 0, 1);

	EXPECT_NEAR(17.121986, l_mdarray.GetValue(0, 0, 0), 1e-5);
	EXPECT_NEAR(14.021994, l_mdarray.GetValue(0, 0, 1), 1e-5);
}

