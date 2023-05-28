#include <memory.hpp>
#include <iostream>

void* cppp::base::xmalloc(c_size size)
{
    return malloc(size);
}

void* cppp::base::xrealloc(void* src, c_size newsize)
{
    return realloc(src, newsize);
}
