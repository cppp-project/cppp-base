/**
 * @file cppp/string.hpp
 * @package cppp-base
 * @author ChenPi11
 * @brief C++ Plus String type definitions.
 * @version 0.0.1
 * @date 2023-08-26
 * @copyright Copyright (c) 2023 The C++ Plus Project
 */
/* Copyright (C) 2023 The C++ Plus Project.
   This file is part of the cppp-base library.

   The cppp-base library is free software; you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public
   License as published by the The C++ Plus Project; either version 3
   of the License, or (at your option) any later version.

   The cppp-base library is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the cppp-base library; see the file COPYING.
   If not, see <https://www.gnu.org/licenses/>.  */

#ifndef _CPPP_STRING_HPP
#define _CPPP_STRING_HPP

#include <cppp/basedef.hpp>
#include <cppp/messages.hpp>

#include <iostream>
#include <string_view>
#include <iterator>
#include <initializer_list>

namespace cppp
{
    // functions will not defined in WString: encode decode format format_map join ljust lstrip partition rpartition rjust rsplit rstrip split splitlines strip
    
    /**
     * @brief C++ Plus wide string type. (buffer with '\0' end)
     */
    class WString
    {
    public:
        /**
         * @typedef size_t
         * @brief Size type of WString.
         */
        using SizeType = size_t;

        /**
         * @typedef wchar_t
         * @brief Character type of WString.
         */
        using CharType = wchar_t;

        /**
         * @brief WString's null value.
         */
        static constexpr const SizeType npos = (SizeType)(-1);
    
    protected:
        /**
         * @brief WString's raw data.
         * @warning Direct operation may cause danger!
         */
        CharType* _raw_data = nullptr;

        /**
         * @brief WString's length.
         * @warning Direct operation may cause danger!
         */
        SizeType _length = 0;

        /**
         * @brief Allocated size.
         * @warning Direct operation may cause danger!
         */
        SizeType _allocated_size = 0;

        /**
         * @brief Default allocate size
         */
        constexpr const static SizeType DEFAULT_ALLOCATE_SIZE = 10;

        /**
         * @brief Update '_raw_data' buffer size and '_length' by the value of 'length'.
         * @param length New length.
         * @warning Direct operation may cause danger!
         * @note This function will change the string's length!
         */
        void _update_buffer_size(const SizeType& length);

    public:
        /**
         * @brief Create a null WString.
         * @throw MemoryError When allocation error.
         */
        WString();

        /**
         * @brief Create a WString from another WString.
         * @param string Another WString.
         * @throw MemoryError When allocate error.
         */
        WString(const WString& string);

        /**
         * @brief Create a WString from another WString.
         * @param string Another WString.
         * @throw MemoryError When allocation error.
         */
        WString(const WString&& string);

        /**
         * @brief Create a WString from a STL string.
         * @param string A STL string.
         * @throw MemoryError When allocation error.
         */
        WString(const std::basic_string<CharType>& string);

        /**
         * @brief Create a WString from a STL string view.
         * @param string A STL string view.
         * @throw MemoryError When allocation error.
         */
        WString(const std::basic_string_view<CharType>& string);

        /**
         * @brief Create a WString from a initializer list.
         * @param string A initializer list.
         * @throw MemoryError When allocation error.
         */
        WString(const std::initializer_list<CharType>& string);

        /**
         * @brief Create a WString from a array.
         * @param string A array.
         * @throw MemoryError When allocation error.
         */
        template<const SizeType& array_length>
        WString(const CharType (&array)[array_length]);

        /**
         * @brief Create a WString from a C string.
         * @param string A C string.
         * @throw MemoryError When allocation error.
         */
        WString(const CharType* const string);

        /**
         * @brief Create a WString from a buffer, WE WILL NOT COPY THE BUFFER!
         * @warning WE WILL NOT COPY THE BUFFER!
         * @param buffer The pointer of the buffer.
         * @param length Length of the buffer.
         */
        WString(CharType* buffer, const SizeType& length);

        /**
         * @brief Create a WString from a buffer.
         * @param begin Begin of the buffer.
         * @param end End of the buffer.
         * @throw MemoryError When allocation error.
         */
        WString(const CharType* begin, const CharType* end);

        /**
         * @brief Get item in S.
         * @param string Input string
         * @param index The index of the character to access.
         * @return Item.
         * @throw IndexError If 'index' is invalid.
         */
        static const CharType& at(const WString& string, SizeType& index);
        /**
         * @brief Get item in S.
         * @param index The index of the character to access.
         * @return Item.
         * @throw IndexError If 'index' is invalid.
         */
        const CharType& at(const SizeType& index) const;

