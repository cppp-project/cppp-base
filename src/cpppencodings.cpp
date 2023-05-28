/**
 * @file cpppencodings.cpp
 * @author ChenPi11
 * @copyright Copyright (C) 2023
 * @date 2023-5-28
 * @brief C++ Plus base library encoding support source.
 * @version 1.0.0
 * @link https://github.com/cppp-project/cppp-base/
 */
#include <cpppencodings.hpp>

#include <stddef.h>
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>
#include <cstring>

/* This is cppp-reiconv, not libiconv!!! see https://github.com/cppp-project/cppp-reiconv/ */
#include <iconv.h>

using namespace cppp;

c_int cppp::base::encoding::get_reiconv_version(void)
{
    return (c_int)::_libiconv_version;
}

iconv_t cppp::base::encoding::iconv_open(c_string* tocode, c_string* fromcode)
{
    return ::iconv_open((const char*)tocode, (const char*)fromcode);
}

c_size cppp::base::encoding::real_iconv(iconv_t cd, c_buffer* inbuf, c_size* inbytesleft, c_buffer* outbuf, c_size* outbytesleft)
{
    return (c_size)::iconv(cd, (const char**)inbuf, (size_t*)inbytesleft, (char**)outbuf, (size_t*)outbytesleft);
}

c_int cppp::base::encoding::iconv_close(iconv_t cd)
{
    return (c_int)::iconv_close(cd);
}

c_int cppp::base::encoding::iconv_string(c_string tocode, c_string fromcode, c_byte* start, c_byte* end, c_buffer* resultp, c_size* lengthp)
{
    c_int r=(c_int)::iconv_string((const char*)tocode, (const char*)fromcode, (const char*)start, (const char*)end, (char**)resultp, (size_t*) lengthp);
    return r;
}

c_int cppp::base::encoding::iconvctl(iconv_t cd, c_int request, c_pointer argument)
{
    return (c_int)::iconvctl(cd, (int)request, (void*)argument);
}

void cppp::base::encoding::iconvlist(cppp::c_int (*do_one)(cppp::c_uint namescount, const cppp::c_string *names, cppp::c_pointer data), cppp::c_pointer data)
{
    ::iconvlist((int(*)(unsigned int, const char* const*, void*))do_one, data);
}

c_string cppp::base::encoding::iconv_canonicalize(c_string name)
{
    return (c_string)::iconv_canonicalize((const char*)name);
}

c_string cppp::base::encoding::locale_charset(void)
{
    return (c_string)::locale_charset();
}

c_string _wchar_to_multi_byte(c_wstring wstr, c_size wlen)
{
    c_buffer mbstr = (c_buffer)malloc(wlen * sizeof(c_char) + 1);
    c_buffer pstr = mbstr;
    c_wbuffer pwstr = (c_wbuffer)wstr;
    for (c_size i = 0; i < wlen; i++)
    {
        *pstr++ = (c_char)(*pwstr++);
    }
    mbstr[wlen] = '\0';
    return (c_string)mbstr;
}

c_int cppp::base::encoding::decode(c_wstring encoding, c_buffer in, c_size in_size, c_wbuffer* out, c_size* out_length, c_bool strict)
{
    c_string fromcode = _wchar_to_multi_byte(encoding, wcslen(encoding));
    c_string to;
    if(strict)
    {
        to = CPPP_CMBTEXT("WCHAR_T");
    }
    else
    {
        to = CPPP_CMBTEXT("WCHAR_T//IGNORE");
    }
    *out = NULL;
    *out_length = 0;

    cppp::base::encoding::iconv_string(to, fromcode,
                    (c_byte*)in, (c_byte*)(in+in_size+1), (c_buffer*)out, out_length);
    *out_length/=sizeof(c_wchar);
    ::free((void*)fromcode);
    return errno;
}
c_int cppp::base::encoding::encode(c_wstring encoding, c_wbuffer in, c_size in_size, c_buffer *out, c_size *out_length, c_bool strict)
{
    c_string tocode = _wchar_to_multi_byte(encoding, wcslen(encoding));
    c_string to;
    if(!strict)
    {
        strncat((char*)tocode,"//IGNORE",sizeof("//IGNORE"));
    }
    *out = NULL;
    *out_length = 0;

    cppp::base::encoding::iconv_string(tocode, "WCHAR_T",
                    (c_byte*)in, (c_byte*)(in+in_size+1), (c_buffer*)out, out_length);
    ::free((void*)tocode);
    return errno;
}
