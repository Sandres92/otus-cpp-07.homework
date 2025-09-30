#include "ILogger.h"

namespace otus
{
    class FileLogger : public ILogger
    {
    private:
        /* data */
    public:
        FileLogger() = default;
        ~FileLogger() = default;

        void Print(CustomQueue customQueue) const override;
    };
}