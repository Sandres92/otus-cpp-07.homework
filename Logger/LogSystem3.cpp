#include "LogSystem3.h"

namespace otus
{
    std::vector<std::unique_ptr<otus::IConsoleLogger>> LogSystem3::consoleLoggers;
    std::vector<std::unique_ptr<otus::IFileLogger>> LogSystem3::fileLoggers;
}