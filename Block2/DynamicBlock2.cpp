#include "DynamicBlock2.h"

namespace otus
{
    DynamicBlock2::DynamicBlock2(/* args */) : Block2(BlockType::DynamicBlock)
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
        }
        else
        {
            blocks.push_back(new CommandBlock2());
        }
    }

    bool DynamicBlock2::IsComlete() const
    {
        return true;
    }

    void DynamicBlock2::MakeComlete()
    {
        this->isComlete = true;
    }
}