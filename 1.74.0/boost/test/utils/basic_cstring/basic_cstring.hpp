//  (C) Copyright Gennadiy Rozental 2001.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.
//
//  File        : $RCSfile: basic_cstring.hpp,v $
//
//  Version     : $Revision: 1.1 $
//
//  Description : class basic_cstring wraps C string and provide std_string like
//                interface
// ***************************************************************************

#ifndef BOOST_TEST_UTILS_BASIC_CSTRING_HPP
#define BOOST_TEST_UTILS_BASIC_CSTRING_HPP

// Boost.Test
#include <boost/test/utils/basic_cstring/basic_cstring_fwd.hpp>
#include <boost/test/utils/basic_cstring/bcs_char_traits.hpp>

// Boost
#include <boost/type_traits/remove_cv.hpp>

// STL
#include <string>

#if defined(BOOST_TEST_STRING_VIEW)
#include <string_view>
#endif

#include <boost/test/detail/suppress_warnings.hpp>

//____________________________________________________________________________//

namespace boost {

namespace unit_test {

// ************************************************************************** //
// **************                basic_cstring                 ************** //
// ************************************************************************** //

template<typename CharT>
class BOOST_SYMBOL_VISIBLE basic_cstring {
    typedef basic_cstring<CharT>                        self_type;
public:
    // Subtypes
    typedef ut_detail::bcs_char_traits<CharT>           traits_type;
    typedef typename traits_type::std_string            std_string;

    typedef CharT                                       value_type;
    typedef typename remove_cv<value_type>::type        value_ret_type;
    typedef value_type*                                 pointer;
    typedef value_type const*                           const_pointer;
    typedef value_type&                                 reference;
    typedef const value_type&                           const_reference;
    typedef std::size_t                                 size_type;
    typedef std::ptrdiff_t                              difference_type;

    typedef value_type const*                           const_iterator;
    typedef value_type*                                 iterator;

    // !! should also present reverse_iterator, const_reverse_iterator

#if !BOOST_WORKAROUND(__IBMCPP__, BOOST_TESTED_AT(600)) && !defined(__DCC__)
    BOOST_STATIC_CONSTANT(size_type, npos = static_cast<size_type>(-1));
#else
    // IBM/VisualAge version 6 is not able to handle enums larger than 4 bytes.
    // But size_type is 8 bytes in 64bit mode.
    static const size_type npos = -1 ;
#endif

    static pointer  null_str();

    // Constructors; default copy constructor is generated by compiler
    basic_cstring();
    basic_cstring( basic_cstring const & );
    basic_cstring( std_string const& s );
    basic_cstring( pointer s );
    template<typename LenType>
    basic_cstring( pointer s, LenType len ) : m_begin( s ), m_end( m_begin + len ) {}
    basic_cstring( pointer first, pointer last );

    // data access methods
    value_ret_type  operator[]( size_type index ) const;
    value_ret_type  at( size_type index ) const;

    // size operators
    size_type       size() const;
    bool            is_empty() const;
    void            clear();
    void            resize( size_type new_len );

    // !! only for STL container conformance use is_empty instead
    bool            empty() const;

    // Trimming
    self_type&      trim_right( size_type trim_size );
    self_type&      trim_left( size_type trim_size );
    self_type&      trim_right( iterator it );
    self_type&      trim_left( iterator it );
#if !BOOST_WORKAROUND(__IBMCPP__, BOOST_TESTED_AT(800))
    self_type&      trim_left( self_type exclusions = self_type() ) ;
    self_type&      trim_right( self_type exclusions = self_type() ) ;
    self_type&      trim( self_type exclusions = self_type() ) ;
#else
    // VA C++/XL C++ v6 and v8 has in this case a problem with the default arguments.
    self_type&      trim_left( self_type exclusions );
    self_type&      trim_right( self_type exclusions );
    self_type&      trim( self_type exclusions );
    self_type&      trim_left()     { return trim_left( self_type() ); }
    self_type&      trim_right()    { return trim_right( self_type() ); }
    self_type&      trim()          { return trim( self_type() ); }
#endif

    // Assignment operators
    basic_cstring&  operator=( self_type const& s );
    basic_cstring&  operator=( std_string const& s );
    basic_cstring&  operator=( pointer s );

