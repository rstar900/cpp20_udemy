#pragma once
#include <iostream>

template <typename T = int , unsigned int size = 2>
class Point{
    T m_components[size];
public :
    // need to add <> to tell that it is going to be a template function
    friend std::ostream& operator<< <>(std::ostream& out, const Point<T, size>& p); 
    unsigned int get_size() const{
        return size;
    }
    void set_value(unsigned int index, T value){
        m_components[index] = value;
    }
};

// Since it is a template function, it's definition also needs to be in the same header file
template <typename T, unsigned int size>
std::ostream& operator<<(std::ostream& out, const Point<T, size>& p) {
    out << "Point : [ dimension : " << p.get_size() << ", components : ";
    for (auto& component : p.m_components) {
        out << component << " ";
    }
    out << "]";
    return out;
} 