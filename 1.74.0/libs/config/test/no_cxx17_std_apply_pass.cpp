//  This file was automatically generated on Fri Oct 14 12:13:46 2016
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: no_cxx17_std_apply_pass.cpp,v 1.1 2020/09/08 19:22:04 kurt Exp $
//


// Test file for macro BOOST_NO_CXX17_STD_APPLY
// This file should compile, if it does not then
// BOOST_NO_CXX!/_STD_APPLY should be defined.
// See file boost_no_cxx17_std_apply.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <boost/config.hpp>
#include "test.hpp"

#ifndef BOOST_NO_CXX17_STD_APPLY
#include "boost_no_cxx17_std_apply.ipp"
#else
namespace boost_no_cxx17_std_apply = empty_boost;
#endif

int main( int, char *[] )
{
   return boost_no_cxx17_std_apply::test();
}

