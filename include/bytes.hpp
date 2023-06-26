/**
 * @file bytes.hpp
 * @author ChenPi11
 * @copyright Copyright (C) 2023
 * @date 2023-5-28
 * @brief C++ Plus Bytes class defines
 * @version 1.0.0
 * @link https://github.com/cppp-project/cppp-base/
 */
#ifndef _CPPP_BASE_BYTES_HPP_
#define _CPPP_BASE_BYTES_HPP_

#include "cpppencodings.hpp"
#include "mincpppdef.hpp"
#include "memory.hpp"
#include <initializer_list>
#include <vector>

namespace cppp{namespace base{
namespace types
{
    /* Requirements predefine */
    class String;

    template<typename Type>
    class Iterable;

    //base::Bytes@0
    class Bytes
    {
    protected:
    public:
    
        //base::npos@0
        static constexpr const c_size npos = (c_size)(-1);

        /**
         * @date 2023-5-28
         * @brief Create a null bytes object.
         */
        Bytes() = default;

        /**
         * @date 2023-5-28
         * @brief Create a bytes object from another Bytes.
         * @param src source bytes
         * @throw MemoryError
         */
        Bytes(const Bytes& src);

        /**
         * @date 2023-5-28
         * @brief Create a bytes object from C++ initializer_list.
         * @param src source array
         * @throw MemoryError
         */
        Bytes(const std::initializer_list<c_byte>& src);

        /**
         * @date 2023-5-28
         * @brief Create a Bytes object from data.
         * @param src souce data
         * @param length data length
         * @throw MemoryError
         */
        Bytes(const c_byte* src, c_size length);

        /**
         * @date 2023-5-28
         * @brief Create a Bytes object of specified length.
         * @param size bytes length
         * @throw MemoryError
         */
        Bytes(c_size size);

        /**
         * @date 2023-5-28
         * @brief Create a Bytes object from array.
         * @param array source array
         * @param array_length array length (template)
         * @throw MemoryError
         */
        template<c_size array_length>
        Bytes(const char(&array)[array_length]);

        /**
         * @date 2023-5-28
         * @brief Create a bytes object of specified length and value.
         * @param init_value initialized value
         * @param bytes_length Initialized length
         * @throw MemoryError
         */
        Bytes(const c_byte init_value, c_size bytes_length);

        /**
         * @date 2023-5-28
         * @brief Return the byte corresponding to the index.
         * @param index value index
         * @return reference to value
         * @throw IndexError
         */
        constexpr c_byte& at(c_size index) const;

