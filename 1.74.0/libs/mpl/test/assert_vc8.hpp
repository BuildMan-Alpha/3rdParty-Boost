
// Copyright Robin Linden 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: assert_vc8.hpp,v 1.1 2020/09/08 21:22:15 kurt Exp $
// $Date: 2020/09/08 21:22:15 $
// $Revision: 1.1 $

// Part of a test to demonstrate a linking error with
// BOOST_MPL_ASSERT_MSG inside of functions under VC++8.

#include <boost/mpl/assert.hpp>

template<class T>
bool func()
{
    BOOST_MPL_ASSERT_MSG(
        true,
        ALWAYS_TRUE,
        (T));

    return true;
}
