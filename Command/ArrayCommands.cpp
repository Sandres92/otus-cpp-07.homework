#include "ArrayCommands.h"

namespace otus
{
    void ArrayCommands::AddCommand(const std::string &command)
    {
        commands.push_back(command);
    }
}