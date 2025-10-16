#pragma once

#include <string>

#include "StdCoutLogger.h"

namespace otus
{
    class StdCoutLogger_moc : public IConsoleLogger
    {
    private:
        mutable std::ostringstream captured;

    public:
        StdCoutLogger_moc() = default;
        ~StdCoutLogger_moc() = default;

        void Print(const std::ostringstream &stream) const override;

        std::string GetCommands() const;
    };
}