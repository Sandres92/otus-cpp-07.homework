#include "../CustomQueue.h"

namespace otus
{
    class ILogger
    {
    private:
        /* data */
    public:
        ILogger() = default;
        ~ILogger() = default;

        virtual void Print(QueueCommands customQueue) const = 0;
    };
}