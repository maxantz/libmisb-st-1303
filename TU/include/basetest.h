#ifndef __BASETEST_H__
#define __BASETEST_H__

#include <gtest/gtest.h>

class BaseTest : public testing::Test
{
public:
	BaseTest() { };
	~BaseTest() override { };
	void SetUp() override { };
	void TearDown() override { };
};

class TestMultiDimensionalArray : public BaseTest {};

#endif

