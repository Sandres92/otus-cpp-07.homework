
#include "QueueCommands.h"

namespace otus
{
    QueueCommands::QueueCommands()
    {
        // commands.reserve(quantityCommand);

        auto now = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(now);

        blocks.push_back(new ArrayCommands());
        ++numBlock;
    }

    QueueCommands::~QueueCommands()
    {
    }

    void QueueCommands::AddCommand(const std::string &command)
    {
        if (command == "{")
        {
            blocks.push_back(new QueueCommands());
            return;
        }
        else if (command == "}")
        {
            blocks.push_back(new ArrayCommands());
            return;
        }
        else if (command == "EOF")
        {
            Print();
            return;
        }

        std::cout << command << "\n";
        blocks[blocks.size() - 1]->AddCommand(command);
    }

    size_t QueueCommands::Size() const noexcept
    {
        size_t size = 0;
        for (const auto &block : blocks)
        {
            size += block->Size();
        }

        return size;
    }

    void QueueCommands::Print()
    {
        std::cout << "\n";

        std::cout << "bulk: ";
        // for (const auto &command : commands)
        //{
        //     std::cout << command << ", ";
        // }
        //
        // commands.clear();

        // if (blocks.size() > 0)
        //{
        //     std::cout << ", ";
        //
        //    for (size_t i = 0; i != blocks.size(); ++i)
        //    {
        //        blocks[i].get()->Print();
        //    }
        //}

        for (size_t i = 0; i != blocks.size(); ++i)
        {
            while (!blocks[i]->End())
            {
                // std::cout << "numBlock " << numBlock << " pointer = " << pointer << " , " << blocks[i]->Front() << "\n";

                std::cout << blocks[i]->Front() << " ";
                blocks[i]->Pop();
            }
        }
    }

    std::string QueueCommands::Front()
    {
        // std::cout << "\n"
        //           << "numBlock " << numBlock << " pointer = "
        //           << pointer << " , "
        //           << blocks[pointer]->Front() << "\n";

        if (pointer < blocks.size())
        {
            return blocks[pointer]->Front();
        }

        // std::cout << "numBlock " << numBlock << "\n";

        return "";
    }

    void QueueCommands::Pop()
    {
        if (!blocks[pointer]->End())
        {
            blocks[pointer]->Pop();
            if (blocks[pointer]->End())
            {
                ++pointer;
            }
        }
    }

    bool QueueCommands::End()
    {
        return pointer == blocks.size();
    }
} //