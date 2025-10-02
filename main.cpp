#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

#include "QueueCommands.h"

using namespace std;

int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    std::vector<std::string> s{
        "cmd1",
        "cmd2",
        "{",
        "cmd3",
        "cmd4",
        "}",
        "{",
        "cmd5",
        "cmd6",
        "{",
        "cmd7",
        "cmd8",
        "}",
        "cmd9",
        "{",
        "cmd10",
        "cmd11",
        "}",
        "}",
        "cmd12",
        "EOF"};

    return 0;
}