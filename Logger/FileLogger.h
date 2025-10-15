#pragma once

#include <fstream>

#include "ILogger.h"
#include "IFileLogger.h"

namespace otus
{
    class FileLogger : public IFileLogger
    {
    public:
        FileLogger() = default;
        ~FileLogger() = default;

        void SaveToFile(std::string fileName, const std::ostringstream &stream) const override;
    };
}