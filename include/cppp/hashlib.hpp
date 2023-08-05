/**
 * @file cppp/hashlib.hpp
 * @package cppp-base
 * @author ChenPi11
 * @brief C++ Plus hash utils.
 * @version 0.0.1
 * @date 2023-7-29
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

#ifndef _CPPP_HASHLIB_HPP
#define _CPPP_HASHLIB_HPP

#include <cppp/basedef.hpp>

#include <iostream>
#include <string>

namespace cppp
{
    namespace base
    {
        
        /**
         * @brief Get a object's hash value.
         * @tparam Object type.
         */
        template<typename T>
        size_t get_hash(const T& object)
        {
            std::hash<std::string> h;
            return h(object);
        }
    }
}
#endif
