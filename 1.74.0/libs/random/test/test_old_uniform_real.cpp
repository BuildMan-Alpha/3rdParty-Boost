/* test_old_uniform_real.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_old_uniform_real.cpp,v 1.1 2020/09/08 20:18:44 kurt Exp $
 *
 */

#include <boost/random/uniform_real.hpp>
#include <boost/math/distributions/uniform.hpp>

#define BOOST_RANDOM_DISTRIBUTION boost::uniform_real<>
#define BOOST_RANDOM_DISTRIBUTION_NAME uniform_real
#define BOOST_MATH_DISTRIBUTION boost::math::uniform
#define BOOST_RANDOM_ARG1_TYPE double
#define BOOST_RANDOM_ARG1_NAME b
#define BOOST_RANDOM_ARG1_DEFAULT 1000
#define BOOST_RANDOM_ARG1_DISTRIBUTION(n) boost::uniform_real<>(0, n)
#define BOOST_RANDOM_DISTRIBUTION_INIT (0, b)
#define BOOST_MATH_DISTRIBUTION_INIT (0, b)

#include "test_real_distribution.ipp"
