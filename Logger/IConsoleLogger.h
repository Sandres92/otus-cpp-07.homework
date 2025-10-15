#pragma once

#include <sstream>

namespace otus
{
    class IConsoleLogger
    {
    public:
        IConsoleLogger() = default;
        ~IConsoleLogger() = default;

        virtual void Print(const std::ostringstream &stream) const = 0;
    };
}