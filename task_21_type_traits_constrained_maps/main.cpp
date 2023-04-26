#include "my_map.h"

int main()
{
    Map<int, std::string> m1(11222,std::string{"Steve Murphy"}); 
	Map<long int,std::string> m2(22333,"Ahmed Malik");
    //Map<double,unsigned int> m3(22.1,44555); // should give compilation problems

    return 0;
}