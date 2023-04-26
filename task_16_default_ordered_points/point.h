#include <iostream>
#include <compare>

struct Point {
    Point (double x, double y) : m_x(x), m_y(y) {}
    Point(double x) : Point(x,x) {}
    ~Point(){
    }
 
    double m_x{};
    double m_y{};

    // Compiler generates all comparison operator for default
    auto operator<=>(const Point& right) const = default;
};

// Update: No need of defining outside in C++20 for <=> operator to enable implicit conversions on left operand
/* 
auto operator<=>(const double left, const Point& right) {
    return Point(left).operator<=>(right);
}
*/