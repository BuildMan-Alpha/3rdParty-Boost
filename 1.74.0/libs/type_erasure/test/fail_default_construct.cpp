// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id: fail_default_construct.cpp,v 1.1 2020/09/08 19:32:30 kurt Exp $

#include <boost/type_erasure/any.hpp>
#include <boost/type_erasure/builtin.hpp>

using namespace boost::type_erasure;

int main()
{
    any<copy_constructible<> > y;
}
