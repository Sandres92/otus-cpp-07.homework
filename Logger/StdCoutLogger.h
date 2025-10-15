#pragma once

#include <iostream>

#include "IConsoleLogger.h"

namespace otus
{
    class StdCoutLogger : public IConsoleLogger
    {
    public:
        StdCoutLogger() = default;
        ~StdCoutLogger() = default;

        void Print(const std::ostringstream &stream) const override;
    };
}