#pragma once 

struct Point {
    Point (double x, double y) : m_x(x), m_y(y) {}
    ~Point(){
    }
    double m_x{};
    double m_y{};

    // in C++20, no need of rel_ops namespace, just need to implement == and != will be automatically generated
    bool operator== (const Point& right) {
        return (m_x == right.m_x && m_y == right.m_y);
    }
};