//  This file was automatically generated on Wed Jan 03 23:31:30 2018
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: no_cxx11_defaulted_moves_fail.cpp,v 1.1 2020/09/08 19:22:03 kurt Exp $
//


// Test file for macro BOOST_NO_CXX11_DEFAULTED_MOVES
// This file should not compile, if it does then
// BOOST_NO_CXX11_DEFAULTED_MOVES should not be defined.
// See file boost_no_cxx11_defaulted_moves.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <boost/config.hpp>
#include "test.hpp"

#ifdef BOOST_NO_CXX11_DEFAULTED_MOVES
#include "boost_no_cxx11_defaulted_moves.ipp"
#else
#error "this file should not compile"
#endif

int main( int, char *[] )
{
   return boost_no_cxx11_defaulted_moves::test();
}

