// Need to use -fcoroutines argument with GCC (tested with g++ 11)
#include <iostream>
#include <coroutine>
#include "unique_generator.h"

// Using third party generator from https://github.com/Quuxplusone/coro/

// The coroutine definition goes here
unique_generator<int> my_coroutine()
{
    std::cout << "Welcome to my coroutine" << std::endl;
    std::cout << "Stage 1 running..." << std::endl;
    co_yield 10;

    std::cout << "Stage 2 running..." << std::endl;
    co_yield 20;

    std::cout << "Stage 3 running..." << std::endl;
    co_yield 30;

    std::cout << "Done!" << std::endl;
    //co_return 100;
}

// Another coroutine to generate numbers upto n
unique_generator<int> number_generator(int n)
{
    int x {1};

    while(x <= n)
    {
        co_yield x++;
    }

    //co_return -1;
}

int main()
{
    auto coroutine_func = my_coroutine();

    std::cout << "---------------------------my_coroutine() start-------------------------------------\n";
    std::cout << coroutine_func() << std::endl;
    std::cout << coroutine_func() << std::endl;
    std::cout << coroutine_func() << std::endl;
    std::cout << coroutine_func() << std::endl;
    std::cout << "---------------------------my_coroutine() end -------------------------------------\n";

    // Running it the way it is defined by the developer
    std::cout << "Testing infinite number generator till 10\n";
    auto inf_num_gen_func = number_generator(10);
    for (int i : number_generator(10)) 
    {
        std::cout << "value[" << i << "] : " << inf_num_gen_func() << std::endl;
    }
    std::cout << "----------------------------------------------------------------------\n";
}