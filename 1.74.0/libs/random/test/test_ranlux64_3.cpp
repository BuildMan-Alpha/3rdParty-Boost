/* test_ranlux64_3.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_ranlux64_3.cpp,v 1.1 2020/09/08 20:18:45 kurt Exp $
 *
 */

#include <boost/random/ranlux.hpp>
#include <boost/cstdint.hpp>
#include <cmath>

#define BOOST_RANDOM_URNG boost::random::ranlux64_3

#define BOOST_RANDOM_SEED_WORDS 48

// principal operation validated with CLHEP, values by experiment
#define BOOST_RANDOM_VALIDATION_VALUE UINT64_C(141789170949364)
#define BOOST_RANDOM_SEED_SEQ_VALIDATION_VALUE UINT64_C(85538657982635)
#define BOOST_RANDOM_ITERATOR_VALIDATION_VALUE UINT64_C(101724473226966)

#define BOOST_RANDOM_GENERATE_VALUES { 0xC35F616BU, 0xDC3C4DF1U, 0xF3F90D0AU, 0x206F9C9EU }

#include "test_generator.ipp"
