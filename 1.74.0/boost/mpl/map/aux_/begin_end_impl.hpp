
#ifndef BOOST_MPL_MAP_AUX_BEGIN_END_IMPL_HPP_INCLUDED
#define BOOST_MPL_MAP_AUX_BEGIN_END_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: begin_end_impl.hpp,v 1.1 2020/09/08 16:12:45 kurt Exp $
// $Date: 2020/09/08 16:12:45 $
// $Revision: 1.1 $

#include <boost/mpl/begin_end_fwd.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/map/aux_/iterator.hpp>

namespace boost { namespace mpl {

template<>
struct begin_impl< aux::map_tag >
{
    template< typename Map > struct apply
    {
        typedef typename next< typename Map::order >::type max_order_;
        typedef m_iter<
              Map
            , next_order<Map,1,max_order_::value>::value
            , max_order_::value
            > type;
    };
};

template<>
struct end_impl< aux::map_tag >
{
    template< typename Map > struct apply
    {
        typedef typename next< typename Map::order >::type max_order_;
        typedef m_iter< Map,max_order_::value,max_order_::value > type;
    };
};

}}

#endif // BOOST_MPL_MAP_AUX_BEGIN_END_IMPL_HPP_INCLUDED
