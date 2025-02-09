
#ifndef BOOST_MPL_VECTOR_VECTOR30_C_HPP_INCLUDED
#define BOOST_MPL_VECTOR_VECTOR30_C_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: vector30_c.hpp,v 1.1 2020/09/08 16:12:48 kurt Exp $
// $Date: 2020/09/08 16:12:48 $
// $Revision: 1.1 $

#if !defined(BOOST_MPL_PREPROCESSING_MODE)
#   include <boost/mpl/vector/vector20_c.hpp>
#   include <boost/mpl/vector/vector30.hpp>
#endif

#include <boost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(BOOST_MPL_PREPROCESSING_MODE)

#   define BOOST_MPL_PREPROCESSED_HEADER vector30_c.hpp
#   include <boost/mpl/vector/aux_/include_preprocessed.hpp>

#else

#   include <boost/mpl/aux_/config/typeof.hpp>
#   include <boost/mpl/aux_/config/ctps.hpp>
#   include <boost/preprocessor/iterate.hpp>
#   include <boost/config.hpp>

namespace boost { namespace mpl {

#   define BOOST_PP_ITERATION_PARAMS_1 \
    (3,(21, 30, <boost/mpl/vector/aux_/numbered_c.hpp>))
#   include BOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_USE_PREPROCESSED_HEADERS

#endif // BOOST_MPL_VECTOR_VECTOR30_C_HPP_INCLUDED
