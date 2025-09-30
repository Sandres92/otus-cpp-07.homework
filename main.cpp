#include <iostream>
#include <stack>
#include <queue>

#include "CustomQueue.h"

using namespace std;

int main(int argc, char *argv[])
{
    size_t n = 3;
    if (argc >= 2)
    {
        n = atoi(argv[1]);
    }

    std::cout << n << "\n";

    std::queue<int> s;
    for (size_t i = 0; i != n; ++i)
    {
        s.push(i);
    }

    while (s.size() != 0)
    {
        std::cout << s.front() << " , " << s.back() << "\n";
        s.pop();
    }

    return 0;
}