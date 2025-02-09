/* test_taus88.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_taus88.cpp,v 1.1 2020/09/08 20:18:46 kurt Exp $
 *
 */

#include <boost/random/taus88.hpp>

#define BOOST_RANDOM_URNG boost::random::taus88

#define BOOST_RANDOM_SEED_WORDS 3

#define BOOST_RANDOM_VALIDATION_VALUE 3535848941U
#define BOOST_RANDOM_SEED_SEQ_VALIDATION_VALUE 2562639222U
#define BOOST_RANDOM_ITERATOR_VALIDATION_VALUE 3762466828U

#define BOOST_RANDOM_GENERATE_VALUES { 0x2B55504U, 0x5403F102U, 0xED45297EU, 0x6B84007U }

#include "test_generator.ipp"
