/* test_cauchy_distribution.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_cauchy_distribution.cpp,v 1.1 2020/09/08 20:18:43 kurt Exp $
 *
 */

#include <boost/random/cauchy_distribution.hpp>
#include <limits>

#define BOOST_RANDOM_DISTRIBUTION boost::random::cauchy_distribution<>
#define BOOST_RANDOM_ARG1 a
#define BOOST_RANDOM_ARG2 b
#define BOOST_RANDOM_ARG1_DEFAULT 0.0
#define BOOST_RANDOM_ARG2_DEFAULT 1.0
#define BOOST_RANDOM_ARG1_VALUE 7.5
#define BOOST_RANDOM_ARG2_VALUE 0.25

#define BOOST_RANDOM_DIST0_MIN -(std::numeric_limits<double>::infinity)()
#define BOOST_RANDOM_DIST0_MAX (std::numeric_limits<double>::infinity)()
#define BOOST_RANDOM_DIST1_MIN -(std::numeric_limits<double>::infinity)()
#define BOOST_RANDOM_DIST1_MAX (std::numeric_limits<double>::infinity)()
#define BOOST_RANDOM_DIST2_MIN -(std::numeric_limits<double>::infinity)()
#define BOOST_RANDOM_DIST2_MAX (std::numeric_limits<double>::infinity)()

#define BOOST_RANDOM_TEST1_PARAMS (-100000.0, 0.000001)
#define BOOST_RANDOM_TEST2_PARAMS (100000.0, 0.000001)
#define BOOST_RANDOM_TEST1_MAX 0.0
#define BOOST_RANDOM_TEST2_MIN 0.0

#include "test_distribution.ipp"