        /**
         * @date 2023-5-28
         * @brief get writable data pointer.
         * @return data pointer
         * @warning this function is dangerous, we do not recommend directly manipulating internal data!
         */
        constexpr c_byte* data(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief get bytes length.
         * @return length
         */
        constexpr c_size length(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief get bytes length.
         * @return length
         * @see Bytes::length
         */
        constexpr c_size size(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return a copy of bytes with only its first character capitalized (ASCII) and the rest lower-cased.
         * @return a copy of bytes
         * @throw MemoryError
         */
        Bytes capitalize(void) const noexcept;
        
        /**
         * @date 2023-5-28
         * @brief Return a centered string of length width. Padding is done using the specified fill character.
         * @param width the length you want
         * @param fillchar fill byte
         * @return a copy of bytes
         * @throw MemoryError
         */
        Bytes center(c_size width, c_byte fillchar=(c_byte)' ') const noexcept;

        /**
         * @date 2023-5-28
         * @brief Counts the number of times a subbytes appears in the parent bytes.
         * @param sub sub bytes
         * @return count result
         */
        c_size count(const Bytes& sub) const noexcept;
        
        /**
         * @date 2023-5-28
         * @brief Decode the bytes using the codec registered for encoding.
         * @param encoding The encoding with which to decode the bytes
         * @param strict Is strict decode mode
         * @return a string object
         * @see https://github.com/cppp-project/cppp-reiconv/
         * @throw MemoryError
         * @throw UnicodeDecodeError
         */
        String decode(const String& encoding = L"utf-8", c_bool strict = true) const;
        
        /**
         * @date 2023-5-28
         * @brief Return true if bytes ends with the specified suffix, false otherwise. With optional start, test bytes beginning at that position. With optional end, stop comparing bytes at that position. Suffix can also be a tuple of bytes to try.
         * @param sub subytes
         * @return test result
         */
        constexpr c_bool endswith(const Bytes& sub) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Extend bytes by appending elements from another bytes.
         * @param bytes another bytes
         * @throw MemoryError
         */
        void extend(const Bytes& bytes);
        
        /**
         * @date 2023-5-28
         * @brief Return a copy where all tab characters are expanded using spaces. If tabsize is not given, a tab size of 8 characters is assumed.
         * @param tabs count
         * @return a copy of bytes
         * @throw MemoryError
         */
        Bytes expandtabs(c_size tabs = 8) const;

        /**
         * @date 2023-5-28
         * @brief Return the lowest index in bytes where subsection sub is found, such that sub is contained within bytes. Optional arguments start and end are interpreted as in slice notation. Return Bytes::npos on failure.
         * @param sub subbytes
         * @param offet offset
         * @return index
         */
        c_size find(const Bytes& sub, c_size offset = 0) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if all characters in bytes are alphanumeric and there is at least one character in bytes, false otherwise.
         * @return result
         */
        c_bool is_alnum(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if all characters in bytes are alphabetic and there is at least one character in bytes, false otherwise.
         * @return result
         */
        c_bool is_alpha(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if bytes is empty or all characters in bytes are ASCII, false otherwise.
         * @return result
         */
        c_bool is_ascii(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if all characters in bytes are digits and there is at least one character in bytes, false otherwise.
         * @return result
         */
        c_bool is_digit(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if all cased characters in bytes are lowercase and there is at least one cased character in bytes, false otherwise.
         * @return result
         */
        c_bool is_lower(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if all characters in bytes are whitespace and there is at least one character in bytes, false otherwise.
         * @return result
         */
        c_bool is_space(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Return true if all cased characters in bytes are uppercase and there is at least one cased character in bytes, false otherwise.
         * @return result
         */
        c_bool is_upper(void) const noexcept;

        /**
         * @date 2023-5-28
         * @brief Concatenate any number of bytes objects. The bytes whose method is called is inserted in between each pair. The result is returned as a new bytes object.
         * @return a new bytes object
         * @throw MemoryError
         */
        Bytes join(Iterable<cppp::c_byte> iterable) const;

        /**
         * @date 2023-5-28
         * @brief Return a left-justified string of length width. Padding is done using the specified fill character.
         * @param width the length you want
         * @param fillchar fill byte
         * @return result
         * @throw MemoryError
         */
        Bytes ljust(c_size width,c_byte fillchar=(c_byte)' ') const;

        /**
         * @date 2023-5-28
         * @brief Return a right-justified string of length width. Padding is done using the specified fill character.
         * @param width the length you want
         * @param fillchar fill byte
         * @return result
         * @throw MemoryError
         */
        Bytes rjust(c_size width,c_byte fillchar=(c_byte)' ') const;

        /**
         * @date 2023-5-28
         * @brief get a copy of subbytes
         * @param begin begin index
         * @param end end index
         * @return a copy of subbytes 
         */
        Bytes sub(c_size begin = 0, c_size end = npos) const;

        /**
         * @date 2023-5-28
         * @brief Return a copy with all occurrences of substring old replaced by new. If the optional argument count is given, only the first count occurrences are replaced.
         * @param from from bytes
         * @param to to bytes
         * @param count Maximum number of occurrences to replace. npos (the default value) means replace all occurrences.
         * @return a copy of bytes
         * @throw MemoryError
         */
        Bytes replace(const Bytes& from, const Bytes& to,c_size count = npos) const;

        /**
         * @date 2023-5-28
         * @brief Return the canonical string representation of bytes.
         * @return bytes repr
         * @throw MemoryError
         */
        String repr(void) const;

        /* C++ STL std::string like methods */

        /**
         * @date 2023-5-28
         * @brief Set value to contents of another string.
         * @param src source string to use.
         */
        void assign(c_wstring src) noexcept;

        /**
         * @date 2023-5-28
         * @brief Return a C++ style copy of bytes.
         * @return a copy of bytes
         */
        std::vector<cppp::c_byte> cpp_bytes(void) const;

        /**
         * @date 2023-5-28
         * @brief free a bytes object
         */
        ~Bytes(void) noexcept;
    };

} /* namespace types */
}}
#endif
//repr,mfcsupport,operators