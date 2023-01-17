#include <iostream>

class Point
{
    double m_x, m_y;

public:
    Point(double x, double y) : m_x{x}, m_y{y}
    {

    }    

    // Indicate by const that no member variable is altered
    // If this is not done, then we cannot call this function with const object  
    void print_info() const
    {
        std::cout << "Const Object" << std::endl;
        std::cout << "x : " << m_x << ", y : " << m_y << std::endl;
    }

    // Overloading for non const case (optional)
    void print_info() 
    {
        std::cout << "Non-Const Object" << std::endl;
        std::cout << "x : " << m_x << ", y : " << m_y << std::endl;
    }

    // Will not work for const object
    void set_x_y(double x, double y)
    {
        m_x = x; m_y = y;
    }
};

int main ()
{
    const Point point1(1.32, 4.56);
    Point point2(1.44, 6.54);

    point1.print_info();
    point2.print_info();

    // Will not compile
    //point1.set_x_y();

    point2.set_x_y(6.34, 9.124);
    point2.print_info();

    return 0;
}