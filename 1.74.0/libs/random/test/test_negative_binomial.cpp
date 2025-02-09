/* test_negative_binomial.cpp
 *
 * Copyright Steven Watanabe 2010
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_negative_binomial.cpp,v 1.1 2020/09/08 20:18:43 kurt Exp $
 *
 */

#include <boost/random/negative_binomial_distribution.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_01.hpp>
#include <boost/math/distributions/negative_binomial.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost::random::negative_binomial_distribution<>
#define BOOST_RANDOM_DISTRIBUTION_NAME negative_binomial
#define BOOST_MATH_DISTRIBUTION boost::math::negative_binomial
#define BOOST_RANDOM_ARG1_TYPE int
#define BOOST_RANDOM_ARG1_NAME n
#define BOOST_RANDOM_ARG1_DEFAULT 100000
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost::uniform_int<>(0, n)
#define BOOST_RANDOM_ARG2_TYPE double
#define BOOST_RANDOM_ARG2_NAME p
#define BOOST_RANDOM_ARG2_DEFAULT 1000.0
#define BOOST_RANDOM_ARG2_DISTRIBUTION(n) boost::uniform_01<>()
#define BOOST_RANDOM_DISTRIBUTION_MAX n

#include "test_real_distribution.ipp"
