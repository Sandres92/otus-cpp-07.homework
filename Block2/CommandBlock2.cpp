#include "CommandBlock2.h"

namespace otus
{
    CommandBlock2::CommandBlock2(/* args */) : Block2(BlockType::DynamicBlock)
    {
    }

    CommandBlock2::~CommandBlock2()
    {
    }

    void CommandBlock2::AddCommand(const std::string &command)
    {
        this->command = command;
    }

    bool CommandBlock2::IsComlete() const
    {
        return true;
    }
}