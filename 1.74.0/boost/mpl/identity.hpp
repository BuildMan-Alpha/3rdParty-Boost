
#ifndef BOOST_MPL_IDENTITY_HPP_INCLUDED
#define BOOST_MPL_IDENTITY_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: identity.hpp,v 1.1 2020/09/08 16:12:34 kurt Exp $
// $Date: 2020/09/08 16:12:34 $
// $Revision: 1.1 $

#include <boost/mpl/aux_/na_spec.hpp>
#include <boost/mpl/aux_/lambda_support.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(T)
    >
struct identity
{
    typedef T type;
    BOOST_MPL_AUX_LAMBDA_SUPPORT(1, identity, (T))
};

template<
      typename BOOST_MPL_AUX_NA_PARAM(T)
    >
struct make_identity
{
    typedef identity<T> type;
    BOOST_MPL_AUX_LAMBDA_SUPPORT(1, make_identity, (T))
};

BOOST_MPL_AUX_NA_SPEC_NO_ETI(1, identity)
BOOST_MPL_AUX_NA_SPEC_NO_ETI(1, make_identity)

}}

#endif // BOOST_MPL_IDENTITY_HPP_INCLUDED
