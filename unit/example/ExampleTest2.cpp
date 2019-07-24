//
// Created by Roman Gaikov on 2019-07-23.
//
#include "../UnitCommon.h"

BOOST_AUTO_TEST_SUITE(ExampleText2)

	BOOST_AUTO_TEST_CASE(EqualTrue2)
	{
		int a = 0;
		int b = 0;
		BOOST_REQUIRE_EQUAL(a, b);
	}

BOOST_AUTO_TEST_SUITE_END()