        /**
         * @brief Capitalize the string.
         * @note More specifically, make the first character have upper case and the rest lower case.
         * @param string Input string.
         */
        static void capitalize(WString& string) noexcept;
        /**
         * @brief Return a capitalized version of this string.
         * @note More specifically, make the first character have upper case and the rest lower case.
         * @return Capitalized result.
         * @throw MemoryError When result string allocation error.
         */
        WString capitalize() const
        {
            WString result = (*this);
            WString::capitalize(result);
            return result;
        }

        /**
         * @brief Get capacity of the string.
         * @param string Input string.
         * @return Capacity.
         */
        static SizeType capacity(const WString& string) noexcept
        {
            return string._allocated_size;
        }
        /**
         * @brief Get capacity of the string.
         * @return Capacity.
         */
        constexpr SizeType capacity() const noexcept
        {
            return _allocated_size;
        }

        /**
         * @brief Center the string in a field of given width.
         * @note Padding is done using the specified fill character (default is a space).
         * @param string Input string.
         * @param width Width of the field.
         * @param fillchar Fill character.
         * @throw MemoryError When memory reallocation error.
         * @return Result.
         */
        static void center(WString& string, const SizeType& width, const CharType& fillchar=L' ');
        /**
         * @brief Return a copy of the string centered in a field of given width.
         * @note Padding is done using the specified fill character (default is a space).
         * @param width Width of the field.
         * @param fillchar Fill character.
         * @throw MemoryError When result string allocation error.
         * @return Result.
         */
        WString center(const SizeType& width, const CharType& fillchar=L' ') const
        {
            WString result = (*this);
            WString::center(result, width, fillchar);
            return result;
        }

        /**
         * @brief Return the number of non-overlapping occurrences of substring sub in string S[begin:end]. Optional arguments start and end are interpreted as in slice notation.
         * @param string Input string.
         * @param substr Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        static SizeType count(const WString& string, const WString& substr, const SizeType& begin=0, const SizeType& end=npos) noexcept;
        /**
         * @brief Return the number of non-overlapping occurrences of substring sub in string S[begin:end]. Optional arguments start and end are interpreted as in slice notation.
         * @param substr Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        SizeType count(const WString& substr, const SizeType& begin=0, const SizeType& end=npos) const noexcept
        {
            return WString::count((*this), substr, begin, end);
        }

        /**
         * @brief Return a read only C style string.
         * @param string Input string.
         * @return String pointer.
         */
        static const CharType* c_str(const WString& string) noexcept
        {
            return string.c_str();
        }
        /**
         * @brief Return a read only C style string.
         * @return String pointer.
         */
        constexpr const CharType* c_str() const noexcept
        {
            return _raw_data;
        }

        /**
         * @brief Return a copy of C++ style string.
         * @param string Input string.
         * @return String.
         * @throw std::bad_alloc
         */
        static const std::basic_string<CharType> cpp_str(const WString& string)
        {
            return string.cpp_str();
        }
        /**
         * @brief Return a copy of C++ style string.
         * @return String.
         * @throw std::bad_alloc 
         */
        const std::basic_string<CharType> cpp_str() const
        {
            return std::basic_string<CharType>(_raw_data, _length);
        }

        /**
         * @brief Return a copy of C++ string view.
         * @return String view.
         */
        const std::basic_string_view<CharType> cpp_strview() const
        {
            return std::basic_string_view<CharType>(_raw_data, _length);
        }

        /**
         * @brief Return true if S ends with the specified suffix, false otherwise.
         * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
         * @param string Input string.
         * @param suffix Suffix string.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        static Boolean endswith(const WString& string, const WString& suffix, const SizeType& begin=0, const SizeType& end=npos) noexcept;
        /**
         * @brief Return true if S ends with the specified suffix, false otherwise.
         * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
         * @param suffix Suffix string.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        Boolean endswith(const WString& suffix, const SizeType& begin=0, const SizeType& end=npos) const noexcept;

        /**
         * @brief Expand all tab characters using spaces.
         * @note If tabsize is not given, a tab size of 8 characters is assumed.
         * @param string Input string.
         * @param tabsize Space size.
         */
        static void expandtabs(WString& string, const SizeType& tabsize=8) noexcept;
        /**
         * @brief Return a copy where all tab characters are expanded using spaces.
         * @note If tabsize is not given, a tab size of 8 characters is assumed.
         * @param tabsize Space size.
         * @return Result.
         * @throw MemoryError When result string allocation error.
         */
        WString expandtabs(const SizeType& tabsize=8) const noexcept
        {
            WString result = (*this);
            WString::expandtabs(result, tabsize);
            return result;
        }

