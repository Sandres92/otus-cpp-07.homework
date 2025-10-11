#include "Block3.h"

namespace otus
{
    void Block3::AddCommand(std::string command)
    {
        if (command == "{")
        {
            if (openDynamic.size() == 0)
            {
                std::cout << "11111111111111\n";
                Print();
            }
            openDynamic.push(commands.size());
        }
        else if (command == "}")
        {
            ++closeDynamic;
            if (openDynamic.size() == closeDynamic)
            {
                Print();
                // SaveToFile();
            }
        }
        else if (command == "EOF")
        {
            if (openDynamic.size() == 0)
            {
                Print();
            }
        }
        else
        {
            if (openDynamic.size() == 1 && commands.size() == 0)
            {
                auto now = std::chrono::system_clock::now();
                time = std::chrono::system_clock::to_time_t(now);
            }

            commands.push_back(command);

            if (openDynamic.size() == 0 && commands.size() == 3)
            {
                Print();
            }
        }
    }

    void Block3::Print()
    {
        if (commands.size() == 0)
        {
            return;
        }

        std::ostringstream stream;

        stream << "bulk: ";
        for (size_t i = 0; i != commands.size(); ++i)
        {
            stream << commands[i];

            if (i != commands.size() - 1)
            {
                stream << ", ";
            }

            if (openDynamic.size() > 0 && i == openDynamic.front())
            {
                openDynamic.pop();
                --closeDynamic;
                stream << "\n";
            }
        }
        stream << "\n";

        commands.clear();

        std::cout << stream.str();
    }

    void Block3::SaveToFile()
    {
        std::cout << "bulk: ";
        for (size_t i = 0; i != commands.size(); ++i)
        {
            std::cout << commands.front();

            if (i != commands.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}