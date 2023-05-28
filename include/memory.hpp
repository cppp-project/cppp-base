/**
 * @file memory.hpp
 * @author ChenPi11
 * @copyright Copyright (C) 2023
 * @date 2023-5-28
 * @brief C++ Plus Bytes memory functions
 * @version 1.0.0
 * @link https://github.com/cppp-project/cppp-base/
 */
#ifndef _CPPP_BASE_BYTES_HPP_
#define _CPPP_BASE_BYTES_HPP_

#include "cpppencodings.hpp"
#include "mincpppdef.hpp"

namespace cppp{
namespace base
{
    void* xmalloc(c_size size);
    void* xrealloc(void* src, c_size newsize);
} /* namespace base */
}
#endif