        /**
         * @brief Return the lowest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation. Return 'npos' on failure.
         * @param string Input string.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        static SizeType find(const WString& string,const WString& substring, const SizeType& begin=0, const SizeType& end=npos);
        /**
         * @brief Return the lowest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation. Return 'npos' on failure.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        SizeType find(const WString& substring, const SizeType& begin=0, const SizeType& end=npos)
        {
            return WString::find((*this), begin, end);
        }

        /**
         * @brief Determine if S contains a substring.
         * @param string Input string.
         * @param substring Substring.
         * @return Result.
         */
        static Boolean has(const WString& string, const WString& substring) noexcept;
        /**
         * @brief Determine if S contains a substring.
         * @param substring Substring.
         * @return Result.
         */
        Boolean has(const WString& substring) const noexcept;

        /**
         * @brief Return the lowest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation.
         * @param string Input string.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         * @throw ValueError when the substring is not found.
         */
        static SizeType index(const WString& string,const WString& substring, const SizeType& begin=0, const SizeType& end=npos);
        /**
         * @brief Return the lowest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         * @throw ValueError when the substring is not found.
         */
        SizeType index(const WString& substring, const SizeType& begin=0, const SizeType& end=npos) const
        {
            return WString::index((*this), begin, end);
        }
        
        /**
         * @brief Return true if the string is an alpha-numeric string, false otherwise.
         * @note A string is alpha-numeric if all characters in the string are alpha-numeric and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_alnum(const WString& string) noexcept;
        /**
         * @brief Return true if the string is an alpha-numeric string, false otherwise.
         * @note A string is alpha-numeric if all characters in the string are alpha-numeric and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_alnum() const noexcept
        {
            return WString::is_alnum((*this));
        }

        /**
         * @brief Return true if the string is an alphabetic string, false otherwise.
         * @note A string is alphabetic if all characters in the string are alphabetic and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_alpha(const WString& string) noexcept;
        /**
         * @brief Return true if the string is an alphabetic string, false otherwise.
         * @note A string is alphabetic if all characters in the string are alphabetic and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_alpha() const noexcept
        {
            return WString::is_alpha((*this));
        }

        /**
         * @brief Return true if all characters in the string are ASCII, false otherwise.
         * @note ASCII characters have code points in the range U+0000-U+007F. Empty string is ASCII too.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_ascii(const WString& string) noexcept;
        /**
         * @brief Return true if all characters in the string are ASCII, false otherwise.
         * @note ASCII characters have code points in the range U+0000-U+007F. Empty string is ASCII too.
         * @return Result.
         */
        Boolean is_ascii() const noexcept
        {
            return WString::is_ascii((*this));
        }

        /**
         * @brief Return true if the string is a decimal string, false otherwise.
         * @note A string is a decimal string if all characters in the string are decimal and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_decimal(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a decimal string, false otherwise.
         * @note A string is a decimal string if all characters in the string are decimal and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_decimal() const noexcept
        {
            return WString::is_decimal((*this));
        }

        /**
         * @brief Return true if the string is a digit string, false otherwise.
         * @note A string is a digit string if all characters in the string are digit and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_digit(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a digit string, false otherwise.
         * @note A string is a digit string if all characters in the string are digit and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_digit() const noexcept
        {
            return WString::is_digit((*this));
        }

        /**
         * @brief Return true if the string is a lower string, false otherwise.
         * @note A string is a lower string if all characters in the string are lower and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_lower(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a lower string, false otherwise.
         * @note A string is a lower string if all characters in the string are lower and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_lower() const noexcept
        {
            return WString::is_lower((*this));
        }

        /**
         * @brief Return true if the string is a numeric string, false otherwise.
         * @note A string is a numeric string if all characters in the string are numeric and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_numeric(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a numeric string, false otherwise.
         * @note A string is a numeric string if all characters in the string are numeric and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_numeric() const noexcept
        {
            return WString::is_numeric((*this));
        }

        /**
         * @brief Return true if the string is a printable string, false otherwise.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_printable(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a printable string, false otherwise.
         * @return Result.
         */
        Boolean is_printable() const noexcept
        {
            return WString::is_printable((*this));
        }

