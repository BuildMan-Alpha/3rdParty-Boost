/* test_lagged_fibonacci44497.cpp
 *
 * Copyright Steven Watanabe 2011
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: test_lagged_fibonacci44497.cpp,v 1.1 2020/09/08 20:18:43 kurt Exp $
 *
 */

#include <boost/random/lagged_fibonacci.hpp>

#define BOOST_RANDOM_URNG boost::random::lagged_fibonacci44497

#define BOOST_RANDOM_SEED_WORDS 44497*2

#define BOOST_RANDOM_VALIDATION_VALUE 0.12519369894159738
#define BOOST_RANDOM_SEED_SEQ_VALIDATION_VALUE 0.92285669730527431
#define BOOST_RANDOM_ITERATOR_VALIDATION_VALUE 0.0019836425785868528

#define BOOST_RANDOM_GENERATE_VALUES { 0x6A2DCEA9U, 0x4668EFB4U, 0x711E352FU, 0xA963C43BU }

#include "test_generator.ipp"
