#pragma once

#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <chrono>
#include <cstdint>

#include "../Logger/LogSystem.h"
#include "AddCommandType.h"

namespace otus
{
    using QuantityCommands_t = size_t;

    /**
     * @brief Class, to receive commands and processing it
     *
     */
    class Bulk
    {
    private:
        /**
         * @brief LogType, type processing commands
         *
         */
        enum class LogType
        {
            ConsoleOnly,
            FileOnly,
            ConsoleAndFile
        };

        /**
         * @brief Function of processing command
         * @param <in> type of logging
         */
        void LogCommands(LogType logType);

        static QuantityCommands_t MAX_COMMANDS;

        std::vector<std::string> commands;
        std::queue<size_t> openDynamic;
        size_t closeDynamic = 0;
        int64_t time;

    protected:
        std::vector<std::string> GetCommands() const;

    public:
        Bulk() = default;
        ~Bulk() = default;

        /**
         * @brief Add commands function
         * @param <in> new commands
         */
        AddCommandType AddCommand(std::string command);

        /**
         * @brief Set Max commmands in array funaction
         * @param <in> Quantity Commands
         */
        static void SetMaxCommands(QuantityCommands_t _MAX_COMMANDS)
        {
            MAX_COMMANDS = _MAX_COMMANDS;
        }
    };
}