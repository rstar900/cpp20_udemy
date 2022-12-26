#include <iostream>
#include <ctime> // for std::time()

int main()
{
    bool end{false};
    char go_on{};
    int num1{};
    int num2{};
    int result{};
    int usrInp{};
    int op{}; // 0 -> Addition, 1 -> Subtraction, 2 -> Multiplication

    std::cout << "Welcome to the greatest calculator on Earth!" << std::endl;

    while (!end)
    {
        // Using std::time() in the seed generation
        std::srand(std::time(0));

        num1 = std::rand() % 200; // 0-199
        num2 = std::rand() % 200;
        op = std::rand() % 3; // 0-2

        std::cout << "What's the result of ";

        switch(op)
        {
            case 0:
                std::cout << num1 << " + " << num2 << " : ";
                result = num1 + num2;
                break;

            case 1:
                std::cout << num1 << " - " << num2 << " : ";
                result = num1 - num2;
                break;

            case 2:
                std::cout << num1 << " * " << num2 << " : ";
                result = num1 * num2;
                break;        
        }

        std::cin >> usrInp;

        if (usrInp == result)
        {
            std::cout << "Congratulations! You got the result " << result << " right!" << std::endl;
        }
        else
        {
            std::cout << "Naah! the correct result is : " << result << std::endl;
        }

        std::cout << std::endl << "Do you want me to try again ? (Y | N) : ";
        std::cin >> go_on;

        end = (go_on == 'y' || go_on == 'Y') ? false : true;

    }

    std::cout << "See you later!" << std::endl;
}