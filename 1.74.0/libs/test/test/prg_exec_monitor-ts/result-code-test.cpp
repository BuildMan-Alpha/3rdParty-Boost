//  (C) Copyright Gennadiy Rozental 2003-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile: result-code-test.cpp,v $
//
//  Version     : $Revision: 1.1 $
//
//  Description : test the Execution Monitor logic regards cpp_main return value
// ***************************************************************************
#include <stdexcept>

int cpp_main( int, char* [] )  // note the name
{
    return -1;
}

//____________________________________________________________________________//

// EOF
