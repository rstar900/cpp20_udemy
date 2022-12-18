#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
  bool change_month = false;
  int year, day, feb_days = 28;
  std::vector<std::string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  std::vector<std::string> days {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

  // Input
  std::cout << "Enter a year : ";
  std::cin >> year;
  std::cout << "Enter the first day of the year [1 : Monday, ... 7 : Sunday] : ";
  std::cin >> day;

  if (day < 1 || day > 7)
  {
    std::cout << "Error : Enter a valid day between 1 and 7!" << std::endl;
    return 1; 
  }

  // If a leap year, then feb has 29 days instead of 28
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    feb_days = 29;  

  std::vector<int> month_days {31, feb_days, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  std::cout << std::endl;
  std::cout << "Calendar for " << year << std::endl;

  for (int month_no{0}; std::string month_name : months)
  {
    // Insert month name, days columns
    std::cout << "--"<< month_name << " " << year << "--" << std::endl;

    for(std::string day_name : days)
      std::cout << std::right << std::setw(5)<< day_name;
    
    std::cout << std::endl;

    // Reset the date to 1 and chaneg_month to false every month
    int date = 1;
    change_month = false;

    // Insert empty characters equal to empty days
    for (int i = 0; i < (day - 1); ++i)
      std::cout << std::right << std::setw(5) << "";
    
    // Date display logic
    for (int i = 0; i < month_days[month_no]; ++i)
    {
      std::cout << std::right << std::setw(5) << date++;

      if (date > month_days[month_no])
      {
        std::cout << std::endl << std::endl;
        change_month = true;
      }
      
      if (day == 7)
      {
        day = 1;
        if (!change_month)
          std::cout << std::endl;
      }
      else
      {
        ++day;
      }
    }
    // increment month number counter
    ++month_no;
  }

  return 0;
}
