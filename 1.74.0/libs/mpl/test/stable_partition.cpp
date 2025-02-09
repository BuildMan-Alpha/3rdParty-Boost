
// Copyright Aleksey Gurtovoy 2004
// Copyright Eric Friedman 2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: stable_partition.cpp,v 1.1 2020/09/08 21:22:16 kurt Exp $
// $Date: 2020/09/08 21:22:16 $
// $Revision: 1.1 $

#include <boost/mpl/stable_partition.hpp>

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/aux_/test.hpp>

typedef vector_c<int,3,4,0,-5,8,-1,7>::type numbers;
typedef vector_c<int,0,-5,-1>::type manual_first;
typedef vector_c<int,3,4,8,7>::type manual_second;

MPL_TEST_CASE()
{
    typedef stable_partition<
          numbers
        , less< _, int_<3> >
        >::type result;

    MPL_ASSERT(( equal< result::first,manual_first > ));
    MPL_ASSERT(( equal< result::second,manual_second > ));
}

MPL_TEST_CASE()
{
    typedef stable_partition<
          numbers
        , greater_equal< _, int_<3> >
        >::type result;

    MPL_ASSERT(( equal< result::first,manual_second > ));
    MPL_ASSERT(( equal< result::second,manual_first > ));
}
