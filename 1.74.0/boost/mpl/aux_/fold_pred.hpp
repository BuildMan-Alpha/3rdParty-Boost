
#ifndef BOOST_MPL_AUX_FOLD_PRED_HPP_INCLUDED
#define BOOST_MPL_AUX_FOLD_PRED_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: fold_pred.hpp,v 1.1 2020/09/08 16:12:39 kurt Exp $
// $Date: 2020/09/08 16:12:39 $
// $Revision: 1.1 $

#include <boost/mpl/same_as.hpp>
#include <boost/mpl/apply.hpp>

namespace boost { namespace mpl { namespace aux {

template< typename Last >
struct fold_pred
{
    template<
          typename State
        , typename Iterator
        >
    struct apply
        : not_same_as<Last>::template apply<Iterator>
    {
    };
};

}}}

#endif // BOOST_MPL_AUX_FOLD_PRED_HPP_INCLUDED
