#define BOOST_TEST_MODULE test_version

#include "lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(version() > 0);
    if (boost::unit_test::framework::master_test_suite().argc > 1)
    {
        BOOST_CHECK(version() == atoi(boost::unit_test::framework::master_test_suite().argv[1]));
    }
}

}
