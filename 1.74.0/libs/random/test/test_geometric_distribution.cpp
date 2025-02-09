/* test_geometric_distribution.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_geometric_distribution.cpp,v 1.1 2020/09/08 20:18:43 kurt Exp $
 *
 */

#include <boost/random/geometric_distribution.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost::random::geometric_distribution<>
#define BOOST_RANDOM_ARG1 p
#define BOOST_RANDOM_ARG1_DEFAULT 0.5
#define BOOST_RANDOM_ARG1_VALUE 0.25

#define BOOST_RANDOM_DIST0_MIN 0
#define BOOST_RANDOM_DIST0_MAX (std::numeric_limits<int>::max)()
#define BOOST_RANDOM_DIST1_MIN 0
#define BOOST_RANDOM_DIST1_MAX (std::numeric_limits<int>::max)()

#define BOOST_RANDOM_TEST1_PARAMS (0.9999)
#define BOOST_RANDOM_TEST1_MIN 0
#define BOOST_RANDOM_TEST1_MAX 0

#define BOOST_RANDOM_TEST2_PARAMS (0.0001)
#define BOOST_RANDOM_TEST2_MIN 1

#include "test_distribution.ipp"
