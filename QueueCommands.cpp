
#include "QueueCommands.h"

namespace otus
{
    QueueCommands::QueueCommands()
    {
        // commands.reserve(quantityCommand);

        auto now = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(now);

        commands.push_back(new ArrayCommands());
    }

    QueueCommands::~QueueCommands()
    {
    }

    void QueueCommands::AddCommand(const std::string &command)
    {
        if (command == "{")
        {
            commands.push_back(new QueueCommands());
        }
        else if (command == "}")
        {
            commands.push_back(new ArrayCommands());
        }
        else if (command == "EOF")
        {
            // print
        }

        commands[commands.size() - 1]->AddCommand(command);
    }

    size_t QueueCommands::Size() const noexcept
    {
        size_t size = 0;
        // for (const auto &block : blocks)
        //{
        //     size += block.get()->Size();
        // }

        return size + commands.size();
    }

    void QueueCommands::Print()
    {
        std::cout << "bulk: ";
        for (const auto &command : commands)
        {
            std::cout << command << ", ";
        }

        commands.clear();

        // if (blocks.size() > 0)
        //{
        //     std::cout << ", ";
        //
        //    for (size_t i = 0; i != blocks.size(); ++i)
        //    {
        //        blocks[i].get()->Print();
        //    }
        //}
    }
}