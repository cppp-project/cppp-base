/**
 * @file cppp/exception.hpp
 * @author ChenPi11
 * @brief C++ Plus base definitions
 * @version 0.0.1
 * @date 2023-7-21
 * @copyright Copyright (C) 2023 The C++ Plus Project
 */
/* Copyright (C) 1999-2023 Free Software Foundation, Inc.
   This file is part of the cppp-base library.

   The cppp-base library is free software; you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either version 3
   of the License, or (at your option) any later version.

   The cppp-base library is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the cppp-base library; see the file COPYING.
   If not, see <https://www.gnu.org/licenses/>.  */

/* We do not use '#pragma once' because it may has bugs in some compiler. */
#ifndef _CPPP_EXCPETION_HPP
#define _CPPP_EXCPETION_HPP

#include <cppp/basedef.hpp>
#include <cppp/string.hpp>
#include <exception>
namespace cppp
{
    class Exception : public std::exception
    {
    private:
        String _message;
    public:
        Exception(const String& message) : _message(message) {};
  
        const char* what() const noexcept override;

    };

#define CPPP_DEFINE_EASY_EXCEPTION(class_name, base_class) \
    class class_name : public base_class { public: using base_class::base_class; };

    /**
     * @brief Base class for lookup errors.
     */
    CPPP_DEFINE_EASY_EXCEPTION(LookupError, Exception);

        /**
         * @brief Sequence index out of range.
         */
        CPPP_DEFINE_EASY_EXCEPTION(IndexError, LookupError);

        /**
         * @brief Mapping key not found.
        */
        CPPP_DEFINE_EASY_EXCEPTION(KeyError, LookupError);

    /**
     * @brief Assertion failed.
     */
    CPPP_DEFINE_EASY_EXCEPTION(AssertionError, Exception);

    /**
     * @brief Program interrupted by user.
     */
    CPPP_DEFINE_EASY_EXCEPTION(KeyboardInterrupt, Exception);

    /**
     * @brief Out of memory.
     */
    CPPP_DEFINE_EASY_EXCEPTION(MemoryError, Exception);

    /**
     * @brief Iteration stopped.
     */
    CPPP_DEFINE_EASY_EXCEPTION(StopIteration, Exception);


}
/*
Errno (errno/winerror)
OSError
{
    strerror, errno, 
}
    IOError
        BlockingIOError
        {
            characters_written
        }
        EOFError
    ChildProcessError
    ConnectionError
        BrokenPipeError
        ConnectionAbortedError
        ConnectionRefusedError
        ConnectionResetError
    FileExistsError
    FileNotFoundError
    InterruptedError
    IsADirectoryError
    NotADirectoryError
    PermissionError
    ProcessLookupError
    TimeoutError

 UnicodeError UnicodeEncodeError UnicodeDecodeError UnicodeTranslateError ValueError
*/


/*WARNINGS
Warning
    DeprecationWarning
    UnicodeWarning
        EncodingWarning
*/

#endif
