// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id: fail_ref_discard_const_init.cpp,v 1.1 2020/09/08 19:32:30 kurt Exp $

#include <boost/type_erasure/any.hpp>
#include <boost/type_erasure/builtin.hpp>
#include <boost/mpl/vector.hpp>

using namespace boost::type_erasure;

int main()
{
    const int i = 1;
    any<copy_constructible<>, _self&> y(i);
}
