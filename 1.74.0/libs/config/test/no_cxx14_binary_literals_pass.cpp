//  This file was automatically generated on Sat Oct 11 19:26:16 2014
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: no_cxx14_binary_literals_pass.cpp,v 1.1 2020/09/08 19:22:03 kurt Exp $
//


// Test file for macro BOOST_NO_CXX14_BINARY_LITERALS
// This file should compile, if it does not then
// BOOST_NO_CXX14_BINARY_LITERALS should be defined.
// See file boost_no_cxx14_binary_literals.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <boost/config.hpp>
#include "test.hpp"

#ifndef BOOST_NO_CXX14_BINARY_LITERALS
#include "boost_no_cxx14_binary_literals.ipp"
#else
namespace boost_no_cxx14_binary_literals = empty_boost;
#endif

int main( int, char *[] )
{
   return boost_no_cxx14_binary_literals::test();
}

