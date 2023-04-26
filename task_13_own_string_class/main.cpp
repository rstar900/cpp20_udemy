#include "my_string.h"

int main() {
    CU::string str1 {"to be question"};
    CU::string str2 {"the "};

    std::cout << "---------------------------------------------------------\n";

    str1.insert(6, str2);
    std::cout << "After doing str1.insert(6, str2) : " << str1 << std::endl;
    std::cout << "Size: " << str1.size() << std::endl;
    std::cout << "Capacity: " << str1.capacity() << std::endl;

    std::cout << "---------------------------------------------------------\n";

    str1.clear();
    std::cout << "After doing str1.clear() : " << str1 << std::endl;
    std::cout << "Size: " << str1.size() << std::endl;
    std::cout << "Capacity: " << str1.capacity() << std::endl;

    std::cout << "---------------------------------------------------------\n";

    CU::string str3 {"This is an example sentence."};
    str3.erase(10,8);
    std::cout << "After doing str3.erase(0, 8) : " << str3 << std::endl;
    std::cout << "Size: " << str3.size() << std::endl;
    std::cout << "Capacity: " << str3.capacity() << std::endl;

    std::cout << "---------------------------------------------------------\n";

    CU::string str4 ("green apple");
    CU::string str5 ("red apple");

    if (str4.compare(str5) != 0)
        std::cout << str4 << " is not " << str5 << '\n';

    CU::string str6 ("apple");
    CU::string str7 ("apple");

    if (str6.compare(str7) == 0)
        std::cout << "Still, an " << str6 << " is an " << str7 << '\n';

    std::cout << "---------------------------------------------------------\n";

    CU::string str8 = "Writing ";
    CU::string str9 = "print 10 and then 5 more";
    str8.append(str9);
    std::cout << "After str8.append(str9) : " << str8 << '\n';

    std::cout << "---------------------------------------------------------\n";
}