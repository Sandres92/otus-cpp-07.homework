#include <iostream>

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

        void Message(std::ostringstream stream) const override;
    };
}