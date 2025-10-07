#include "CommandsBlock.h"

namespace otus
{
    CommandsBlock::CommandsBlock() : Block(BlockType::CommnadBlock)
    {
        idBlock = CommandsBlock::countBlock;
        ++CommandsBlock::countBlock;
        // MakeComlete();

        // std::cout << "creat CommandsBlock " << idBlock << "\n";
    }

    void CommandsBlock::AddCommand(const std::string &command)
    {
        commands.push_back(command);
    }

    size_t CommandsBlock::SizeElements() const noexcept
    {
        return commands.size();
    }

    size_t CommandsBlock::SizeBlocks() const noexcept
    {
        return 1;
    }

    std::string CommandsBlock::Front()
    {
        if (pointer < commands.size())
        {
            return commands[pointer];
        }

        return "";
    }

    void CommandsBlock::Pop()
    {
        // std::cout << "\nCommandsBlock pointer a = " << pointer << " , commands.size() " << commands.size() << " idBlock = " << idBlock << "\n";
        if (pointer < commands.size())
        {
            ++pointer;
        }
        // std::cout << "CommandsBlock pointer b = " << pointer << " , commands.size() " << commands.size() << " idBlock = " << idBlock << "\n";
    }

    bool CommandsBlock::End()
    {
        // std::cout << "\nCommandsBlock::End pointer = " << pointer << " , commands.size() " << commands.size() << " idBlock = " << idBlock << "\n";

        return pointer == commands.size();
    }

    BlockType CommandsBlock::GetCurrentBlockType() const
    {
        return BlockType::CommnadBlock;
    }

    BlockType CommandsBlock::GetNextBlockType() const
    {
        return BlockType::CommnadBlock;
    }
}