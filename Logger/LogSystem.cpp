#include "LogSystem.h"

namespace otus
{
    std::vector<std::unique_ptr<otus::IConsoleLogger>> LogSystem::consoleLoggers;
    std::vector<std::unique_ptr<otus::IFileLogger>> LogSystem::fileLoggers;
}