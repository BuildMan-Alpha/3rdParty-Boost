//  This file was automatically generated on Thu Aug 13 16:29:35 2015
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: has_float128_pass.cpp,v 1.1 2020/09/08 19:22:02 kurt Exp $
//


// Test file for macro BOOST_HAS_FLOAT128
// This file should compile, if it does not then
// BOOST_HAS_FLOAT128 should not be defined.
// See file boost_has_float128.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <boost/config.hpp>
#include "test.hpp"

#ifdef BOOST_HAS_FLOAT128
#include "boost_has_float128.ipp"
#else
namespace boost_has_float128 = empty_boost;
#endif

int main( int, char *[] )
{
   return boost_has_float128::test();
}

