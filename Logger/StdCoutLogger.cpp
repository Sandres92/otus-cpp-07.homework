#include "StdCoutLogger.h"

namespace otus
{
    void StdCoutLogger::Message(std::ostringstream stream) const
    {
        std::cout << stream.str();
    }
}