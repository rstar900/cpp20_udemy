#include <iostream>

    // By default int, here assigned unsigned char to save space
    enum class Month : unsigned char
    {
        Jan = 1, Feb, Mar,
        Apr, May, Jun,
        Jul, Aug, Sep,
        Oct, Nov, Dec 
    };

void month_name(Month month)
{
    
    switch (month)
    {
        // C++20 feature
        using enum Month;

        case Jan:
            std::cout << "It is January" << std::endl;
            break;

        case Feb:
            std::cout << "It is February" << std::endl;
            break;

        case Mar:
            std::cout << "It is March" << std::endl;
            break;
            
        case Apr:
            std::cout << "It is April" << std::endl;
            break;

        case May:
            std::cout << "It is May" << std::endl;
            break;

        case Jun:
            std::cout << "It is June" << std::endl;
            break;

        case Jul:
            std::cout << "It is July" << std::endl;
            break;                                    

        case Aug:
            std::cout << "It is August" << std::endl;
            break;
            
        case Sep:
            std::cout << "It is September" << std::endl;
            break;

        case Oct:
            std::cout << "It is October" << std::endl;
            break;

        case Nov:
            std::cout << "It is November" << std::endl;
            break;

        case Dec:
            std::cout << "It is December" << std::endl;
            break; 

        default:
            std::cout << "Not a valid month!" << std::endl;                                       

    }
}

int main()
{

    Month month {Month::Apr};
    std::cout << "April is : " << static_cast<int>(month) << std::endl; // Cannot print directly, need to cast 

    std::cout << std::endl;

    for (unsigned char i = 1; i <= 12; ++i)
    {
        Month month_val {i}; // Explicit conversion to Month
        month_name(month_val);
    }
}