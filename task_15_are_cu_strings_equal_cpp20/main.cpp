#include "my_string.h"

int main()
{
    CU::string a("Hello");
    CU::string b("Hello");
 
    auto result1 = (a == b);
    auto result2 = (a!=b);
    std::cout << std::boolalpha;
    std::cout << "result1 : " << result1 << std::endl;
    std::cout << "result2 : " << result2 << std::endl;
    return 0;
}