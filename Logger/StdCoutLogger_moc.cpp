#include "StdCoutLogger_moc.h"

namespace otus
{
    void StdCoutLogger_moc::Print(const std::ostringstream &stream) const
    {
        captured << stream.str();
    }

    std::string StdCoutLogger_moc::GetCommands() const
    {
        return captured.str();
    }
}