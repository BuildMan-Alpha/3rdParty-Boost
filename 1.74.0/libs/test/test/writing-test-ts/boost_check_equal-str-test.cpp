//  (C) Copyright Gennadiy Rozental 2001-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile: boost_check_equal-str-test.cpp,v $
//
//  Version     : $Revision: 1.1 $
//
//  Description : unit test for string comparison specializations
// *****************************************************************************

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/utils/is_cstring.hpp>

BOOST_AUTO_TEST_CASE( check_is_cstring_concept )
{
  namespace bp = boost::unit_test;
  BOOST_TEST((bp::is_cstring<char const*>::value));
  BOOST_TEST((bp::is_cstring<char const []>::value));
  BOOST_TEST((bp::is_cstring<char []>::value));
  BOOST_TEST((bp::is_cstring<char *>::value));
  BOOST_TEST((!bp::is_cstring<std::string>::value));
  BOOST_TEST((!bp::is_cstring< bp::basic_cstring<char> >::value));

  BOOST_TEST((!bp::is_cstring< std::vector<char> >::value));
}

#if defined(BOOST_TEST_STRING_VIEW)
BOOST_AUTO_TEST_CASE( check_is_cstring_concept_string_view )
{
  namespace bp = boost::unit_test;
  BOOST_TEST((!bp::is_cstring< std::string_view >::value));
}
#endif

BOOST_AUTO_TEST_CASE( check_is_cstring_comparable_concept )
{
  namespace bp = boost::unit_test;
  BOOST_TEST((bp::is_cstring_comparable<char const*>::value));
  BOOST_TEST((bp::is_cstring_comparable<char const []>::value));
  BOOST_TEST((bp::is_cstring_comparable<char []>::value));
  BOOST_TEST((bp::is_cstring_comparable<char *>::value));
  BOOST_TEST((bp::is_cstring_comparable<std::string>::value));
  BOOST_TEST((bp::is_cstring_comparable< bp::basic_cstring<char> >::value));

  BOOST_TEST((!bp::is_cstring_comparable< std::vector<char> >::value));
}

#if defined(BOOST_TEST_STRING_VIEW)
BOOST_AUTO_TEST_CASE( check_is_cstring_comparable_concept_string_view )
{
  namespace bp = boost::unit_test;
  BOOST_TEST((bp::is_cstring_comparable< std::string_view >::value));
}
#endif

//____________________________________________________________________________//

BOOST_AUTO_TEST_CASE( check_string_compare )
{

    char const* buf_ptr_cch     = "0abc";
    char const  buf_array_cch[] = "1abc";
    char        buf_array_ch[]  = "2abc";
    char*       buf_ptr_ch      = buf_array_ch + 1;
    std::string buf_str         = "3abc";

    buf_ptr_cch++;
    buf_str = buf_str.substr(1);

    BOOST_TEST((void*)buf_ptr_cch != (void*)(buf_array_cch + 1));
    BOOST_TEST((void*)buf_ptr_cch != (void*)(buf_array_ch + 1));
    BOOST_TEST((void*)(buf_array_cch +1) != (void*)(buf_array_ch + 1));

    BOOST_TEST(buf_ptr_cch == buf_ptr_cch);
#ifndef BOOST_TEST_MACRO_LIMITED_SUPPORT
    BOOST_TEST(buf_ptr_cch == (buf_array_cch + 1));
    BOOST_TEST(buf_ptr_cch == (buf_array_ch + 1));
    BOOST_TEST(buf_ptr_cch == buf_ptr_ch);
    BOOST_TEST(buf_ptr_cch == buf_str);
#endif

#ifndef BOOST_TEST_MACRO_LIMITED_SUPPORT
    BOOST_TEST((buf_array_cch + 1) == buf_ptr_cch);
    BOOST_TEST((buf_array_cch + 1) == (buf_array_cch + 1));
    BOOST_TEST((buf_array_cch + 1) == buf_ptr_ch);
    BOOST_TEST((buf_array_cch + 1) == (buf_array_ch + 1));
    BOOST_TEST((buf_array_cch + 1) == buf_str);
#endif

    BOOST_TEST(buf_ptr_ch == buf_ptr_ch);
#ifndef BOOST_TEST_MACRO_LIMITED_SUPPORT
    BOOST_TEST(buf_ptr_ch == buf_ptr_cch);
    BOOST_TEST(buf_ptr_ch == (buf_array_cch + 1));
    BOOST_TEST(buf_ptr_ch == (buf_array_ch + 1));
    BOOST_TEST(buf_ptr_ch == buf_str);
#endif

#ifndef BOOST_TEST_MACRO_LIMITED_SUPPORT
    BOOST_TEST((buf_array_ch + 1) == buf_ptr_cch);
    BOOST_TEST((buf_array_ch + 1) == (buf_array_cch + 1));
    BOOST_TEST((buf_array_ch + 1) == buf_ptr_ch);
    BOOST_TEST((buf_array_ch + 1) == (buf_array_ch + 1));
    BOOST_TEST((buf_array_ch + 1) == buf_str);
#endif

    BOOST_TEST(buf_str == buf_ptr_cch);
    BOOST_TEST(buf_str == (buf_array_cch + 1));
    BOOST_TEST(buf_str == buf_ptr_ch);
    BOOST_TEST(buf_str == (buf_array_ch + 1));
    BOOST_TEST(buf_str == buf_str);

    BOOST_TEST(buf_ptr_cch == buf_str);
    //BOOST_TEST((buf_array_cch + 1) == buf_str); // does not compile
    BOOST_TEST(buf_ptr_ch == buf_str);
    //BOOST_TEST((buf_array_ch + 1) == buf_str); // does not compile
    BOOST_TEST(buf_str == buf_str);

#ifndef BOOST_TEST_MACRO_LIMITED_SUPPORT
    BOOST_TEST( buf_ptr_cch == buf_ptr_cch, boost::test_tools::per_element() );
    BOOST_TEST( buf_ptr_cch <= "abd" , boost::test_tools::per_element() );
    BOOST_TEST( buf_ptr_cch >= "aba" , boost::test_tools::per_element() );
    BOOST_TEST( buf_str == buf_ptr_cch , boost::test_tools::per_element() );
    BOOST_TEST( buf_str <= "abd" , boost::test_tools::per_element() );
    BOOST_TEST( buf_str >= "aba" , boost::test_tools::per_element() );

    BOOST_TEST( buf_ptr_cch <= buf_ptr_cch, boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch >= buf_ptr_cch, boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch <= "abc" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch < "abd" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch < "abcd" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch >= "abc" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch > "aba" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_ptr_cch > "abad" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_str <= buf_ptr_cch , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_str >= buf_ptr_cch , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_str <= "abc" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_str < "abd" , boost::test_tools::lexicographic() );
    BOOST_TEST( buf_str > "aba" , boost::test_tools::lexicographic() );
#endif

}

