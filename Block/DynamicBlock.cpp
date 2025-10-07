
#include "DynamicBlock.h"

namespace otus
{
    DynamicBlock::DynamicBlock() : Block(BlockType::DynamicBlock)
    {
        auto now = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(now);

        ++numBlock;

        idBlock = DynamicBlock::countBlock;
        ++DynamicBlock::countBlock;
    }

    DynamicBlock::DynamicBlock(BlockType blockType) : Block(blockType)
    {
        auto now = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(now);

        ++numBlock;

        idBlock = DynamicBlock::countBlock;
        ++DynamicBlock::countBlock;
    }

    void DynamicBlock::AddCommand(const std::string &command)
    {
        if (command == "{")
        {
            if (blocks.size() == 0)
            {
                blocks.push_back(new DynamicBlock());
            }
            else if (blocks[blocks.size() - 1]->GetCurrentBlockType() == BlockType::CommnadBlock)
            {
                blocks[blocks.size() - 1]->MakeComlete();
                blocks.push_back(new DynamicBlock());
            }
            else
            {
                blocks[blocks.size() - 1]->AddCommand(command);
            }
            return;
        }
        else if (command == "}")
        {
            blocks[blocks.size() - 1]->MakeComlete();
            return;
        }
        else if (command == "EOF")
        {
            MakeComlete();
            return;
        }

        if (blocks.size() == 0 || blocks[blocks.size() - 1]->IsComlete())
        {
            blocks.push_back(new CommandsBlock());
        }

        blocks[blocks.size() - 1]->AddCommand(command);
    }

    size_t DynamicBlock::SizeElements() const noexcept
    {
        size_t size = 0;
        for (const auto &block : blocks)
        {
            size += block->SizeElements();
        }

        return size;
    }

    size_t DynamicBlock::SizeBlocks() const noexcept
    {
        return blocks.size();
    }

    BlockType DynamicBlock::GetCurrentBlockType() const
    {
        return blockType;
    }

    BlockType DynamicBlock::GetNextBlockType() const
    {
        return blocks[blocks.size() - 1]->GetCurrentBlockType();
    }

    std::string DynamicBlock::Front()
    {
        if (pointer < blocks.size())
        {
            return blocks[pointer]->Front();
        }

        return {};
    }

    void DynamicBlock::Pop()
    {
        if (pointer < blocks.size() && !blocks[pointer]->End())
        {
            blocks[pointer]->Pop();
            if (blocks[pointer]->End())
            {
                ++pointer;
            }
        }
    }

    bool DynamicBlock::End()
    {
        return pointer == blocks.size();
    }

    void DynamicBlock::MakeComlete()
    {
        if (blocks.size() == 0)
        {
            Block::MakeComlete();
        }
        else if (blocks[blocks.size() - 1]->GetCurrentBlockType() == BlockType::DynamicBlock)
        {
            blocks[blocks.size() - 1]->MakeComlete();
        }
        else
        {
            Block::MakeComlete();
        }
    }
} //