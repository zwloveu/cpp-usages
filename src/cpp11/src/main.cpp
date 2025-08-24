#include <iostream>
#include <vector>
#include <limits>

#include "operation_registry.h"

void clear_screen()
{
    system("cls"); // for Linux/Mac，use system("clear")
}

int main()
{
    std::cout << "C++ version: " << __cplusplus << std::endl;
    
    register_all_operations();
    const auto &ops = OperationRegistry::get_instance().get_operations();

    std::vector<std::string> op_keys;
    for (const auto &pair : ops)
    {
        op_keys.push_back(pair.first);
    }

    while (true)
    {
        for (size_t i = 0; i < op_keys.size(); ++i)
        {
            std::cout << "  " << (i + 1) << ". " << op_keys[i] << std::endl;
        }

        std::cout << std::endl
                  << "Please choose (0 to exit, 1-" << op_keys.size() << "): ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl
                      << "Invalid input! Please choose (0 to exit, 1-" << op_keys.size() << "): " << std::endl;
            system("pause");
            continue;
        }

        if (choice == 0)
        {
            clear_screen();
            std::cout << "Exiting program...\n";
            break;
        }

        if (choice < 1 || choice > static_cast<int>(op_keys.size()))
        {
            std::cout << std::endl
                      << "Invalid input! Please choose (0 to exit, 1-" << op_keys.size() << "): " << std::endl;
            std::cout << "Press any key to continue...";
            std::cin.get();
            continue;
        }

        clear_screen();
        std::cout << "----- [RUNNING] " << op_keys[choice - 1] << " -----" << std::endl;

        try
        {
            ops.at(op_keys[choice - 1])();
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "----- [Finished] " << op_keys[choice - 1] << " -----" << std::endl;
        std::cout << "Press any key to continue...";        
        std::cin.ignore();
        std::cin.get();
        clear_screen();
    }

    return 0;
}