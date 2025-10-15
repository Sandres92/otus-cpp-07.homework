#pragma once

#include <sstream>

namespace otus
{
    class ILogger
    {
    private:
        /* data */
    public:
        ILogger() = default;
        ~ILogger() = default;

        virtual void Message(const std::ostringstream &stream) const = 0;
    };
}