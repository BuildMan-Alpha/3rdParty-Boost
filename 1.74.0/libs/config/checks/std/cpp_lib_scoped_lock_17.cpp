//  This file was automatically generated on Mon Dec 09 09:47:38 2019
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.//
//  Revision $Id: cpp_lib_scoped_lock_17.cpp,v 1.1 2020/09/08 19:21:57 kurt Exp $
//

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

#include <mutex>

#ifndef __cpp_lib_scoped_lock
#error "Macro << __cpp_lib_scoped_lock is not set"
#endif

#if __cpp_lib_scoped_lock < 201703
#error "Macro __cpp_lib_scoped_lock had too low a value"
#endif

int main( int, char *[] )
{
   return 0;
}

