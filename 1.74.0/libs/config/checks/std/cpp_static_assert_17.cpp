//  This file was automatically generated on Mon Dec 09 09:47:37 2019
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: cpp_static_assert_17.cpp,v 1.1 2020/09/08 19:21:58 kurt Exp $
//

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#ifndef __cpp_static_assert
#error "Macro << __cpp_static_assert is not set"
#endif

#if __cpp_static_assert < 201411
#error "Macro __cpp_static_assert had too low a value"
#endif

int main( int, char *[] )
{
   return 0;
}

