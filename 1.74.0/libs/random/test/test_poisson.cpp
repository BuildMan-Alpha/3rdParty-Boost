/* test_poisson.cpp
 *
 * Copyright Steven Watanabe 2010
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_poisson.cpp,v 1.1 2020/09/08 20:18:44 kurt Exp $
 *
 */

#include <boost/random/poisson_distribution.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/math/distributions/poisson.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost::random::poisson_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME poisson
#define BOOST_MATH_DISTRIBUTION boost::math::poisson
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME mean
#define BOOST_RANDOM_ARG1_DEFAULT 100000.0
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost::uniform_real<>(1e-15, n)
#define BOOST_RANDOM_DISTRIBUTION_MAX static_cast<int>(mean * 4)

#include "test_real_distribution.ipp"
