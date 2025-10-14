#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "Block/StaticBlock.h"
#include "Block/DynamicBlock.h"

#include "Block2/DynamicBlock2.h"
#include "Block3/Block3.h"
#include "Block3/AddCommandType.h"

using namespace std;

int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    otus::StaticBlock::SetQuantityCommands(n);
    otus::Block3::SetMaxCommands(n);

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

    otus::Block3 staticBlock;

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