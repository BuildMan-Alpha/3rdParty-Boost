/* test_weibull.cpp
 *
 * Copyright Steven Watanabe 2010
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_weibull.cpp,v 1.1 2020/09/08 20:18:46 kurt Exp $
 *
 */

#include <boost/random/weibull_distribution.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/math/distributions/weibull.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost::random::weibull_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME weibull
#define BOOST_MATH_DISTRIBUTION boost::math::weibull
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME a
#define BOOST_RANDOM_ARG1_DEFAULT 1000.0
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost::uniform_real<>(0.00001, n)
#define BOOST_RANDOM_ARG2_TYPE double
#define BOOST_RANDOM_ARG2_NAME b
#define BOOST_RANDOM_ARG2_DEFAULT 1000.0
#define BOOST_RANDOM_ARG2_DISTRIBUTION(n) boost::uniform_real<>(0.00001, n)

#include "test_real_distribution.ipp"