    template<typename CharT2>
    basic_cstring&  assign( basic_cstring<CharT2> const& s )
    {
        return *this = basic_cstring<CharT>( s.begin(), s.end() );
    }
    template<typename PosType, typename LenType>
    basic_cstring&  assign( self_type const& s, PosType pos, LenType len )
    {
        return *this = self_type( s.m_begin + pos, len );
    }

    basic_cstring&  assign( std_string const& s );
    template<typename PosType, typename LenType>
    basic_cstring&  assign( std_string const& s, PosType pos, LenType len )
    {
        return *this = self_type( s.c_str() + pos, len );
    }
    basic_cstring&  assign( pointer s );
    template<typename LenType>
    basic_cstring&  assign( pointer s, LenType len )
    {
        return *this = self_type( s, len );
    }
    basic_cstring&  assign( pointer f, pointer l );

    // swapping
    void            swap( self_type& s );

    // Iterators
    iterator        begin();
    const_iterator  begin() const;
    iterator        end();
    const_iterator  end() const;

    // !! should have rbegin, rend

    // substring search operation
    size_type       find( basic_cstring ) const;
    size_type       rfind( basic_cstring ) const;
    self_type       substr( size_type beg_index, size_type end_index = npos ) const;

private:
    static self_type default_trim_ex();

