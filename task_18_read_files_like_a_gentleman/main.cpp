#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

void read_from_file(std::string_view filename, size_t size, int * data)
{
    std::ifstream fstrem_in{ filename.data() }; // We may fail to open the file

    
    if (fstrem_in.fail()) {
        //We failed to open the file
        std::string err_msg = std::string("Unable to open file ") + std::string(filename.data());
        throw std::runtime_error(err_msg);
    }
    
    int value;
    int index{};
    while (fstrem_in >> value) {
        data[index++] = value;
    }
    //Something might go wrong in the process of reading the file.

    if (!fstrem_in.eof()) { 
        //We failed to reach End of File
        std::string err_msg = std::string("Something went wrong while reading the file ") + std::string(filename.data());
        throw std::runtime_error(err_msg);
    }
 
}

int main()
{
    int data[4]{};
 
    try{

    read_from_file("numbersss.txt",std::size(data),data);

    for(auto i : data){
        std::cout << "value : " << i << std::endl;
    }

    } catch(std::runtime_error& e) {

        std::cout << e.what() << std::endl;
        return 1;
        
    }

    return 0;
}