#pragma once

#include <string>
#include <sstream>

namespace otus
{
    class IFileLogger
    {
    public:
        IFileLogger() = default;
        ~IFileLogger() = default;

        virtual void SaveToFile(std::string fileName, const std::ostringstream &stream) const = 0;
    };
}