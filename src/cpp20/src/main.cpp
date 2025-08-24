#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <coroutine>

void async_task(int id)
{
    std::cout << "Task " << id << " running on thread: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

struct CoroutineTask
{
    struct promise_type
    {
        CoroutineTask get_return_object() { return {}; }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() {}
    };
};

CoroutineTask coroutine_task(int id)
{
    std::cout << "Coroutine Task " << id << " thread: " << std::this_thread::get_id() << std::endl;
    co_await std::suspend_always{};
}

int main()
{
    std::cout << "C++ version: " << __cplusplus << std::endl;

    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

    auto fut1 = std::async(std::launch::async, async_task, 1);
    auto fut2 = std::async(std::launch::async, async_task, 2);
    auto fut3 = std::async(std::launch::async, async_task, 3);

    fut1.wait();
    fut2.wait();
    fut3.wait();

    coroutine_task(1);
    coroutine_task(2);
    coroutine_task(3);

    return 0;
}