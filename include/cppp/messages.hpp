/**
 * @file cppp/messages.hpp
 * @package cppp-base
 * @author ChenPi11
 * @brief C++ Plus messages.
 * @version 0.0.1
 * @date 2023-8-20
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

#ifndef _CPPP_MESSAGES_HPP
#define _CPPP_MESSAGES_HPP

#include <cppp/basedef.hpp>

#include <iostream>
#include <string>

#define _CPPP_DEFINE_MESSAGE(name, message) constexpr const wchar_t* const name = L##message

namespace cppp
{
    namespace base
    {
        /**
         * @brief C++ Plus messages.
         */
        namespace messages
        {
            _CPPP_DEFINE_MESSAGE(ERROR_ALLOC_MEMORY, "Memory allocation failed.");
            _CPPP_DEFINE_MESSAGE(ERROR_REALLOC_MEMORY, "Memory reallocation failed.");
            _CPPP_DEFINE_MESSAGE(ERROR_INDEX_OUT_OF_RANGE, "Index out of range.");
            _CPPP_DEFINE_MESSAGE(ERROR_INDEX_OUT_OF_RANGE_MOREINFO, "(Index: %d, All: %d)");
        }
    }
}

#undef _CPPP_DEFINE_MESSAGE

#endif
