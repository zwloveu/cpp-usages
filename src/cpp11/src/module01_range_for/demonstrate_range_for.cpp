#include "module01_range_for/demonstrate_range_for.h"
#include <iostream>
#include <cassert>

void demonstrate_range_for_basic()
{
    const std::vector<std::string> fruits{"apple", "banana", "cherry"};
    std::cout << "Range for basic (read-only):\n";
    for (const auto &fruit : fruits)
    {
        std::cout << " - " << fruit << std::endl;
    }
}

void demonstrate_range_for_modify()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << "Range for modify (with reference):" << std::endl;
    for (auto &num : nums)
    {
        num *= 2;
    }

    for (const auto &num : nums)
    {
        std::cout << " - " << num << std::endl;
    }
}

void demonstrate_range_for_modify_ptr()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> *const nums_ptr = &nums;
    
    if (!nums_ptr)
        return;

    for (auto &num : *nums_ptr)
    {
        num *= 2;
    }

    for (const auto &num : *nums_ptr)
    {
        std::cout << " - " << num << "\n";
    }
}

void demonstrate_range_for_modify_iter()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << "demonstrate_range_for_modify_iter" << std::endl;
    std::cout << "First Element Address: " << &nums[0] << std::endl;
    std::cout << "Last Element Address: " << &nums[nums.size() - 1] << std::endl;
    std::cout << *(nums.cend() - 1) << std::endl;
    assert(nums[nums.size() - 1] == *(nums.cend() - 1));

    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        *it *= 2;
    }

    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
    {
        std::cout << " - " << *it << "\n";
    }
}