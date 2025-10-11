#include "CommandBlock2.h"

namespace otus
{
    CommandBlock2::CommandBlock2(const std::string &command) : command(command),
                                                               Block2(BlockType::DynamicBlock)
    {
    }

    CommandBlock2::~CommandBlock2()
    {
    }

    void CommandBlock2::AddCommand(const std::string &command)
    {
        this->command = command;
    }

    size_t CommandBlock2::Size() const noexcept
    {
        return 1;
    }

    std::string CommandBlock2::Front()
    {
        return "";
    }

    void CommandBlock2::Pop()
    {
    }

    bool CommandBlock2::End()
    {
        return true;
    }
}