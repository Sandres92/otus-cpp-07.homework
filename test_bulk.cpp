#define BOOST_TEST_MODULE test_version

#include <iostream>

#include "lib.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_editor)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_valid_sum)
{
    BOOST_CHECK(1 + 1 == 2);
}

BOOST_AUTO_TEST_SUITE_END()