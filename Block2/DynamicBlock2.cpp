#include "DynamicBlock2.h"

namespace otus
{
    DynamicBlock2::DynamicBlock2() : Block2(BlockType::DynamicBlock)
    {
    }

    DynamicBlock2::~DynamicBlock2()
    {
    }

    void DynamicBlock2::AddCommand(const std::string &command)
    {
        if (command == "{")
        {
            if (blocks.size() == 0 || blocks[blocks.size() - 1]->IsComlete())
            {
                blocks.push_back(new DynamicBlock2());
            }
            else
            {
                blocks[blocks.size() - 1]->AddCommand(command);
            }
        }
        else if (command == "}")
        {
            blocks[blocks.size() - 1]->MakeComlete();
        }
        else if (command == "EOF")
        {
            MakeComlete();
            // print
        }
        else
        {
            blocks.push_back(new CommandBlock2(command));
        }

        if (blocks.size() == DynamicBlock2::quantityCommands)
        {
            // print
        }
    }

    void DynamicBlock2::PushBack(Block2 *block)
    {
        if (blocks.size() == 0)
        {
            MarkTime();
        }

        blocks.push_back(block);
    }

    bool DynamicBlock2::IsComlete() const
    {
        return isComlete;
    }

    void DynamicBlock2::MakeComlete()
    {
        this->isComlete = true;

        // save to file
    }

    std::size_t DynamicBlock2::Size() const noexcept
    {
        return blocks.size();
    }

    std::string DynamicBlock2::Front()
    {
        if (pointer < Size())
        {
            return blocks[pointer]->Front();
        }
        return "";
    }

    void DynamicBlock2::Pop()
    {
        if (pointer < Size())
        {
            if (blocks[pointer]->GetBlockType() == BlockType::DynamicBlock)
            {
                blocks[pointer]->Pop();
            }
            else
            {
                ++pointer;
            }
        }
    }

    bool DynamicBlock2::End()
    {
        return pointer == Size();
    }

    void DynamicBlock2::MarkTime()
    {
        auto now = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(now);
    }
}