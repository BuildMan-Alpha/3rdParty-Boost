// Boost.TypeErasure library
//
// Copyright 2011 Steven Watanabe
//
// Distributed under the Boost Software License Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// $Id: fail_binding_convert_no_mapping.cpp,v 1.1 2020/09/08 19:32:30 kurt Exp $

#include <boost/type_erasure/binding.hpp>
#include <boost/type_erasure/builtin.hpp>
#include <boost/type_erasure/static_binding.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/pair.hpp>

using namespace boost::type_erasure;

int main()
{
    binding< boost::mpl::vector<typeid_<_a>, typeid_<_b> > > b1(
        make_binding<boost::mpl::map<boost::mpl::pair<_a, int>, boost::mpl::pair<_b, int> > >());
    binding< typeid_<_a> > b2(b1, make_binding<boost::mpl::map<> >());
}