#if defined(BOOST_TEST_STRING_VIEW)
BOOST_AUTO_TEST_CASE( check_string_view_compare )
{
    namespace bp = boost::unit_test;
    using namespace std::literals;

    std::string str = "str";
    std::string_view sv = "sv";

    BOOST_TEST((!bp::is_cstring< decltype(sv) >::value));

    BOOST_TEST_CHECK(str == str);
    BOOST_TEST_CHECK(sv == sv);
    BOOST_TEST_CHECK(str != sv);
    BOOST_TEST_CHECK(sv != str);

    //  comparisons based on size
    BOOST_TEST_CHECK(str >= sv);
    BOOST_TEST_CHECK(sv <= str);
    BOOST_TEST_CHECK(str > sv);
    BOOST_TEST_CHECK(sv < str);
  
    BOOST_TEST_CHECK(str <= sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(sv >= str, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(str < sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(sv > str, boost::test_tools::lexicographic());
  
    std::string_view s1 = "this_is_string_view"sv;
    BOOST_TEST(s1 == s1);
    BOOST_TEST(s1 <= s1);
    BOOST_TEST(s1 >= s1);
    BOOST_TEST(s1 == "this_is_string_view"s);
  
    BOOST_TEST(s1 <= "this_is_string_view2"sv);
  
    // lexicographic compare
    BOOST_TEST_CHECK("str" <= sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(sv >= "str", boost::test_tools::lexicographic());
    BOOST_TEST_CHECK("str" < sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(sv > "str", boost::test_tools::lexicographic());

    BOOST_TEST_CHECK("str"sv <= sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(sv >= "str"sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK("str"sv < sv, boost::test_tools::lexicographic());
    BOOST_TEST_CHECK(sv > "str"sv, boost::test_tools::lexicographic());

    // per element, left-right operand
    BOOST_TEST( "sv" <= sv , boost::test_tools::per_element() );
    BOOST_TEST( "sv" >= sv , boost::test_tools::per_element() );
    BOOST_TEST( "sv" == sv , boost::test_tools::per_element() );

    BOOST_TEST( sv <= "sv" , boost::test_tools::per_element() );
    BOOST_TEST( sv >= "sv" , boost::test_tools::per_element() );
    BOOST_TEST( sv == "sv" , boost::test_tools::per_element() );

    BOOST_TEST( "rv" <= sv , boost::test_tools::per_element() );
    BOOST_TEST( "tv" >= sv , boost::test_tools::per_element() );
    BOOST_TEST( "tw" != sv , boost::test_tools::per_element() );

    BOOST_TEST( sv <= "tv" , boost::test_tools::per_element() );
    BOOST_TEST( sv >= "rv" , boost::test_tools::per_element() );
    BOOST_TEST( sv != "ru" , boost::test_tools::per_element() );

}
#endif

// EOF
