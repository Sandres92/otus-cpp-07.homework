
#include "CustomQueue.h"

namespace otus
{
    CustomQueue::CustomQueue(QuantityCommandType quantityCommand)
        : quantityCommand(quantityCommand)
    {
        commands.reserve(quantityCommand);
        time = 0;

        // auto now = std::chrono::system_clock::now();
        // auto in_time_t = std::chrono::system_clock::to_time_t(now);
    }

    CustomQueue::~CustomQueue()
    {
    }

    void CustomQueue::AddCommand(std::string command)
    {
        if (command == "{")
        {
            // new CustomQueue
        }
        else if (command == "}")
        {
            // print
        }
        else if (command == "EOF")
        {
            // print
        }
        else
        {
            commands.push_back(command);

            if (commands.size() == 3)
            {
                // print
            }
        }
    }

    size_t CustomQueue::Size() const noexcept
    {
        size_t size = 0;
        for (const auto &block : blocks)
        {
            size += block.get()->Size();
        }

        return size + commands.size();
    }

    void CustomQueue::Print()
    {
        std::cout << "bulk: ";
        for (const auto &command : commands)
        {
            std::cout << command << ", ";
        }

        commands.clear();

        if (blocks.size() > 0)
        {
            std::cout << ", ";

            for (size_t i = 0; i != blocks.size(); ++i)
            {
                blocks[i].get()->Print();
            }
        }
    }
}