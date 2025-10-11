#include <memory>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

#include "ILogger.h"

namespace otus
{
    class LogSystem3
    {
    private:
        static std::vector<std::unique_ptr<ILogger>> loggers;

    public:
        static void AddLogger(std::unique_ptr<ILogger> logger);

        static void Message(std::vector<std::string> commands,
                            std::queue<int> openDynamic);
    };
}