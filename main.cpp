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

    std::vector<std::string> commands{
        "cmd1",
        "cmd2",
        "{",
        "{",
        "cmd_2_1",
        "{",
        "cmd_2_1_1",
        "}",
        "cmd_2_2",
        "}",
        "cmd3",
        "cmd4",
        "}",
        "EOF"};

    otus::Bulk staticBlock;

    auto it = commands.begin();
    int index = 0;
    while (it != commands.end() &&
           staticBlock.AddCommand(*it) != otus::AddCommandType::FinishAddCommand)
    {
        std::cout << *it << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++it;
        ++index;
    }

    return 0;
}