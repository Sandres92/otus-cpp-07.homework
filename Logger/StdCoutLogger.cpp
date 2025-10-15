#include "StdCoutLogger.h"

namespace otus
{
    void StdCoutLogger::Print(const std::ostringstream &stream) const
    {
        std::cout << "bulk: " << stream.str() << "\n";
    }
}