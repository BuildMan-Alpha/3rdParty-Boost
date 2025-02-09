/* test_lognormal.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_lognormal.cpp,v 1.1 2020/09/08 20:18:43 kurt Exp $
 *
 */

#include <boost/random/lognormal_distribution.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/math/distributions/lognormal.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost::random::lognormal_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME lognormal
#define BOOST_MATH_DISTRIBUTION boost::math::lognormal
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME m
#define BOOST_RANDOM_ARG1_DEFAULT 10.0
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost::uniform_real<>(-n, n)
#define BOOST_RANDOM_ARG2_TYPE double
#define BOOST_RANDOM_ARG2_NAME s
#define BOOST_RANDOM_ARG2_DEFAULT 10.0
#define BOOST_RANDOM_ARG2_DISTRIBUTION(n) boost::uniform_real<>(0.0001, n)

#include "test_real_distribution.ipp"
