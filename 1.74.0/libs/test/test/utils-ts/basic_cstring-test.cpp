//  (C) Copyright Gennadiy Rozental 2001-2015.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile: basic_cstring-test.cpp,v $
//
//  Version     : $Revision: 1.1 $
//
//  Description : basic_cstring unit test
// *****************************************************************************

#ifdef _MSC_VER
#pragma warning(disable: 4996)
#pragma warning(disable: 4267)
#endif

// Boost.Test
#include <boost/test/unit_test.hpp>

#include <boost/test/utils/basic_cstring/basic_cstring.hpp>
#include <boost/test/utils/basic_cstring/compare.hpp>
#include <boost/test/utils/basic_cstring/io.hpp>
#include <boost/test/tools/output_test_stream.hpp>
namespace utf = boost::unit_test;
namespace tt  = boost::test_tools;
using utf::const_string;

// Boost
#include <boost/mpl/list.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/type_traits/add_const.hpp>

// STL
#include <cctype>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

namespace mpl = boost::mpl;

typedef mpl::list2<char const,wchar_t const>                                base_const_char_types;
typedef mpl::list3<char,unsigned char,wchar_t>                              mutable_char_types;
typedef mpl::transform<mutable_char_types,boost::add_const<mpl::_1> >::type const_char_types;
typedef mpl::joint_view<const_char_types,mutable_char_types>                char_types;
typedef mpl::list2<char,const char>                                         io_test_types;

//____________________________________________________________________________//

template<typename CharT>
struct string_literal {
    typedef typename boost::remove_const<CharT>::type   mutable_char;

    string_literal() {}
    string_literal( char const* orig, std::size_t orig_size )
    {
        assign(orig, orig_size);
    }

    CharT*    begin() const { return const_cast<CharT*>(buff.c_str()); }

    void    assign( char const* orig, std::size_t orig_size )
    {
        buff.resize( orig_size );
        for (size_t index = 0; index < orig_size; ++index)
            buff[index] = orig[index];
    }

    std::basic_string<mutable_char> buff;
};

//____________________________________________________________________________//

template<typename CharT>
CharT*
test_string( CharT* = 0 )
{
    static string_literal<CharT> l( "test_string", 11 );

    return l.begin();
}
#define TEST_STRING test_string<CharT>( (CharT*)0 )

//____________________________________________________________________________//

template<typename CharT>
CharT*
static_literal(char const* orig, std::size_t orig_size)
{
    static string_literal<CharT> l;
    
    l.assign(orig, orig_size);

    return l.begin();
}
#define LITERAL( s ) static_literal<CharT>( s, sizeof( s ) )

#define LOCAL_DEF( name, s )                                                \
string_literal<CharT> BOOST_JOIN( sl, __LINE__)(s, sizeof( s ));            \
utf::basic_cstring<CharT> name( (CharT*)(BOOST_JOIN( sl, __LINE__).begin()))\
/**/


