/**
 * @file cpppencodings.hpp
 * @author ChenPi11
 * @copyright Copyright (C) 2023
 * @date 2023-5-28
 * @brief C++ Plus base library encoding support.
 * @version 1.0.0
 * @link https://github.com/cppp-project/cppp-base/
 */
#ifndef _CPPP_ENCODINGS_HPP_
#define _CPPP_ENCODINGS_HPP_

#include "mincpppdef.hpp"

namespace cppp{namespace base{
namespace encoding
{
    /* Reiconv wrappers */
    /* Define iconv_t ourselves. */
    #undef iconv_t
    /* Iconv handle */
    typedef c_pointer iconv_t;

    #undef get_reiconv_version
    /* Get cppp-reiconv version */
    extern c_int get_reiconv_version(void);

    #undef iconv_open
    /* Open iconv handle */
    extern iconv_t iconv_open(c_string* tocode, c_string* fromcode);

    #undef real_iconv
    /* Iconv function */
    extern c_size real_iconv(iconv_t cd, c_buffer* inbuf, c_size* inbytesleft, c_buffer* outbuf, c_size* outbytesleft);

    #undef iconv_close
    /* Close iconv handle */
    extern c_int iconv_close(iconv_t cd);

    #undef iconv_string
    /* Iconv string function */
    extern c_int iconv_string(c_string tocode, c_string fromcode, c_byte* start, c_byte* end, c_buffer* resultp, c_size* lengthp);

    #undef iconvctl
    /* Iconv control function */
    extern c_int iconvctl(iconv_t cd, c_int request, c_pointer argument);

    #undef iconvlist
    /* Listing of locale independent encodings */
    extern void iconvlist(c_int (*do_one)(c_uint namescount,
                                    c_string const * names,
                                    c_pointer data),
                    c_pointer data);

    #undef iconv_canonicalize
    /* Canonicalize an encoding name */
    extern c_string iconv_canonicalize(c_string name);
    
    #undef locale_charset
    /* Determine the current locale's character encoding, and canonicalize it into one of the canonical names listed below. */
    extern c_string locale_charset(void);

    /* Iconv flag defines */
    #undef ICONV_SURFACE_NONE
    /* Surfaces.
        The concept of surfaces is described in the 'recode' manual.  */
    constexpr const c_int ICONV_SURFACE_NONE = 0;

    #undef ICONV_SURFACE_EBCDIC_ZOS_UNIX
    /* In EBCDIC encodings, 0x15 (which encodes the "newline function", see the
        Unicode standard, chapter 5) maps to U+000A instead of U+0085.  This is
        for interoperability with C programs and Unix environments on z/OS.  */
    constexpr const c_int ICONV_SURFACE_EBCDIC_ZOS_UNIX = 1;

    /* Requests for iconvctl. */
    #undef ICONV_TRIVIALP
    /* int *argument */
    constexpr const c_int ICONV_TRIVIALP = 0; 

    #undef ICONV_GET_TRANSLITERATE
    /* int *argument */
    constexpr const c_int ICONV_GET_TRANSLITERATE = 1;

    #undef ICONV_SET_TRANSLITERATE
    /* const int *argument */
    constexpr const c_int ICONV_SET_TRANSLITERATE = 2;

    #undef ICONV_GET_DISCARD_ILSEQ
    /* int *argument */
    constexpr const c_int ICONV_GET_DISCARD_ILSEQ = 3;

    #undef ICONV_SET_DISCARD_ILSEQ
    /* const int *argument */
    constexpr const c_int ICONV_SET_DISCARD_ILSEQ = 4;

    #undef ICONV_SET_HOOKS
    /* const struct iconv_hooks *argument */
    constexpr const c_int ICONV_SET_HOOKS = 5;

    #undef ICONV_SET_FALLBACKS
    /* const struct iconv_fallbacks *argument */
    constexpr const c_int ICONV_SET_FALLBACKS = 6;

    #undef ICONV_GET_FROM_SURFACE
    /* unsigned int *argument */
    constexpr const c_int ICONV_GET_FROM_SURFACE = 7;

    #undef ICONV_SET_FROM_SURFACE
    /* const unsigned int *argument */
    constexpr const c_int ICONV_SET_FROM_SURFACE = 8;

    #undef ICONV_GET_TO_SURFACE
    /* unsigned int *argument */
    constexpr const c_int ICONV_GET_TO_SURFACE = 9;

    #undef ICONV_SET_TO_SURFACE
    /* const unsigned int *argument */
    constexpr const c_int ICONV_SET_TO_SURFACE = 10;

    /* C++ Plus encoding functions */
    /* decode multi-bytes string to wide-string */
    extern c_int decode(c_wstring encoding, c_buffer in, c_size in_size, c_wbuffer* out, c_size* out_length, c_bool strict);

    /* encode wide-string to multi-bytes string */
    extern c_int encode(c_wstring encoding, c_wbuffer in, c_size in_size, c_buffer* out, c_size* out_length, c_bool strict);

} /* namespace encoding */
}}
#endif