/* boost test_random_number_generator.cpp
 *
 * Copyright Jens Maurer 2000
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_random_number_generator.cpp,v 1.1 2020/09/08 20:18:44 kurt Exp $
 */

#include <boost/random/random_number_generator.hpp>
#include <boost/random/mersenne_twister.hpp>

#include <algorithm>
#include <vector>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_random_shuffle)
{
#ifndef BOOST_NO_CXX98_RANDOM_SHUFFLE
    boost::mt19937 engine(1234);
    boost::random::random_number_generator<boost::mt19937> generator(engine);

    std::vector<int> testVec;

    for (int i = 0; i < 200; ++i) {
        testVec.push_back(i);
    }

    std::random_shuffle(testVec.begin(), testVec.end(), generator);
#endif
}