    // Data members
    iterator        m_begin;
    iterator        m_end;
    static CharT null;
};

// ************************************************************************** //
// **************         cstring_string_view_helper           ************** //
// ************************************************************************** //


#if defined(BOOST_TEST_STRING_VIEW)
// Helper for instanciating a subclass of cstring using a string_view. We do not
// change the API of cstring using BOOST_TEST_STRING_VIEW as the code should remain
// compatible between boost.test and test module using different compiler options.
//! @internal
template <class CharT, class string_view_t = std::basic_string_view<CharT>>
class BOOST_SYMBOL_VISIBLE stringview_cstring_helper : public basic_cstring<CharT> {
public:
  stringview_cstring_helper(string_view_t const& sv)
  : basic_cstring<CharT>(const_cast<CharT*>(sv.data()), sv.size())
  {}
};
#endif


// ************************************************************************** //
// **************            basic_cstring::impl               ************** //
// ************************************************************************** //

//____________________________________________________________________________//

template<typename CharT>
CharT basic_cstring<CharT>::null = 0;

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::pointer
basic_cstring<CharT>::null_str()
{
    return &null;
}

//____________________________________________________________________________//

template<typename CharT>
inline
basic_cstring<CharT>::basic_cstring()
: m_begin( null_str() )
, m_end( m_begin )
{
}

//____________________________________________________________________________//

template<typename CharT>
inline
basic_cstring<CharT>::basic_cstring(basic_cstring const & s)
: m_begin( s.m_begin )
, m_end( s.m_end )
{
}

//____________________________________________________________________________//

template<typename CharT>
inline
basic_cstring<CharT>::basic_cstring( std_string const& s )
: m_begin( s.c_str() )
, m_end( m_begin + s.size() )
{
}

//____________________________________________________________________________//

template<typename CharT>
inline
basic_cstring<CharT>::basic_cstring( pointer s )
: m_begin( s ? s : null_str() )
, m_end  ( m_begin + (s ? traits_type::length( s ) : 0 ) )
{
}

//____________________________________________________________________________//

template<typename CharT>
inline
basic_cstring<CharT>::basic_cstring( pointer first, pointer last )
: m_begin( first )
, m_end( last )
{
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::value_ret_type
basic_cstring<CharT>::operator[]( size_type index ) const
{
    return m_begin[index];
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::value_ret_type
basic_cstring<CharT>::at( size_type index ) const
{
    if( m_begin + index >= m_end )
        return static_cast<value_type>(0);

    return m_begin[index];
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::size_type
basic_cstring<CharT>::size() const
{
    return static_cast<size_type>(m_end - m_begin);
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
basic_cstring<CharT>::is_empty() const
{
    return m_end == m_begin;
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
basic_cstring<CharT>::empty() const
{
    return is_empty();
}

//____________________________________________________________________________//

template<typename CharT>
inline void
basic_cstring<CharT>::clear()
{
    m_begin = m_end;
}

//____________________________________________________________________________//

template<typename CharT>
inline void
basic_cstring<CharT>::resize( size_type new_len )
{
    if( m_begin + new_len < m_end )
        m_end = m_begin + new_len;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim_left( size_type trim_size )
{
    m_begin += trim_size;
    if( m_end <= m_begin )
        clear();

    return *this;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim_left( iterator it )
{
    m_begin = it;
    if( m_end <= m_begin )
        clear();

    return *this;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim_left( basic_cstring exclusions )
{
    if( exclusions.is_empty() )
        exclusions = default_trim_ex();

    iterator it;
    for( it = begin(); it != end(); ++it ) {
        if( traits_type::find( exclusions.begin(), exclusions.size(), *it ) == reinterpret_cast<pointer>(0) )
            break;
    }

    return trim_left( it );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim_right( size_type trim_size )
{
    m_end  -= trim_size;
    if( m_end <= m_begin )
        clear();

    return *this;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim_right( iterator it )
{
    m_end = it;
    if( m_end <= m_begin )
        clear();

    return *this;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim_right( basic_cstring exclusions )
{
    if( exclusions.is_empty() )
        exclusions = default_trim_ex();

    iterator it;

    for( it = end()-1; it != begin()-1; --it ) {
        if( self_type::traits_type::find( exclusions.begin(),  exclusions.size(), *it ) == reinterpret_cast<pointer>(0) )
            break;
    }

    return trim_right( it+1 );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::trim( basic_cstring exclusions )
{
    trim_left( exclusions );
    trim_right( exclusions );

    return *this;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::operator=( basic_cstring<CharT> const& s )
{
    m_begin = s.m_begin;
    m_end   = s.m_end;

    return *this;
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::operator=( std_string const& s )
{
    return *this = self_type( s );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::operator=( pointer s )
{
    return *this = self_type( s );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::assign( std_string const& s )
{
    return *this = self_type( s );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::assign( pointer s )
{
    return *this = self_type( s );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>&
basic_cstring<CharT>::assign( pointer f, pointer l )
{
    return *this = self_type( f, l );
}

//____________________________________________________________________________//

template<typename CharT>
inline void
basic_cstring<CharT>::swap( basic_cstring<CharT>& s )
{
    // do not want to include alogrithm
    pointer tmp1    = m_begin;
    pointer tmp2    = m_end;

    m_begin         = s.m_begin;
    m_end           = s.m_end;

    s.m_begin       = tmp1;
    s.m_end         = tmp2;
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::iterator
basic_cstring<CharT>::begin()
{
    return m_begin;
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::const_iterator
basic_cstring<CharT>::begin() const
{
    return m_begin;
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::iterator
basic_cstring<CharT>::end()
{
    return m_end;
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::const_iterator
basic_cstring<CharT>::end() const
{
    return m_end;
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::size_type
basic_cstring<CharT>::find( basic_cstring<CharT> str ) const
{
    if( str.is_empty() || str.size() > size() )
        return static_cast<size_type>(npos);

    const_iterator it   = begin();
    const_iterator last = end() - str.size() + 1;

    while( it != last ) {
        if( traits_type::compare( it, str.begin(), str.size() ) == 0 )
            break;

        ++it;
    }

    return it == last ? npos : static_cast<size_type>(it - begin());
}

//____________________________________________________________________________//

template<typename CharT>
inline typename basic_cstring<CharT>::size_type
basic_cstring<CharT>::rfind( basic_cstring<CharT> str ) const
{
    if( str.is_empty() || str.size() > size() )
        return static_cast<size_type>(npos);

    const_iterator it   = end() - str.size();
    const_iterator last = begin()-1;

    while( it != last ) {
        if( traits_type::compare( it, str.begin(), str.size() ) == 0 )
            break;

        --it;
    }

    return it == last ? static_cast<size_type>(npos) : static_cast<size_type>(it - begin());
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>
basic_cstring<CharT>::substr( size_type beg_index, size_type end_index ) const
{
    return beg_index > size()
            ?       self_type()
            : end_index > size()
                ?   self_type( m_begin + beg_index, m_end )
                :   self_type( m_begin + beg_index, m_begin + end_index );
}

//____________________________________________________________________________//

template<typename CharT>
inline basic_cstring<CharT>
basic_cstring<CharT>::default_trim_ex()
{
    static CharT ws[3] = { CharT(' '), CharT('\t'), CharT('\n') }; // !! wide case

    return self_type( ws, 3 );
}

//____________________________________________________________________________//

// ************************************************************************** //
// **************             comparison operators             ************** //
// ************************************************************************** //

template<typename CharT1,typename CharT2>
inline bool
operator==( basic_cstring<CharT1> const& s1, basic_cstring<CharT2> const& s2 )
{
    typedef typename basic_cstring<CharT1>::traits_type traits_type;
    return s1.size() == s2.size() &&
               traits_type::compare( s1.begin(), s2.begin(), s1.size() ) == 0;
}

//____________________________________________________________________________//

template<typename CharT1,typename CharT2>
inline bool
operator==( basic_cstring<CharT1> const& s1, CharT2* s2 )
{
#if !defined(__DMC__)
    return s1 == basic_cstring<CharT2>( s2 );
#else
    return s1 == basic_cstring<CharT2 const>( s2 );
#endif
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator==( basic_cstring<CharT> const& s1, typename basic_cstring<CharT>::std_string const& s2 )
{
    return s1 == basic_cstring<CharT>( s2 );
}

//____________________________________________________________________________//

template<typename CharT1,typename CharT2>
inline bool
operator==( CharT1* s2, basic_cstring<CharT2> const& s1 )
{
    return s1 == s2;
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator==( typename basic_cstring<CharT>::std_string const& s2, basic_cstring<CharT> const& s1 )
{
    return s1 == s2;
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator!=( basic_cstring<CharT> const& s1, CharT* s2 )
{
    return !(s1 == s2);
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator!=( CharT* s2, basic_cstring<CharT> const& s1 )
{
    return !(s1 == s2);
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator!=( basic_cstring<CharT> const& s1, basic_cstring<CharT> const& s2 )
{
    return !(s1 == s2);
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator!=( basic_cstring<CharT> const& s1, typename basic_cstring<CharT>::std_string const& s2 )
{
    return !(s1 == s2);
}

//____________________________________________________________________________//

template<typename CharT>
inline bool
operator!=( typename basic_cstring<CharT>::std_string const& s2, basic_cstring<CharT> const& s1 )
{
    return !(s1 == s2);
}

//____________________________________________________________________________//

// ************************************************************************** //
// **************                  first_char                  ************** //
// ************************************************************************** //

template<typename CharT>
inline typename basic_cstring<CharT>::value_ret_type
first_char( basic_cstring<CharT> source )
{
    typedef typename basic_cstring<CharT>::value_ret_type res_type;

    return source.is_empty() ? static_cast<res_type>(0) : *source.begin();
}

//____________________________________________________________________________//

// ************************************************************************** //
// **************                  last_char                   ************** //
// ************************************************************************** //

template<typename CharT>
inline typename basic_cstring<CharT>::value_ret_type
last_char( basic_cstring<CharT> source )
{
    typedef typename basic_cstring<CharT>::value_ret_type res_type;

    return source.is_empty() ? static_cast<res_type>(0) : *(source.end()-1);
}

//____________________________________________________________________________//

// ************************************************************************** //
// **************                  assign_op                   ************** //
// ************************************************************************** //

template<typename CharT1, typename CharT2>
inline void
assign_op( std::basic_string<CharT1>& target, basic_cstring<CharT2> src, int )
{
    target.assign( src.begin(), src.size() );
}

//____________________________________________________________________________//

template<typename CharT1, typename CharT2>
inline std::basic_string<CharT1>&
operator+=( std::basic_string<CharT1>& target, basic_cstring<CharT2> const& str )
{
    target.append( str.begin(), str.end() );
    return target;
}

//____________________________________________________________________________//

template<typename CharT1, typename CharT2>
inline std::basic_string<CharT1>
operator+( std::basic_string<CharT1> const& lhs, basic_cstring<CharT2> const& rhs )
{
    std::basic_string<CharT1> res( lhs );

    res.append( rhs.begin(), rhs.end() );
    return res;
}

//____________________________________________________________________________//

} // namespace unit_test

} // namespace boost

//____________________________________________________________________________//

#include <boost/test/detail/enable_warnings.hpp>

#endif // BOOST_TEST_UTILS_BASIC_CSTRING_HPP