        /**
         * @brief Return true if the string is a whitespace string, false otherwise.
         * @note A string is a whitespace string if all characters in the string are whitespace and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_space(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a whitespace string, false otherwise.
         * @note A string is a whitespace string if all characters in the string are whitespace and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_space() const noexcept
        {
            return WString::is_space((*this));
        }

        /**
         * @brief Return true if the string is a title-cased string, false otherwise.
         * @note In a title-cased string, upper- and title-case characters may only follow uncased characters and lowercase characters only cased ones.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_title(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a title-cased string, false otherwise.
         * @note In a title-cased string, upper- and title-case characters may only follow uncased characters and lowercase characters only cased ones.
         * @return Result.
         */
        Boolean is_title() const noexcept
        {
            return WString::is_title((*this));
        }

        /**
         * @brief Return true if the string is a uppercase string, false otherwise.
         * @note A string is a uppercase string if all characters in the string are uppercase and there is at least one character in the string.
         * @param string Input string.
         * @return Result.
         */
        static Boolean is_upper(const WString& string) noexcept;
        /**
         * @brief Return true if the string is a uppercase string, false otherwise.
         * @note A string is a uppercase string if all characters in the string are uppercase and there is at least one character in the string.
         * @return Result.
         */
        Boolean is_upper() const noexcept
        {
            return WString::is_upper((*this));
        }

        /**
         * @brief Return the length of the string.
         * @param string Input string.
         * @return Length.
         */
        static SizeType length(const WString& string) noexcept
        {
            return string.length();
        }
        /**
         * @brief Return the length of the string.
         * @return Length.
         */
        constexpr SizeType length() const noexcept
        {
            return _length;
        }

        /**
         * @brief Convert the string to lowercase.
         * @param string Input string.
         */
        static void lower(WString& string) noexcept;
        /**
         * @brief Return a copy of the string converted to lowercase.
         * @return Result.
         * @throw 
         */
        WString lower() const
        {
            WString result = (*this);
            WString::lower(result);
            return result;
        }

        /**
         * @brief Return a str with the given suffix string removed if present.
         * @note If the string ends with the suffix string and that suffix is not empty, return string[:-len(suffix)]. Otherwise, return a copy of the original string.
         * @param string Input string.
         * @param suffix Suffix string.
         */
        static void removesuffix(WString& string, const WString& suffix) noexcept;

        /**
         * @brief Return a str with the given suffix string removed if present.
         * @note If the string ends with the suffix string and that suffix is not empty, return string[:-len(suffix)]. Otherwise, return a copy of the original string.
         * @param suffix Suffix string.
         * @return Result.
         * @throw MemoryError When allocation error.
         */
        WString removesuffix(const WString& suffix) const
        {
            WString result = (*this);
            WString::removesuffix(result, suffix);
            return result;
        }

        /**
         * @brief Repeat string.
         * @param string Input string.
         * @param time Repeat times.
         * @throw MemoryError When allocation error.
         */
        static void repeat(WString& string, const SizeType& time);
        /**
         * @brief Repeat string.
         * @param time Repeat times.
         * @throw MemoryError When allocation error.
         */
        WString repeat(const SizeType& time) const
        {
            WString result = (*this);
            WString::repeat(result, time);
            return result;
        }

        /**
         * @brief Replace all occurrences of substring 'from' by 'to'.
         * @param string Input string.
         * @param from From substring.
         * @param to To string.
         * @param count Maximum number of occurrences to replace. 'npos' (the default value) means replace all occurrences.
         */
        static void replace(WString& string, const WString& from, const WString to, const SizeType& count=npos) noexcept;
        /**
         * @brief Return a copy with all occurrences of substring old replaced by new.
         * @param from From substring.
         * @param to To string.
         * @param count Maximum number of occurrences to replace. 'npos' (the default value) means replace all occurrences.
         * @return Result.
         * @throw MemoryError When allocation error.
         */
        WString replace(const WString& from, const WString to, const SizeType& count=npos) const
        {
            WString result = (*this);
            WString::replace(result, from, to, count);
            return result;
        }
        
        /**
         * @brief Return the highest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation. Return 'npos' on failure.
         * @param string Input string.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        static SizeType rfind(const WString& string,const WString& substring, const SizeType& begin=0, const SizeType& end=npos);
        /**
         * @brief Return the highest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation. Return 'npos' on failure.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        SizeType rfind(const WString& substring, const SizeType& begin=0, const SizeType& end=npos)
        {
            return WString::rfind((*this), begin, end);
        }

        /**
         * @brief Return the highest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation.
         * @param string Input string.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         * @throw ValueError when the substring is not found.
         */
        static SizeType rindex(const WString& string,const WString& substring, const SizeType& begin=0, const SizeType& end=npos);
        /**
         * @brief Return the highest index in S where substring sub is found, such that sub is contained within S[begin:end].
         * @note Optional arguments start and end are interpreted as in slice notation.
         * @param substring Substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         * @throw ValueError when the substring is not found.
         */
        SizeType rindex(const WString& substring, const SizeType& begin=0, const SizeType& end=npos) const
        {
            return WString::rindex((*this), begin, end);
        }

