
// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: inherit_multiply.cpp,v 1.1 2020/09/08 21:22:10 kurt Exp $
// $Date: 2020/09/08 21:22:10 $
// $Revision: 1.1 $

#include <boost/mpl/inherit.hpp>
#include <boost/mpl/inherit_linearly.hpp>
#include <boost/mpl/list.hpp>

#include <iostream>

namespace mpl = boost::mpl;
using namespace mpl::placeholders;

template< typename T >
struct tuple_field
{
    typedef tuple_field type; // note the typedef
    T field_;
};

template< typename T >
inline
T& field(tuple_field<T>& t)
{
    return t.field_;
}

typedef mpl::inherit_linearly<
      mpl::list<int,char const*,bool>
    , mpl::inherit< _1, tuple_field<_2> >
    >::type my_tuple;
    

int main()
{
    my_tuple t;
    
    field<int>(t) = -1;
    field<char const*>(t) = "text";
    field<bool>(t) = false;

    std::cout
        << field<int>(t) << '\n'
        << field<char const*>(t) << '\n'
        << field<bool>(t) << '\n'
        ;

    return 0;
}
