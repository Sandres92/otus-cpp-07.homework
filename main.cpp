#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "Bulk/Bulk.h"

#include "Logger/LogSystem.h"
#include "Logger/StdCoutLogger.h"
#include "Logger/FileLogger.h"

using namespace std;

/**
 * @brief Entry point
 *
 * Execution of the program
 * starts here.
 *
 * @return Program exit status
 */
int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    otus::Bulk::SetMaxCommands(n);

    otus::LogSystem::AddConsoleLogger(std::make_unique<otus::StdCoutLogger>());
    otus::LogSystem::AddFileLogger(std::make_unique<otus::FileLogger>());

    otus::Bulk bulk;

    while (true)
    {
        std::string command;
        std::cin >> command;

        if (bulk.AddCommand(command) == otus::AddCommandType::FinishAddCommand)
        {
            break;
        }
    }

    return 0;
}