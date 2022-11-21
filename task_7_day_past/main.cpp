#include <iostream>

int main()
{
    int day, daysPassed, dayPast;
    bool isValid = false;

    std::cout << "Which day is today  [1 : Monday,...,  7 : Sunday] :" << std::endl;
    std::cin >> day;

    switch (day)
    {
    case 1:
    {
        std::cout << "Today is Monday." << std::endl;
        isValid = true;
    }
    break;

    case 2:
    {
        std::cout << "Today is Tuesday." << std::endl;
        isValid = true;
    }
    break;

    case 3:
    {
        std::cout << "Today is Wednesday." << std::endl;
        isValid = true;
    }
    break;

    case 4:
    {
        std::cout << "Today is Thursday." << std::endl;
        isValid = true;
    }
    break;

    case 5:
    {
        std::cout << "Today is Friday." << std::endl;
        isValid = true;
    }
    break;

    case 6:
    {
        std::cout << "Today is Saturday." << std::endl;
        isValid = true;
    }
    break;

    case 7:
    {
        std::cout << "Today is Sunday." << std::endl;
        isValid = true;
    }
    break;

    default:
    {
        std::cout << day << " is not a valid day." << std::endl;
    }
    }

    if (isValid)
    {
        std::cout << "How many days have passed up to today : " << std::endl;
        std::cin >> daysPassed;

        daysPassed %= 7;
        dayPast = (day +  (7 - daysPassed)) % 7;

        if (dayPast == 0)
            dayPast = 7;

        /* Alternate approach (from instructor)

        //Make sure the day difference is between 0 and 6 inclusive
        //for ease of computation
        int normalized_diff = (days_passed %7);
  
        int day_in_the_past = today - normalized_diff;

        //If the day in the past happens to be negative, we throw it back
        //in the positive range, again for ease of our logic. This way
        //we can use the same logic to print out the days
        if(day_in_the_past < 0){
            day_in_the_past += 7;
        }

        */    

        std::cout << "If we went " << daysPassed << " in past we would hit a ";

        switch (dayPast)
        {
        case 1:
        {
            std::cout << "Monday." << std::endl;
            
        }
        break;

        case 2:
        {
            std::cout << "Tuesday." << std::endl;
            
        }
        break;

        case 3:
        {
            std::cout << "Wednesday." << std::endl;
            
        }
        break;

        case 4:
        {
            std::cout << "Thursday." << std::endl;
            
        }
        break;

        case 5:
        {
            std::cout << "Friday." << std::endl;
            
        }
        break;

        case 6:
        {
            std::cout << "Saturday." << std::endl;
            
        }
        break;

        case 7:
        {
            std::cout << "Sunday." << std::endl;
        
        }
        break;

        default:
        {
            std::cout << day << " is not a valid day." << std::endl;
        }
        
        }

    }

    return 0;
}