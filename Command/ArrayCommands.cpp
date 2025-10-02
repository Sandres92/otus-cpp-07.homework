#include "ArrayCommands.h"

namespace otus
{
    void ArrayCommands::AddCommand(const std::string &command)
    {
        commands.push_back(command);
    }

    size_t ArrayCommands::Size() const noexcept
    {
        return commands.size();
    }

    std::string ArrayCommands::Front()
    {
        if (pointer < commands.size())
        {
            return commands[pointer];
        }

        return "";
    }

    void ArrayCommands::Pop()
    {
        if (pointer < commands.size())
        {
            ++pointer;
        }
    }

    bool ArrayCommands::End()
    {
        return pointer == commands.size();
    }
}