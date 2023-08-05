/**
 * @file cppp/string.hpp
 * @package cppp-base
 * @author ChenPi11
 * @brief C++ Plus String type definitions.
 * @version 0.0.1
 * @date 2023-7-21
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

#include <iostream>
#include <string_view>
#include <iterator>
#include <initializer_list>

namespace cppp
{
    namespace base
    {
        // functions will not defined in BasicString: center encode decode format format_map join ljust lstrip partition rpartition rjust rsplit rstrip split splitlines strip
        /**
         * @brief C++ Plus Basic String type.
         * @tparam CharType Type of charator in this string.
         */
        template<typename CharType>
        class BasicString
        {
        public:
            /**
             * @typedef size_t
             * @brief Size type for BasicString.
             */
            using SizeType = size_t;

            /**
             * @brief None position.
             */
            static SizeType npos = (SizeType)(-1);
        
        protected:
            /**
             * @brief BasicString's raw data.
             * @warning Direct operation may cause danger!
             */
            CharType* _raw_data;

            /**
             * @brief BasicString's length.
             * @warning Direct operation may cause danger!
             */
            SizeType _length;

        public:
            /**
             * @brief Create a null BasicString.
             * @throw MemoryError When allocation error.
             */
            BasicString() = default;

            /**
             * @brief Create a BasicString from another BasicString.
             * @param string Another BasicString.
             * @throw MemoryError When allocate error.
             */
            BasicString(const BasicString& string);

            /**
             * @brief Create a BasicString from a STL string.
             * @param string A STL string.
             * @throw MemoryError When allocation error.
             */
            BasicString(const std::basic_string<CharType>& string);

            /**
             * @brief Create a BasicString from a STL string view.
             * @param string A STL string view.
             * @throw MemoryError When allocation error.
             */
            BasicString(const std::basic_string_view<CharType>& string);

            /**
             * @brief Create a BasicString from a initializer list.
             * @param string A initializer list.
             * @throw MemoryError When allocation error.
             */
            BasicString(const std::initializer_list<CharType>& string);

            /**
             * @brief Create a BasicString from a array.
             * @param string A array.
             * @throw MemoryError When allocation error.
             */
            template<const SizeType& array_length>
            BasicString(const CharType (&array)[array_length]);

            /**
             * @brief Create a BasicString from a C string.
             * @param string A C string.
             * @throw MemoryError When allocation error.
             */
            BasicString(const CharType* string);

            /**
             * @brief Create a BasicString from a buffer, WE WILL NOT COPY THE BUFFER!
             * @warning WE WILL NOT COPY THE BUFFER!
             * @param buffer The pointer of the buffer.
             * @param length Length of the buffer.
             */
            BasicString(CharType* buffer, const SizeType& length);

            /**
             * @brief Create a BasicString from a buffer.
             * @param begin Begin of the buffer.
             * @param end End of the buffer.
             * @throw MemoryError When allocation error.
             */
            BasicString(const CharType* begin, const CharType* end);

            /**
             * @brief Capitalize the string.
             * @note More specifically, make the first character have upper case and the rest lower case.
             * @param string Input string.
             */
            static void capitalize(BasicString& string) noexcept;
            /**
             * @brief Return a capitalized version of this string.
             * @note More specifically, make the first character have upper case and the rest lower case.
             * @return Capitalized result.
             * @throw MemoryError when result string allocation error.
             */
            BasicString capitalize() const
            {
                BasicString result = (*this);
                BasicString::capitalize(result);
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
            static SizeType count(const BasicString& string, const BasicString& substr, const SizeType& begin=0, const SizeType& end=npos) noexcept;
            /**
             * @brief Return the number of non-overlapping occurrences of substring sub in string S[begin:end]. Optional arguments start and end are interpreted as in slice notation.
             * @param substr Substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             */
            SizeType count(const BasicString& substr, const SizeType& begin=0, const SizeType& end=npos) const noexcept
            {
                return BasicString::count((*this), substr, begin, end);
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
            static Boolean endswith(const BasicString& string, const BasicString& suffix, const SizeType& begin=0, const SizeType& end=npos) noexcept;
            /**
             * @brief Return true if S ends with the specified suffix, false otherwise.
             * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
             * @param suffix Suffix string.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             */
            Boolean endswith(const BasicString& suffix, const SizeType& begin=0, const SizeType& end=npos) const noexcept;

            /**
             * @brief Expand all tab characters using spaces.
             * @note If tabsize is not given, a tab size of 8 characters is assumed.
             * @param string Input string.
             * @param tabsize Space size.
             */
            static void expandtabs(BasicString& string, const SizeType& tabsize=8) noexcept;
            /**
             * @brief Return a copy where all tab characters are expanded using spaces.
             * @note If tabsize is not given, a tab size of 8 characters is assumed.
             * @param tabsize Space size.
             * @return Result.
             * @throw MemoryError when result string allocation error.
             */
            BasicString expandtabs(const SizeType& tabsize=8) const noexcept
            {
                BasicString result = (*this);
                BasicString::expandtabs(result, tabsize);
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
            static SizeType find(const BasicString& string,const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos);
            /**
             * @brief Return the lowest index in S where substring sub is found, such that sub is contained within S[begin:end].
             * @note Optional arguments start and end are interpreted as in slice notation. Return 'npos' on failure.
             * @param substring Substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             */
            SizeType find(const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos)
            {
                return BasicString::find((*this), begin, end);
            }

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
            static SizeType index(const BasicString& string,const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos);
            /**
             * @brief Return the lowest index in S where substring sub is found, such that sub is contained within S[begin:end].
             * @note Optional arguments start and end are interpreted as in slice notation.
             * @param substring Substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             * @throw ValueError when the substring is not found.
             */
            SizeType index(const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos) const
            {
                return BasicString::index((*this), begin, end);
            }
            
            /**
             * @brief Return true if the string is an alpha-numeric string, false otherwise.
             * @note A string is alpha-numeric if all characters in the string are alpha-numeric and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_alnum(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is an alpha-numeric string, false otherwise.
             * @note A string is alpha-numeric if all characters in the string are alpha-numeric and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_alnum() const noexcept;
            {
                return BasicString::is_alnum((*this));
            }

            /**
             * @brief Return true if the string is an alphabetic string, false otherwise.
             * @note A string is alphabetic if all characters in the string are alphabetic and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_alpha(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is an alphabetic string, false otherwise.
             * @note A string is alphabetic if all characters in the string are alphabetic and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_alpha() const noexcept;
            {
                return BasicString::is_alpha((*this));
            }

            /**
             * @brief Return true if all characters in the string are ASCII, false otherwise.
             * @note ASCII characters have code points in the range U+0000-U+007F. Empty string is ASCII too.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_ascii(const BasicString& string) noexcept;
            /**
             * @brief Return true if all characters in the string are ASCII, false otherwise.
             * @note ASCII characters have code points in the range U+0000-U+007F. Empty string is ASCII too.
             * @return Result.
             */
            Boolean is_ascii() const noexcept;
            {
                return BasicString::is_ascii((*this));
            }

            /**
             * @brief Return true if the string is a decimal string, false otherwise.
             * @note A string is a decimal string if all characters in the string are decimal and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_decimal(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a decimal string, false otherwise.
             * @note A string is a decimal string if all characters in the string are decimal and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_decimal() const noexcept;
            {
                return BasicString::is_decimal((*this));
            }

            /**
             * @brief Return true if the string is a digit string, false otherwise.
             * @note A string is a digit string if all characters in the string are digit and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_digit(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a digit string, false otherwise.
             * @note A string is a digit string if all characters in the string are digit and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_digit() const noexcept;
            {
                return BasicString::is_digit((*this));
            }

            /**
             * @brief Return true if the string is a lower string, false otherwise.
             * @note A string is a lower string if all characters in the string are lower and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_lower(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a lower string, false otherwise.
             * @note A string is a lower string if all characters in the string are lower and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_lower() const noexcept;
            {
                return BasicString::is_lower((*this));
            }

            /**
             * @brief Return true if the string is a numeric string, false otherwise.
             * @note A string is a numeric string if all characters in the string are numeric and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_numeric(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a numeric string, false otherwise.
             * @note A string is a numeric string if all characters in the string are numeric and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_numeric() const noexcept;
            {
                return BasicString::is_numeric((*this));
            }

            /**
             * @brief Return true if the string is a printable string, false otherwise.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_printable(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a printable string, false otherwise.
             * @return Result.
             */
            Boolean is_printable() const noexcept;
            {
                return BasicString::is_printable((*this));
            }

            /**
             * @brief Return true if the string is a whitespace string, false otherwise.
             * @note A string is a whitespace string if all characters in the string are whitespace and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_space(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a whitespace string, false otherwise.
             * @note A string is a whitespace string if all characters in the string are whitespace and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_space() const noexcept;
            {
                return BasicString::is_space((*this));
            }

            /**
             * @brief Return true if the string is a title-cased string, false otherwise.
             * @note In a title-cased string, upper- and title-case characters may only follow uncased characters and lowercase characters only cased ones.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_title(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a title-cased string, false otherwise.
             * @note In a title-cased string, upper- and title-case characters may only follow uncased characters and lowercase characters only cased ones.
             * @return Result.
             */
            Boolean is_title() const noexcept;
            {
                return BasicString::is_title((*this));
            }

            /**
             * @brief Return true if the string is a uppercase string, false otherwise.
             * @note A string is a uppercase string if all characters in the string are uppercase and there is at least one character in the string.
             * @param string Input string.
             * @return Result.
             */
            static Boolean is_upper(const BasicString& string) noexcept;
            /**
             * @brief Return true if the string is a uppercase string, false otherwise.
             * @note A string is a uppercase string if all characters in the string are uppercase and there is at least one character in the string.
             * @return Result.
             */
            Boolean is_upper() const noexcept;
            {
                return BasicString::is_upper((*this));
            }

            /**
             * @brief Convert the string to lowercase.
             * @param string Input string.
             */
            static void lower(BasicString& string) noexcept;
            /**
             * @brief Return a copy of the string converted to lowercase.
             * @return Result.
             * @throw 
             */
            BasicString lower() const
            {
                BasicString result = (*this);
                BasicString::lower(result);
                return result;
            }

            /**
             * @brief Return a str with the given suffix string removed if present.
             * @note If the string ends with the suffix string and that suffix is not empty, return string[:-len(suffix)]. Otherwise, return a copy of the original string.
             * @param string Input string.
             * @param suffix Suffix string.
             */
            static void removesuffix(BasicString& string, const BasicString& suffix) noexcept;

            /**
             * @brief Return a str with the given suffix string removed if present.
             * @note If the string ends with the suffix string and that suffix is not empty, return string[:-len(suffix)]. Otherwise, return a copy of the original string.
             * @param suffix Suffix string.
             * @return Result.
             * @throw MemoryError When allocation error.
             */
            BasicString removesuffix(const BasicString& suffix) const
            {
                BasicString result = (*this);
                BasicString::removesuffix(result, suffix);
                return result;
            }

            /**
             * @brief Replace all occurrences of substring 'from' by 'to'.
             * @param string Input string.
             * @param from From substring.
             * @param to To string.
             * @param count Maximum number of occurrences to replace. 'npos' (the default value) means replace all occurrences.
             */
            static void replace(BasicString& string, const BasicString& from, const BasicString to, const SizeType& count=npos) noexcept;
            /**
             * @brief Return a copy with all occurrences of substring old replaced by new.
             * @param from From substring.
             * @param to To string.
             * @param count Maximum number of occurrences to replace. 'npos' (the default value) means replace all occurrences.
             * @return Result.
             * @throw MemoryError When allocation error.
             */
            BasicString replace(const BasicString& from, const BasicString to, const SizeType& count=npos) const
            {
                BasicString result;
                BasicString::replace((*this), from, to, count);
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
            static SizeType rfind(const BasicString& string,const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos);
            /**
             * @brief Return the highest index in S where substring sub is found, such that sub is contained within S[begin:end].
             * @note Optional arguments start and end are interpreted as in slice notation. Return 'npos' on failure.
             * @param substring Substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             */
            SizeType rfind(const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos)
            {
                return BasicString::rfind((*this), begin, end);
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
            static SizeType rindex(const BasicString& string,const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos);
            /**
             * @brief Return the highest index in S where substring sub is found, such that sub is contained within S[begin:end].
             * @note Optional arguments start and end are interpreted as in slice notation.
             * @param substring Substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             * @throw ValueError when the substring is not found.
             */
            SizeType rindex(const BasicString& substring, const SizeType& begin=0, const SizeType& end=npos) const
            {
                return BasicString::rindex((*this), begin, end);
            }

            /**
             * @brief Return true if S starts with the specified prefix, false otherwise.
             * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
             * @param string Input string.
             * @param prefix Prefix substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             */
            static Boolean startswith(const BasicString& string, const BasicString& prefix, const SizeType& begin=0, const SizeType& end=npos) noexcept;
            /**
             * @brief Return true if S starts with the specified prefix, false otherwise.
             * @note With optional start, test S beginning at that position. With optional end, stop comparing S at that position.
             * @param prefix Prefix substring.
             * @param begin Begining position for search.
             * @param end End position for search.
             * @return Result.
             */
            Boolean startswith(const BasicString& prefix, const SizeType& begin=0, const SizeType& end=npos) const noexcept
            {
                return BasicString::startswith((*this), begin, end);
            }

            /**
             * @brief Convert the string to uppercase.
             * @param string Input string.
             */
            static void upper(BasicString& string) noexcept;
            /**
             * @brief Return a copy of the string converted to uppercase.
             * @return Result.
             * @throw MemoryError when result string allocation error.
             */
            BasicString upper() const
            {
                BasicString result = (*this);
                BasicString::upper(result);
                return result;
            }

            /**
             * @brief Pad a numeric string with zeros on the left, to fill a field of the given width.
             * @note The string is never truncated.
             * @param string Input string.
             * @param width Expected width.
             */
            static void zfill(BasicString& string, const SizeType& width) noexcept;
            /**
             * @brief Pad a numeric string with zeros on the left, to fill a field of the given width.
             * @note The string is never truncated.
             * @param width Expected width.
             * @return Result.
             * @throw MemoryError when result string allocation error.
             */
            BasicString zfill(const SizeType& width) const;

            /**
             * @brief Deconstruct this BasicString.
             */
            ~BasicString() noexcept;
        };
    }

}
#endif
