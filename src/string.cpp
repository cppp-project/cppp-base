/**
 * @file string.cpp
 * @package cppp-base
 * @author ChenPi11
 * @brief C++ Plus String type implementation.
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

#include "cppp/exception.hpp"
#include "cppp/messages.hpp"
#include <cppp/string.hpp>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace cppp;

/*
1. The minimum increment or decrement unit length for each allocation operation is 'DEFAULT_ALLOCATE_SIZE'.
2. Each allocation operation ensures that the allocated '_allocated_size' is divisible by 'DEFAULT_ALLOCATE_SIZE'.
3. Each allocation operation ensures that the allocated '_allocated_size' is greater than or equal to 'length'.
4. The length of allocation is determined based on 'length'.
*/
void WString::_update_buffer_size(const SizeType& length)
{
    CharType* new_buffer = nullptr;
    SizeType new_size = (length / DEFAULT_ALLOCATE_SIZE + (SizeType)(bool)(length % DEFAULT_ALLOCATE_SIZE)) * DEFAULT_ALLOCATE_SIZE;
    if(new_size == 0)
    {
        free(_raw_data);
        goto end;
    }
    new_buffer = (CharType*)realloc(_raw_data, new_size * sizeof(CharType));
    if (new_buffer == nullptr)
    {
        throw MemoryError(base::messages::ERROR_ALLOC_MEMORY);
    }

    end:
    _raw_data = new_buffer;
    _allocated_size = new_size;
    _length = length;
    memset(_raw_data + _length, 0, _allocated_size - _length);
}

// Reset the string.
WString::WString()
{
    _update_buffer_size(0);
}

WString::WString(const WString& string)
{
    _update_buffer_size(string.length());
}

WString::WString(const WString&& string)
{
    _update_buffer_size(string.length());
}
