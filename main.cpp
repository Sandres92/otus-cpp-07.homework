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

int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    otus::Bulk::SetMaxCommands(n);

    otus::LogSystem3::AddConsoleLogger(make_unique<otus::StdCoutLogger>());
    otus::LogSystem3::AddFileLogger(make_unique<otus::FileLogger>());

    // std::vector<std::string> commands{
    //     "cmd1",
    //     "cmd2",
    //     "{",
    //     "cmd3",
    //     "cmd4",
    //     "}",
    //     "{",
    //     "cmd5",
    //     "cmd6",
    //     "{",
    //     "cmd7",
    //     "cmd8",
    //     "}",
    //     "cmd9",
    //     "{",
    //     "cmd10",
    //     "cmd11",
    //     "}",
    //     "}",
    //     "cmd12",
    //     "EOF"};

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

    // std::vector<std::string> commands{
    //     "cmd1",
    //     "cmd2",
    //     "cmd3",
    //     "{",
    //     "cmd3_a",
    //     "{",
    //     "cmd3_a_a",
    //     "}",
    //     "cmd3_b",
    //     "}",
    //     "cmd4"};

    // otus::StaticBlock staticBlock;

    // commands.clear();
    // commands = {
    //    "cmd1",
    //    "cmd2",
    //    "cmd3",
    //    "cmd4",
    //    "cmd5"};

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