#include <iostream>
#include <string>
#include <vector>

#include "Command/QueueCommands.h"

using namespace std;

int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    otus::QueueCommands::SetQuantityCommands(n);

    // std::vector<std::string> s{
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

    std::vector<std::string> str{
        "cmd1",
        "cmd2",
        "cmd3",
        "{",
        "cmd3_a",
        "cmd3_b",
        "}",
        "cmd4"};

    otus::QueueCommands queueCommands;

    // for (const auto &s : str)
    //{
    //     std::cout << s << "\n";
    // }

    for (const auto &s : str)
    {
        queueCommands.AddCommand(s);
    }

    queueCommands.AddCommand("EOF");
    return 0;
}