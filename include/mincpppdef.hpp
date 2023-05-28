/**
 * @file mincpppdef.hpp
 * @author ChenPi11
 * @copyright Copyright (C) 2023
 * @date 2023-5-28
 * @brief C++ Plus base library minimal defines
 * @version 1.0.0
 * @link https://github.com/cppp-project/cppp-base/
 */
#ifndef _MIN_CPPP_DEFINES_HPP_
#define _MIN_CPPP_DEFINES_HPP_

#include <stddef.h>
#include <iostream>

#include "platform_predef.h"

/* C++ Plus main namespace */
namespace cppp
{
    /* C++ Plus type defines */
    typedef             bool        c_bool;
    typedef             char        c_char;
    typedef unsigned    char        c_byte;
    typedef signed      short       c_short;
    typedef unsigned    short       c_ushort;
    typedef             wchar_t     c_wchar;
    typedef signed      int         c_int;
    typedef unsigned    int         c_uint;
    typedef signed      long long   c_llong;
    typedef unsigned    long long   c_ullong;
    typedef             float       c_float;
    typedef             double      c_double;
    typedef             long double c_ldouble;
    typedef             void*       c_pointer;
    /* Different platform may have diffect size_t */
    typedef             size_t      c_size;

    /* Other type defines */
#if __has_cpp20__
    typedef char8_t        c_char8;
#else
    typedef c_char         c_char8;
#endif
#if __has_cpp11__
    typedef char16_t       c_char16;
    typedef char32_t       c_char32;
#else
    typedef c_wchar        c_char16;
    typedef c_uint         c_char32;
#endif
    typedef const c_char*    c_string;
    typedef const c_wchar*   c_wstring;
    typedef const c_char8*   c_u8string;
    typedef const c_char16*  c_u16string;
    typedef const c_char32*  c_u32string;
    typedef c_byte*          c_buffer;
    typedef c_wchar*         c_wbuffer;

    /* C++ Plus base functions */
    namespace base
    {
        
    } /* namespace base */

    /* C++ Plus base types */
    namespace types
    {

    } /* namespace types */

    /* C++ Plus builtins module */
    namespace builtins
    {

    } /* namespace builtins */
    
} /* namespace cppp */

#undef CPPP_CTEXT
#define CPPP_CTEXT(quote) (c_wstring)(L ## quote)

#undef CPPP_CMBTEXT
#define CPPP_CMBTEXT(quote) (c_string)(quote)

#endif