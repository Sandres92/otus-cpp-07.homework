#include "LogSystem3.h"

namespace otus
{
    void LogSystem3::AddLogger(std::unique_ptr<ILogger> logger)
    {
        loggers.push_back(std::move(logger));
    }

    void LogSystem3::Message(std::vector<std::string> commands,
                             std::queue<int> openDynamic)
    {
        std::ostringstream stream;

        stream << "bulk: ";
        for (size_t i = 0; i != commands.size(); ++i)
        {
            stream << commands.front();

            if (i != commands.size() - 1)
            {
                stream << ", ";
            }

            if (i == openDynamic.front())
            {
                openDynamic.pop();
                stream << "\n";
            }
        }
        stream << "\n";
    }
}