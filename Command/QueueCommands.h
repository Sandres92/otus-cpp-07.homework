#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>

#include "Command.h"
#include "ArrayCommands.h"

namespace otus
{
    using QuantityCommandType = size_t;

    class QueueCommands : public Command
    {
    private:
        static inline QuantityCommandType quantityCommands = 0;
        size_t numBlock = 0;

        std::vector<Command *> blocks;
        std::time_t time;

    public:
        QueueCommands();
        ~QueueCommands();

        void AddCommand(const std::string &command) override;

        size_t Size() const noexcept override;

        std::string Front() override;
        void Pop() override;
        bool End() override;

        void Print();

        static void SetQuantityCommands(QuantityCommandType _quantityCommands)
        {
            quantityCommands = _quantityCommands;
        }
    };
}