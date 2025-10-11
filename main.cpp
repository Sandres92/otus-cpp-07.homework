#include <iostream>
#include <string>
#include <vector>

#include "Block/StaticBlock.h"
#include "Block/DynamicBlock.h"

#include "Block2/DynamicBlock2.h"
#include "Block3/Block3.h"

using namespace std;

int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    otus::StaticBlock::SetQuantityCommands(n);
    otus::Block3::SetQuantityCommands(n);

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
        "}"};

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
    for (const auto &s : commands)
    {
        staticBlock.AddCommand(s);
    }

    staticBlock.AddCommand("EOF");
    return 0;
}