/**
 * @file cppp/basedef.hpp
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
#ifndef _CPPP_BASE_HPP
#define _CPPP_BASE_HPP

/* Include C and C++ base definitions,
   we can use some type in it like 'size_t'. */
#include <cstddef>
#include <stddef.h>

/* C++ Plus base namespace,
   This namespace include all things in C++ Plus base library. */
namespace cppp
{
   /* C++ Plus types */
   template<typename Type>
   class Iterator;
   class Bytes;
   typedef bool Boolean;
   /* C++ Plus basic functions and apis is in here. */
   namespace base
   {
      /**
       * @brief C++ Plus Basic String type.
       * @tparam CharType Type of charator in this string.
       */
      template<typename CharType>
      class BasicString;
   } // namespace base

} // namespace cppp

#endif
