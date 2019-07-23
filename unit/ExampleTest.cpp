//
// Created by Roman Gaikov on 2019-07-23.
//
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ExampleText)

	BOOST_AUTO_TEST_CASE(Equal)
	{
		int a = 0;
		int b = 1;
		BOOST_REQUIRE_EQUAL(a, b);
	}

}
