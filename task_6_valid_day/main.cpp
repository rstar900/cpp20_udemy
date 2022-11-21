#include <iostream>

int main()
{
    int day;

    std::cout << "Which day is today  [1 : Monday,...,  7 : Sunday] :" << std::endl;
    std::cin >> day;

    switch (day) 
    {
        case 1 :
        {
            std::cout << "Today is Monday." << std::endl;
        }
        break;

        case 2 :
        {
            std::cout << "Today is Tuesday." << std::endl;
        }
        break;

        case 3 :
        {
            std::cout << "Today is Wednesday." << std::endl;
        }
        break;

        case 4 :
        {
            std::cout << "Today is Thursday." << std::endl;
        }
        break;

        case 5 :
        {
            std::cout << "Today is Friday." << std::endl;
        }
        break;

        case 6 :
        {
            std::cout << "Today is Saturday." << std::endl;
        }
        break;

        case 7 :
        {
            std::cout << "Today is Sunday." << std::endl;
        }
        break;

        default :
        {
            std::cout << day << " is not a valid day." << std::endl;
        }

    }


    return 0;    
}