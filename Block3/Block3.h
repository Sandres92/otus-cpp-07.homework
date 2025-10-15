#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <chrono>
#include <cstdint>

#include "../Logger/LogSystem3.h"
#include "AddCommandType.h"

namespace otus
{
    using QuantityCommands_t = size_t;
    class Block3
    {
    private:
        enum class LogType
        {
            ConsoleOnly,
            FileOnly,
            ConsoleAndFile
        };

        void PrintLog(LogType logType);

        static QuantityCommands_t MAX_COMMANDS;

        std::vector<std::string> commands;
        std::queue<size_t> openDynamic;
        size_t closeDynamic = 0;
        int64_t time;

    public:
        Block3() = default;
        ~Block3() = default;

        AddCommandType AddCommand(std::string command);

        static void SetMaxCommands(QuantityCommands_t _MAX_COMMANDS)
        {
            MAX_COMMANDS = _MAX_COMMANDS;
        }
    };
}