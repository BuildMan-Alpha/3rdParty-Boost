
#ifndef BOOST_MPL_GET_TAG_HPP_INCLUDED
#define BOOST_MPL_GET_TAG_HPP_INCLUDED

// Copyright Sergey Krivonos 2017
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: get_tag.hpp,v 1.1 2020/09/08 16:12:34 kurt Exp $
// $Date: 2020/09/08 16:12:34 $
// $Revision: 1.1 $


#define BOOST_MPL_GET_TAG_DEF(TAG) \
    namespace boost { namespace mpl { \
        template<typename T> \
        struct get_##TAG { \
            typedef typename T::TAG type; \
        }; \
    }}

#endif
