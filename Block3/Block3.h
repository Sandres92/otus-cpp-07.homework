#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <chrono>

#include "../Logger/LogSystem3.h"

namespace otus
{
    using QuantityCommands_t = size_t;
    class Block3
    {
    private:
        static inline QuantityCommands_t quantityCommands = 1;

        std::vector<std::string> commands;
        std::queue<size_t> openDynamic;
        size_t closeDynamic = 0;
        std::time_t time;

    public:
        Block3() = default;
        ~Block3() = default;

        void AddCommand(std::string command);
        void Print();
        void SaveToFile();

        static void SetQuantityCommands(QuantityCommands_t _quantityCommands)
        {
            quantityCommands = _quantityCommands;
        }
    };
}