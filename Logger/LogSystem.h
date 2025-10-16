#pragma once

#include <memory>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>

#include "IFileLogger.h"
#include "IConsoleLogger.h"

namespace otus
{
    class LogSystem
    {
    private:
        static std::vector<std::unique_ptr<IConsoleLogger>> consoleLoggers;
        static std::vector<std::unique_ptr<IFileLogger>> fileLoggers;

    public:
        static void AddConsoleLogger(std::unique_ptr<IConsoleLogger> consoleLogger)
        {
            consoleLoggers.push_back(std::move(consoleLogger));
        }

        static void AddFileLogger(std::unique_ptr<IFileLogger> fileLogger)
        {
            fileLoggers.push_back(std::move(fileLogger));
        }

        static void Print(const std::ostringstream &stream)
        {
            for (size_t i = 0; i != consoleLoggers.size(); ++i)
            {
                consoleLoggers[i]->Print(stream);
            }
        }

        static void SaveToFile(int64_t time, const std::ostringstream &stream)
        {
            std::string fileName = "bulk_" + std::to_string(time) + ".log";
            for (size_t i = 0; i != fileLoggers.size(); ++i)
            {
                fileLoggers[i]->SaveToFile(fileName, stream);
            }
        }
    };
}