//  This file was automatically generated on Thu Sep 18 23:32:18 2008
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: no_nested_friendship_pass.cpp,v 1.1 2020/09/08 19:22:04 kurt Exp $
//


// Test file for macro BOOST_NO_NESTED_FRIENDSHIP
// This file should compile, if it does not then
// BOOST_NO_NESTED_FRIENDSHIP should be defined.
// See file boost_no_nested_friendship.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <boost/config.hpp>
#include "test.hpp"

#ifndef BOOST_NO_NESTED_FRIENDSHIP
#include "boost_no_nested_friendship.ipp"
#else
namespace boost_no_nested_friendship = empty_boost;
#endif

int main( int, char *[] )
{
   return boost_no_nested_friendship::test();
}

