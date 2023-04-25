module;
// This is the Global module fragment (all legacy includes and preprocessor stuff)
#include <cstring>
#include <iostream>
export module first_module;

// Preamble (all imports) (not working for c++ headers )
// import module_name; or import <c++_header>;

// Purview starts below (all code)
export void say_hello(const char* name)
{
    std::cout << "Hello, " << name << " " << strlen(name) << " !" << std::endl;
}