//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( constructors_test, CharT )
{
    {
        utf::basic_cstring<CharT> bcs;
        BOOST_TEST( bcs.size() == 0U );
        BOOST_TEST( bcs.is_empty() );
    }

    {
        utf::basic_cstring<CharT> bcs( utf::basic_cstring<CharT>::null_str() );
        BOOST_TEST( bcs.size() == 0U );
        BOOST_TEST( bcs.is_empty() );
    }

    {
        utf::basic_cstring<CharT> bcs( 0 );
        BOOST_TEST( bcs.size() == 0U );
        BOOST_TEST( bcs.is_empty() );
    }

    {
        typedef typename utf::basic_cstring<CharT>::traits_type traits;

        utf::basic_cstring<CharT> bcs( TEST_STRING );
        BOOST_TEST( traits::compare( bcs.begin(), TEST_STRING, bcs.size() ) == 0 );
        BOOST_TEST( bcs.size() == traits::length( TEST_STRING ) );

        utf::basic_cstring<CharT> bcs1( bcs );
        BOOST_TEST( traits::compare( bcs1.begin(), TEST_STRING, bcs1.size() ) == 0 );
    }

    {
        typedef typename utf::basic_cstring<CharT>::traits_type traits;

        utf::basic_cstring<CharT> bcs( TEST_STRING, 4 );
        BOOST_TEST( traits::compare( bcs.begin(), LITERAL( "test" ), bcs.size() ) == 0 );
    }

    {
        typedef typename utf::basic_cstring<CharT>::traits_type traits;

        utf::basic_cstring<CharT> bcs( TEST_STRING, TEST_STRING + 6 );
        BOOST_TEST( traits::compare( bcs.begin(), LITERAL( "test_s" ), bcs.size() ) == 0 );
    }
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( constructors_std_string_test, CharT )
{
    typedef typename utf::basic_cstring<CharT>::traits_type traits;

    {
        typename utf::basic_cstring<CharT>::std_string l( TEST_STRING );

        utf::basic_cstring<CharT> bcs( l );
        BOOST_TEST( traits::compare( bcs.begin(), TEST_STRING, bcs.size() ) == 0 );
    }

}

//____________________________________________________________________________//

void array_construction_test()
{
    const_string bcs_array[] = { "str1", "str2" };

    BOOST_TEST( const_string::traits_type::compare( bcs_array[0].begin(), "str1", bcs_array[0].size() ) == 0 );
    BOOST_TEST( const_string::traits_type::compare( bcs_array[1].begin(), "str2", bcs_array[1].size() ) == 0 );

    const_string bcs( "abc" );
    BOOST_TEST( const_string::traits_type::compare( bcs.begin(), "abc", bcs.size() ) == 0 );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( data_access_test, CharT )
{
    typedef typename utf::basic_cstring<CharT>::traits_type traits_type;

    utf::basic_cstring<CharT> bcs1( TEST_STRING );
    BOOST_TEST( traits_type::compare( bcs1.begin(), TEST_STRING, bcs1.size() ) == 0 );
    BOOST_TEST( traits_type::compare( bcs1.begin(), bcs1.begin(), bcs1.size() ) == 0 );

    BOOST_TEST( bcs1[0] == 't' );
    BOOST_TEST( bcs1[4] == '_' );
    BOOST_TEST( bcs1[bcs1.size()-1] == 'g' );

    BOOST_TEST( bcs1[0] == bcs1.at( 0 ) );
    BOOST_TEST( bcs1[2] == bcs1.at( 5 ) );
    BOOST_TEST( bcs1.at( bcs1.size() - 1 ) == 'g' );
    BOOST_TEST( bcs1.at( bcs1.size() ) == 0 );
    BOOST_TEST( bcs1.at( bcs1.size()+1 ) == 0 );

    BOOST_TEST( utf::first_char( bcs1 ) == 't' );
    BOOST_TEST( utf::last_char( bcs1 ) == 'g' );

    BOOST_TEST( utf::first_char( utf::basic_cstring<CharT>() ) == 0 );
    BOOST_TEST( utf::last_char( utf::basic_cstring<CharT>() ) == 0 );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( size_test, CharT )
{
    utf::basic_cstring<CharT> bcs1;

    BOOST_TEST( bcs1.size() == 0U );
    BOOST_TEST( bcs1.is_empty() );

    bcs1 = TEST_STRING;
    BOOST_TEST( bcs1.size() == 11U );

    bcs1.clear();
    BOOST_TEST( bcs1.size() == 0U );
    BOOST_TEST( bcs1.is_empty() );

    bcs1 = utf::basic_cstring<CharT>( TEST_STRING, 4 );
    BOOST_TEST( bcs1.size() == 4U );

    bcs1.resize( 5 );
    BOOST_TEST( bcs1.size() == 4U );

    bcs1.resize( 3 );
    BOOST_TEST( bcs1.size() == 3U );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( asignment_test, CharT )
{
    typedef typename utf::basic_cstring<CharT>::traits_type traits_type;

    utf::basic_cstring<CharT> bcs1;
    string_literal<CharT> l( "test", 4 );

    bcs1 = l.begin();
    BOOST_TEST( traits_type::compare( bcs1.begin(), LITERAL( "test" ), bcs1.size() ) == 0 );

    utf::basic_cstring<CharT> bcs2( TEST_STRING );
    bcs1 = bcs2;
    BOOST_TEST( traits_type::compare( bcs1.begin(), TEST_STRING, bcs1.size() ) == 0 );

    bcs1.assign( l.begin() );
    BOOST_TEST( traits_type::compare( bcs1.begin(), LITERAL( "test" ), bcs1.size() ) == 0 );

    bcs1.assign( l.begin()+1, l.begin()+3 );
    BOOST_TEST( traits_type::compare( bcs1.begin(), LITERAL( "est" ), bcs1.size() ) == 0 );

    bcs1.assign( bcs2, 4, 3 );
    BOOST_TEST( traits_type::compare( bcs1.begin(), LITERAL( "_st" ), bcs1.size() ) == 0 );

    bcs1.swap( bcs2 );
    BOOST_TEST( traits_type::compare( bcs1.begin(), TEST_STRING, bcs1.size() ) == 0 );
    BOOST_TEST( traits_type::compare( bcs2.begin(), LITERAL( "_st" ), bcs2.size() ) == 0 );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( asignment_std_string_test, CharT )
{
    typedef typename utf::basic_cstring<CharT>::traits_type traits_type;

    utf::basic_cstring<CharT> bcs1;
    typename utf::basic_cstring<CharT>::std_string l( TEST_STRING );

    bcs1 = l;
    BOOST_TEST( traits_type::compare( bcs1.begin(), TEST_STRING, bcs1.size() ) == 0 );

    bcs1.assign( l );
    BOOST_TEST( traits_type::compare( bcs1.begin(), TEST_STRING, bcs1.size() ) == 0 );

    bcs1.assign( l, 1, 2 );
    BOOST_TEST( traits_type::compare( bcs1.begin(), LITERAL( "es" ), bcs1.size() ) == 0 );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( comparison_test, CharT )
{
    utf::basic_cstring<CharT> bcs1( TEST_STRING );
    utf::basic_cstring<CharT> bcs2( TEST_STRING );

    BOOST_TEST(( bcs1 == TEST_STRING ));
    BOOST_TEST(( TEST_STRING == bcs1 ));
    BOOST_TEST(( bcs1 == bcs2 ));

    bcs1.resize( 4 );

    BOOST_TEST(( bcs1 == LITERAL( "test" ) ));

    BOOST_TEST(( bcs1 != TEST_STRING ));
    BOOST_TEST(( TEST_STRING != bcs1 ));
    BOOST_TEST(( bcs1 != bcs2 ));

    LOCAL_DEF( bcs3, "TeSt" );
    BOOST_TEST( utf::case_ins_eq( bcs1, bcs3 ) );
}

//____________________________________________________________________________//

BOOST_TEST_DONT_PRINT_LOG_VALUE( std::wstring )

BOOST_TEST_CASE_TEMPLATE_FUNCTION( comparison_std_string_test, CharT )
{
    utf::basic_cstring<CharT> bcs1( TEST_STRING );
    typename utf::basic_cstring<CharT>::std_string l( TEST_STRING );

    BOOST_TEST( bcs1 == l );
    BOOST_TEST( l == bcs1 );

    bcs1.resize( 4 );

    BOOST_TEST( bcs1 != l );
    BOOST_TEST( l != bcs1 );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( ordering_test, CharT )
{
    LOCAL_DEF( bcs1, "aBcd" );
    LOCAL_DEF( bcs2, "aBbdd" );
    LOCAL_DEF( bcs3, "aBbde" );
    LOCAL_DEF( bcs4, "abab" );

    BOOST_TEST(( bcs1 < bcs2 ));
    BOOST_TEST(( bcs2 < bcs3 ));
    BOOST_TEST(( bcs1 < bcs3 ));
    BOOST_TEST(( bcs1 < bcs4 ));

    utf::case_ins_less<CharT> cil;
    BOOST_TEST( cil( bcs4, bcs1 ) );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( trim_test, CharT )
{
    LOCAL_DEF( bcs0, "tes" );

    bcs0.trim_right( 1 );
    BOOST_TEST( bcs0.size() == 2U );
    BOOST_TEST( bcs0[0] == 't' );

    bcs0.trim_left( 1 );
    BOOST_TEST( bcs0.size() == 1U );
    BOOST_TEST( bcs0[0] == 'e' );

    bcs0.trim_left( 1 );
    BOOST_TEST( bcs0.is_empty() );

    bcs0 = TEST_STRING;
    bcs0.trim_left( 11 );
    BOOST_TEST( bcs0.is_empty() );

    bcs0 = TEST_STRING;
    bcs0.trim_right( 11 );
    BOOST_TEST( bcs0.is_empty() );

    bcs0 = TEST_STRING;
    bcs0.trim_right( bcs0.size() - bcs0.find( LITERAL( "t_s" ) ) - 3 );
    BOOST_TEST( bcs0 == LITERAL( "test_s" ) );

    bcs0.trim_left( bcs0.find( LITERAL( "t_s" ) ) );
    BOOST_TEST( bcs0 == LITERAL( "t_s" ) );

    LOCAL_DEF( bcs1, "abcd   " );
    LOCAL_DEF( bcs2, "     abcd" );
    LOCAL_DEF( bcs3, "  abcd  " );

    bcs1.trim_right();
    BOOST_TEST( bcs1 == LITERAL( "abcd" ) );

    bcs2.trim_left();
    BOOST_TEST( bcs2 == LITERAL( "abcd" ) );

    bcs3.trim( LITERAL( "\"" ) );
    BOOST_TEST( bcs3 == LITERAL( "  abcd  " ) );

    bcs3.trim();
    BOOST_TEST( bcs3 == LITERAL( "abcd" ) );

    bcs3.trim();
    BOOST_TEST( bcs3 == LITERAL( "abcd" ) );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( io_test, CharT )
{
    utf::basic_cstring<CharT> bcs1( TEST_STRING );
    bcs1.trim_right( 7 );

    tt::output_test_stream ostr;

    ostr << std::setw( 6 ) << bcs1;
    BOOST_TEST( ostr.is_equal( "  test" ) );

    ostr << std::setw( 3 ) << bcs1;
    BOOST_TEST( ostr.is_equal( "test" ) );

    ostr << std::setw( 5 ) << std::setiosflags( std::ios::left ) << bcs1;
    BOOST_TEST( ostr.is_equal( "test " ) );
}

//____________________________________________________________________________//

BOOST_TEST_CASE_TEMPLATE_FUNCTION( find_test, CharT )
{
    typedef typename utf::basic_cstring<CharT>::size_type size;
    utf::basic_cstring<CharT> bcs1( TEST_STRING );

    size not_found = (size)utf::basic_cstring<CharT>::npos;

    BOOST_TEST( bcs1.find( utf::basic_cstring<CharT>() ) == not_found );
    BOOST_TEST( bcs1.find( LITERAL( "test" ) ) == (size)0 );
    BOOST_TEST( bcs1.find( TEST_STRING ) == (size)0 );
    BOOST_TEST( bcs1.find( LITERAL( "test_string " ) ) == not_found );
    BOOST_TEST( bcs1.find( LITERAL( " test_string" ) ) == not_found );
    BOOST_TEST( bcs1.find( LITERAL( "est" ) ) == (size)1 );
    BOOST_TEST( bcs1.find( LITERAL( "t_st" ) ) == (size)3 );
    BOOST_TEST( bcs1.find( LITERAL( "ing" ) ) == (size)8 );
    BOOST_TEST( bcs1.find( LITERAL( "tst" ) ) == not_found );

    BOOST_TEST( bcs1.rfind( utf::basic_cstring<CharT>() ) == not_found );
    BOOST_TEST( bcs1.rfind( LITERAL( "test" ) ) == (size)0 );
    BOOST_TEST( bcs1.rfind( TEST_STRING ) == (size)0 );
    BOOST_TEST( bcs1.rfind( LITERAL( "test_string " ) ) == not_found );
    BOOST_TEST( bcs1.rfind( LITERAL( " test_string" ) ) == not_found );
    BOOST_TEST( bcs1.rfind( LITERAL( "est" ) ) == (size)1 );
    BOOST_TEST( bcs1.rfind( LITERAL( "t_st" ) ) == (size)3 );
    BOOST_TEST( bcs1.rfind( LITERAL( "ing" ) ) == (size)8 );
    BOOST_TEST( bcs1.rfind( LITERAL( "tst" ) ) == not_found );
}

//____________________________________________________________________________//

void const_conversion()
{
    char arr[] = { "ABC" };

    utf::basic_cstring<char> str1( arr );
    utf::basic_cstring<char const> str2;

    str2.assign( str1 );

    BOOST_TEST( str1 == "ABC" );
    BOOST_TEST( str2 == "ABC" );
}

//____________________________________________________________________________//

#if defined(BOOST_TEST_STRING_VIEW)
BOOST_TEST_CASE_TEMPLATE_FUNCTION( string_view_support, CharT )
{
  using namespace std::literals;
  typedef std::basic_string_view<CharT> string_view_t;
  namespace utf = boost::unit_test;

  {
    string_view_t sv = LITERAL("");

    utf::stringview_cstring_helper<CharT, string_view_t> svh = sv;
    BOOST_TEST( svh.size() == 0U );
    BOOST_TEST( svh.is_empty() );
  }


  {
    string_view_t sv = LITERAL("bla");

    utf::stringview_cstring_helper<CharT, string_view_t> svh = sv;
    BOOST_TEST( svh.size() == 3U );
    BOOST_TEST( !svh.is_empty() );
  }
}
#endif


//____________________________________________________________________________//

utf::test_suite*
init_unit_test_suite( int /*argc*/, char* /*argv*/[] )
{
    utf::test_suite* test= BOOST_TEST_SUITE("basic_cstring test");

    test->add( BOOST_TEST_CASE_TEMPLATE( constructors_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( constructors_std_string_test, base_const_char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( asignment_std_string_test, base_const_char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( comparison_std_string_test, base_const_char_types ) );
    test->add( BOOST_TEST_CASE( array_construction_test ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( data_access_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( size_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( asignment_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( comparison_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( ordering_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( trim_test, char_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( io_test, io_test_types ) );
    test->add( BOOST_TEST_CASE_TEMPLATE( find_test, char_types ) );
    test->add( BOOST_TEST_CASE( &const_conversion ) );
  
#if defined(BOOST_TEST_STRING_VIEW)
    test->add( BOOST_TEST_CASE_TEMPLATE( string_view_support, char_types ) );
#endif

    return test;
}

// EOF
