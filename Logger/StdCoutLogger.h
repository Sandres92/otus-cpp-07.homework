#include "ILogger.h"

namespace otus
{
    class StdCoutLogger : public ILogger
    {
    private:
        /* data */
    public:
        StdCoutLogger() = default;
        ~StdCoutLogger() = default;

        void Print(CustomQueue customQueue) const override;
    };
}