
#ifndef BOOST_MPL_BACK_INSERTER_HPP_INCLUDED
#define BOOST_MPL_BACK_INSERTER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: back_inserter.hpp,v 1.1 2020/09/08 16:12:33 kurt Exp $
// $Date: 2020/09/08 16:12:33 $
// $Revision: 1.1 $

#include <boost/mpl/push_back.hpp>
#include <boost/mpl/inserter.hpp>

namespace boost {
namespace mpl {

template<
      typename Sequence
    >
struct back_inserter
    : inserter< Sequence,push_back<> >
{
};

}}

#endif // BOOST_MPL_BACK_INSERTER_HPP_INCLUDED
