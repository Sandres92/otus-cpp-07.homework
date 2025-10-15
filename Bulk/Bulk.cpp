#include "Bulk.h"

namespace otus
{
    QuantityCommands_t Bulk::MAX_COMMANDS = 1;

    AddCommandType Bulk::AddCommand(std::string command)
    {
        AddCommandType addCommandType = AddCommandType::ContinueAddCommand;

        if (command == "{")
        {
            if (openDynamic.size() == 0)
            {
                PrintLog(LogType::ConsoleOnly);
            }
            openDynamic.push(commands.size());
        }
        else if (command == "}")
        {
            ++closeDynamic;
            if (openDynamic.size() == closeDynamic)
            {
                PrintLog(LogType::ConsoleAndFile);
                // SaveToFile();
            }
        }
        else if (command == "EOF")
        {
            if (openDynamic.size() == 0)
            {
                PrintLog(LogType::ConsoleOnly);
            }

            addCommandType = AddCommandType::FinishAddCommand;
        }
        else
        {
            if (openDynamic.size() != 0 && commands.size() == 0)
            {
                auto now = std::chrono::system_clock::now();
                auto duration = now.time_since_epoch();
                time = std::chrono::duration_cast<std::chrono::milliseconds>(
                           duration)
                           .count();
            }

            commands.push_back(command);

            if (openDynamic.size() == 0 &&
                commands.size() == Bulk::MAX_COMMANDS)
            {
                PrintLog(LogType::ConsoleOnly);
            }
        }

        return addCommandType;
    }

    void Bulk::PrintLog(LogType logType)
    {
        if (commands.size() == 0)
        {
            return;
        }

        std::ostringstream stream;

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

        commands.clear();

        if (logType == LogType::ConsoleOnly)
        {
            LogSystem3::Print(stream);
        }
        else if (logType == LogType::FileOnly)
        {
            LogSystem3::SaveToFile(time, stream);
        }
        else if (logType == LogType::ConsoleAndFile)
        {
            LogSystem3::Print(stream);
            LogSystem3::SaveToFile(time, stream);
        }
    }
}