#include "StaticBlock.h"

namespace otus
{
    StaticBlock::StaticBlock() : DynamicBlock(BlockType::StaticBlock)
    {
    }

    void StaticBlock::AddCommand(const std::string &command)
    {
        if (command == "EOF")
        {
            Print();
            return;
        }
        else if (command == "{")
        {
            if (blocks[blocks.size() - 1]->GetCurrentBlockType() == BlockType::CommnadBlock)
            {
                Print();
            }
        }
        else if (command == "}")
        {
            Print();
        }

        DynamicBlock::AddCommand(command);

        // std::cout << "command " << command << " , " << Size() << "\n";
        if (SizeBlocks() == StaticBlock::quantityCommands)
        {
            // Print();
        }
        if (SizeBlocks() == 0)
        {
            return;
        }
    }

    void StaticBlock::Print()
    {
        std::cout << "bulk: ";
        while (!End())
        {
            std::cout << Front() << ", ";
            Pop();
        }
        std::cout << "\n";

        return;

        if (SizeBlocks() == 0)
        {
            return;
        }

        std::cout << "bulk: ";
        for (size_t i = 0; i != blocks.size(); ++i)
        {
            if (i != 0 && i < (blocks.size() - 1))
            {
                std::cout << ", ";
            }
            else if (i != 0 && i == (blocks.size() - 1) && !blocks[i]->End())
            {
                std::cout << ", ";
            }

            while (!blocks[i]->End())
            {
                std::cout << blocks[i]->Front();
                blocks[i]->Pop();

                if (!blocks[i]->End())
                {
                    std::cout << ", ";
                }
            }
        }
        std::cout << "\n";
    }
}