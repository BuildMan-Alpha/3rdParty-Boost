
// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License,Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: single_view.cpp,v 1.1 2020/09/08 21:22:16 kurt Exp $
// $Date: 2020/09/08 21:22:16 $
// $Revision: 1.1 $

#include <boost/mpl/single_view.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
    typedef single_view<int> view;
    typedef begin<view>::type first;
    typedef end<view>::type last;

    MPL_ASSERT(( is_same< deref<first>::type, int > ));
    MPL_ASSERT(( is_same< next<first>::type, last > ));
    MPL_ASSERT(( is_same< prior<last>::type, first > ));

    MPL_ASSERT(( is_same< mpl::advance<first, int_<0> >::type, first > ));
    MPL_ASSERT(( is_same< mpl::advance<first, int_<1> >::type, last > ));
    MPL_ASSERT(( is_same< mpl::advance<last, int_<0> >::type, last > ));
    MPL_ASSERT(( is_same< mpl::advance<last, int_<-1> >::type, first > ));

    MPL_ASSERT_RELATION( (mpl::distance<first,first>::value), ==, 0 );
    MPL_ASSERT_RELATION( (mpl::distance<first,last>::value), ==, 1 );
    MPL_ASSERT_RELATION( (mpl::distance<last,last>::value), ==, 0 );

    MPL_ASSERT_RELATION( size<view>::value, ==, 1 );

    MPL_ASSERT(( equal< view, view::type > ));
}
