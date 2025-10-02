#pragma once

#include <iostream>
#include <string>

namespace otus
{
    class Command
    {
    private:
    protected:
        std::size_t pointer = 0;

    public:
        Command() = default;
        virtual ~Command() = default;

        virtual void AddCommand(const std::string &command) = 0;

        virtual std::size_t Size() const noexcept = 0;

        virtual std::string Front() = 0;
        virtual void Pop() = 0;
        virtual bool End() = 0;

        void Reset();
    };
}