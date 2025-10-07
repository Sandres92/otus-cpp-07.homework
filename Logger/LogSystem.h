#include "vector"
#include "ILogger.h"
#include <memory>

namespace otus
{
    class LogSystem
    {
    private:
        static std::vector<std::unique_ptr<ILogger>> loggers;

    public:
        static void AddLogger(std::unique_ptr<ILogger> logger);
        static void Print(const DynamicBlock &dynamicBlock);
    };
}