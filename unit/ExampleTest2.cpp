//
// Created by Roman Gaikov on 2019-07-23.
//
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ExampleText2)

	BOOST_AUTO_TEST_CASE(EqualTrue2)
	{
		int a = 0;
		int b = 0;
		BOOST_REQUIRE_EQUAL(a, b);
	}
}