        /**
         * @brief Return the length of the string.
         * @param string Input string.
         * @note Alias to 'S.length'.
         * @return Length.
         */
        static SizeType size(const WString& string) noexcept
        {
            return string.size();
        }
        /**
         * @brief Return the length of the string.
         * @note Alias to 'S.length'.
         * @return Length.
         */
        constexpr SizeType size() const noexcept
        {
            return length();
        }

        /**
         * @brief Return true if S starts with the specified prefix, false otherwise.
         * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
         * @param string Input string.
         * @param prefix Prefix substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         */
        static Boolean startswith(const WString& string, const WString& prefix, const SizeType& begin=0, const SizeType& end=npos) noexcept;
        /**
         * @brief Return true if S starts with the specified prefix, false otherwise.
         * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
         * @param prefix Prefix substring.
         * @param begin Begining position for search.
         * @param end End position for search.
         * @return Result.
         */
        Boolean startswith(const WString& prefix, const SizeType& begin=0, const SizeType& end=npos) const noexcept
        {
            return WString::startswith((*this), begin, end);
        }

        /**
         * @brief Convert the string to uppercase.
         * @param string Input string.
         */
        static void upper(WString& string) noexcept;
        /**
         * @brief Return a copy of the string converted to uppercase.
         * @return Result.
         * @throw MemoryError When result string allocation error.
         */
        WString upper() const
        {
            WString result = (*this);
            WString::upper(result);
            return result;
        }

        /**
         * @brief Pad a numeric string with zeros on the left, to fill a field of the given width.
         * @note The string is never truncated.
         * @param string Input string.
         * @param width Expected width.
         */
        static void zfill(WString& string, const SizeType& width) noexcept;
        /**
         * @brief Pad a numeric string with zeros on the left, to fill a field of the given width.
         * @note The string is never truncated.
         * @param width Expected width.
         * @return Result.
         * @throw MemoryError When result string allocation error.
         */
        WString zfill(const SizeType& width) const;

        // Operator definitions.

        /**
         * @brief Set string data.
         * @param string String.
         * @return Self.
         */
        WString& operator=(const WString& string);

        /**
         * @brief Set string data.
         * @param string String.
         * @return Self.
         */
        WString& operator=(const WString&& string);

        /**
         * @brief Concatenate string and return this copy.
         * @param string Another string.
         * @return Result.
         */
        WString operator+(const WString& string) const;

        /**
         * @brief Append string.
         * @param string Another string.
         * @return Self.
         * @throw MemoryError When allocation error.
         */
        WString& operator+=(const WString& string);

        /**
         * @brief Replace 'substring' to null and return this copy.
         * @param substring Substring you want to clear.
         * @return Result.
         */
        WString operator-(const WString& substring) const;
        /**
         * @brief Replace 'substring' to null.
         * @param substring Substring you want to clear.
         * @return Self.
         */
        WString& operator-=(const WString& substring);

        /**
         * @brief Repeat string and return this copy.
         * @note Alias to 'S.repeat'.
         * @param time Repeat time.
         * @return Result.
         */
        WString operator*(const SizeType& time) const;
        /**
         * @brief Repeat string.
         * @note Alias to 'S.repeat'.
         * @param time Repeat time.
         * @return Result.
         * @throw MemoryError When result string allocation error.
         */
        WString operator*=(const SizeType& time);

        /**
         * @brief Compare string.
         * @param string Another string.
         * @return Are two strings equal.
         */
        Boolean operator==(const WString& string) const noexcept;
        /**
         * @brief Compare string.
         * @param string Another string.
         * @return Are two strings not equal.
         */
        Boolean operator!=(const WString& string) const noexcept; 

        /**
         * @brief Compare string.
         * @param string Another string.
         * @return Result.
         */
        Boolean operator>(const WString& string) const noexcept;

        /**
         * @brief Compare string.
         * @param string Another string.
         * @return Result.
         */
        Boolean operator<(const WString& string) const noexcept;

        /**
         * @brief Get self[index]
         * @param index Index.
         * @return Result.
         * @throw IndexError If 'index' is invalid.
         */
        CharType operator[](const SizeType& index) const;

        /**
         * @brief Deconstruct this WString.
         */
        ~WString() noexcept;
    };

    /**
     * @brief C++ Plus string type. (buffer with '\0' end)
     */
    using String = WString;
}
#endif
