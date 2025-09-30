#include "StdCoutLogger.h"

namespace otus
{
    void StdCoutLogger::Print(CustomQueue customQueue) const
    {
        if (customQueue.Size() == 1)
        {
            std::cout << "1\n";
        }
        else
        {
            std::cout << "0\n";
        }
    }
}