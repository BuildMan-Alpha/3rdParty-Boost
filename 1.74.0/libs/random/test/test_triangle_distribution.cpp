/* test_triangle_distribution.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_triangle_distribution.cpp,v 1.1 2020/09/08 20:18:46 kurt Exp $
 *
 */

#include <boost/random/triangle_distribution.hpp>
#include <limits>

#define BOOST_RANDOM_DISTRIBUTION boost::random::triangle_distribution<>
#define BOOST_RANDOM_ARG1 a
#define BOOST_RANDOM_ARG2 b
#define BOOST_RANDOM_ARG3 c
#define BOOST_RANDOM_ARG1_DEFAULT 0.0
#define BOOST_RANDOM_ARG2_DEFAULT 0.5
#define BOOST_RANDOM_ARG3_DEFAULT 1.0
#define BOOST_RANDOM_ARG1_VALUE -0.5
#define BOOST_RANDOM_ARG2_VALUE 0.25
#define BOOST_RANDOM_ARG3_VALUE 1.5

#define BOOST_RANDOM_DIST0_MIN 0.0
#define BOOST_RANDOM_DIST0_MAX 1.0
#define BOOST_RANDOM_DIST1_MIN -0.5
#define BOOST_RANDOM_DIST1_MAX 1.0
#define BOOST_RANDOM_DIST2_MIN -0.5
#define BOOST_RANDOM_DIST2_MAX 1.0
#define BOOST_RANDOM_DIST3_MIN -0.5
#define BOOST_RANDOM_DIST3_MAX 1.5

#define BOOST_RANDOM_TEST1_PARAMS (-1, -0.5, 0)
#define BOOST_RANDOM_TEST1_MAX 0

#define BOOST_RANDOM_TEST2_PARAMS (0, 0.5, 1)
#define BOOST_RANDOM_TEST2_MIN 0

#include "test_distribution.ipp"
