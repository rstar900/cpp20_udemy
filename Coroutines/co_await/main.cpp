// Need to use -fcoroutines argument with GCC (tested with g++ 11)
#include <iostream>
#include <coroutine>

// co_await allows to suspend functions, and when they are called back then they run from the point after co_await 

// The basic coroutine infrastructure that needs to be implemented for basic coroutine functionality to work
// Here we define CoroType to be our own custom coroutine type
struct CoroType
{
    struct promise_type
    {
        CoroType get_return_object() { return CoroType(this); }

        // if return type set to std::suspend_never, then the coroutine will not suspend in the beginning
        std::suspend_always initial_suspend() { return {}; } 
        std::suspend_always final_suspend() noexcept { return {}; }

        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }

        void return_void(){};
    };

    CoroType(promise_type* p) : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}
    ~CoroType()
    {
        std::cout << "Coroutine destroyed..." << std::endl;
    }

    std::coroutine_handle<promise_type> m_handle;
};

// The coroutine definition goes here
CoroType my_coroutine()
{
    std::cout << "Welcome to my coroutine" << std::endl;
    std::cout << "Stage 1 running..." << std::endl;
    co_await std::suspend_always{};

    std::cout << "Stage 2 running..." << std::endl;
    co_await std::suspend_always{};

    std::cout << "Stage 3 running..." << std::endl;
    co_await std::suspend_always{};

    std::cout << "Done!" << std::endl;
}

int main()
{
    auto coroutine_func = my_coroutine();

    std::cout << std::boolalpha;
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    coroutine_func.m_handle.resume(); // can also simply use coroutine_func.m_handle()
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

    coroutine_func.m_handle();
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    
    coroutine_func.m_handle();
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";
    
    coroutine_func.m_handle();
    std::cout << "Coroutine finished: " << coroutine_func.m_handle.done() << std::endl;
    std::cout << "--------------------------------------------------------------------\n";

}