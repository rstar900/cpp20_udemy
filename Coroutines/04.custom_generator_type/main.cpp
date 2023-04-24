// Need to use -fcoroutines argument with GCC (tested with g++ 11)
#include <iostream>
#include <coroutine>

// Defining our own Generator<T> type here
// without implementing it's methods MSVC C++ compiler does not compile code 

// The basic coroutine infrastructure that needs to be implemented for basic coroutine functionality to work
// Here we define CoroType to be our own custom coroutine type
template <typename T>
struct Generator
{
    struct promise_type
    {
        // need m_value to store return value after co_yield
        T m_value;

        Generator<T> get_return_object() { return Generator(this); }

        // if return type set to std::suspend_never, then the coroutine will not suspend in the beginning
        std::suspend_always initial_suspend() { return {}; } 
        std::suspend_always final_suspend() noexcept { return {}; }

        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }

        // instead of return_void(), we define yield_value() function for co_yield to work
        // Again if you don't want coroutine to suspend, use return type std::suspend_never
        std::suspend_always yield_value(T val)
        {
            m_value = val;
            return {};
        }

        // Need to implement either return_value() or return_void() functions for co_return to work (not both)

        //void return_void() {}
        
        void return_value(T val)
        {
            m_value = val;
        }
        
    };

    // instead of pointer *p using reference &p
    Generator(promise_type* p) : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}
    ~Generator()
    {
        std::cout << "Coroutine destroyed..." << std::endl;
        m_handle.destroy();
    }

    // Need to override () operator to make it callable
    T operator()()
    {
        m_handle.resume();
        return m_handle.promise().m_value;
    }

    std::coroutine_handle<promise_type> m_handle;
};

// The coroutine definition goes here
Generator<int> my_coroutine()
{
    std::cout << "Welcome to my coroutine" << std::endl;
    std::cout << "Stage 1 running..." << std::endl;
    co_yield 10;

    std::cout << "Stage 2 running..." << std::endl;
    co_yield 20;

    std::cout << "Stage 3 running..." << std::endl;
    co_yield 30;

    std::cout << "Done!" << std::endl;
    co_return 100;
}

// Another coroutine to generate infinite numbers
Generator<int> infinite_number_generator()
{
    int x {1};

    while(true)
    {
        co_yield x++;
    }

    co_return -1;
}

int main()
{
    auto coroutine_func = my_coroutine();

    std::cout << std::boolalpha;
    std::cout << "Coroutine return value: " << coroutine_func.m_handle.promise().m_value << std::endl;
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    coroutine_func.m_handle.resume(); // can also simply use coroutine_func.m_handle()
    std::cout << "Coroutine return value: " << coroutine_func.m_handle.promise().m_value << std::endl;
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    coroutine_func.m_handle();
    std::cout << "Coroutine return value: " << coroutine_func.m_handle.promise().m_value << std::endl;
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    
    coroutine_func.m_handle();
    std::cout << "Coroutine return value: " << coroutine_func.m_handle.promise().m_value << std::endl;
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    
    coroutine_func.m_handle();
    std::cout << "Coroutine return value: " << coroutine_func.m_handle.promise().m_value << std::endl;
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    std::cout << "Testing infinite number generator till 10\n";
    auto inf_num_gen_func = infinite_number_generator();
    for (int i {}; i < 10; ++i) 
    {
        std::cout << "value[" << i << "] : " << inf_num_gen_func() << std::endl;
    }
    std::cout << "----------------------------------------------------------------------\n";
}