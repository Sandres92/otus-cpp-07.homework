#include <memory>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>

#include "ILogger.h"

namespace otus
{
    class LogSystem3
    {
    private:
        static std::vector<std::unique_ptr<ILogger>> loggers;

    public:
        static void AddLogger(std::unique_ptr<ILogger> logger)
        {
            loggers.push_back(std::move(logger));
        }

        static void Print(const std::ostringstream &stream)
        {
            // std::cout << "bulk " << &stream << "\n";
            if (stream)
            {
            }
        }

        static void SaveToFile(int64_t time, const std::ostringstream &stream)
        {
            if (time && stream)
            {
            }
            // std::string fileName0 = "bulk_" + std::to_string(time) + ".log";
            // std::cout << fileName0 << "\n";

            std::ofstream out;
            std::string fileName;
            out.open(fileName);
            if (out.is_open())
            {
                out << &stream << "\n";
            }
            out.close();
        }
    };
}