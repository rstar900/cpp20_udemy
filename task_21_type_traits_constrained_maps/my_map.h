#pragma once
#include <type_traits>
#include <string>

template <typename T, typename P>
struct Map
{
private : 
    static_assert(std::is_integral_v<T>, "Keys can only be of integral type");
    static_assert(std::is_same_v<P, std::string>, " Values can only be of std::string type");
    T m_key;
    P m_value;
public : 
    Map(T key, P value)
     : m_key(key), m_value(value)
    {}
};