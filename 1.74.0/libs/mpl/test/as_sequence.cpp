
// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: as_sequence.cpp,v 1.1 2020/09/08 21:22:15 kurt Exp $
// $Date: 2020/09/08 21:22:15 $
// $Revision: 1.1 $

#include <boost/mpl/as_sequence.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    MPL_ASSERT(( is_sequence< as_sequence<int>::type > ));
    MPL_ASSERT(( is_sequence< as_sequence<UDT>::type > ));
    MPL_ASSERT(( is_sequence< as_sequence< vector<> >::type > ));
}
