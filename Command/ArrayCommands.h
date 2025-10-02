#pragma once

#include <string>
#include <vector>
#include <queue>

#include "Command.h"

namespace otus
{
    class ArrayCommands : public Command
    {
    public:
        ArrayCommands() = default;
        virtual ~ArrayCommands() = default;

    private:
        std::vector<std::string> commands;

        void AddCommand(const std::string &command) override;

        size_t Size() const noexcept override;

        std::string Front() override;

        void Pop() override;
        bool End() override;
    };
}