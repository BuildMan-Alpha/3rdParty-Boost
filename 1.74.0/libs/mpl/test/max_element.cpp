
// Copyright Eric Friedman 2002-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: max_element.cpp,v 1.1 2020/09/08 21:22:16 kurt Exp $
// $Date: 2020/09/08 21:22:16 $
// $Revision: 1.1 $

#include <boost/mpl/max_element.hpp>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef list_c<int,3,4,2,0,-5,8,-1,7>::type numbers;
    typedef max_element< numbers >::type iter;
    typedef deref<iter>::type max_value;
    
    MPL_ASSERT_RELATION( max_value::value, ==, 8 );
}
