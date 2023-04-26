#pragma once
#include <iostream>
#include <string>
#include <concepts>

template <typename T, typename P>
requires std::is_integral_v<T> && std::is_same_v<P, std::string>
struct Map
{
private : 
    friend std::ostream& operator<< <>  (std::ostream& out, const Map<T,P>& operand); 
    
    T m_key;
    P m_value;
public : 
    Map(T key, P value)
     : m_key(key), m_value(value)
    {}
};
 
 
template < typename T, typename P> 
 std::ostream& operator<<(std::ostream& out, const Map<T,P>& operand)
 requires std::is_integral_v<T> && std::is_same_v<P, std::string> {
 
    out << "Map : [" << operand.m_key 
        << "," << operand.m_value << "]";
    return out;
}