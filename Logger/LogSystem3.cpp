#include "LogSystem3.h"

namespace otus
{
    // void LogSystem3::AddLogger(std::unique_ptr<ILogger> logger)
    //{
    //     loggers.push_back(std::move(logger));
    // }
    //
    // void LogSystem3::Print(const std::ostringstream &stream)
    //{
    //    std::cout << "bulk " << &stream << "\n";
    //}
    //
    // void LogSystem3::SaveToFile(std::time_t time, const std::ostringstream &stream)
    //{
    //    std::cout << time << "\n";
    //    return;
    //
    //    std::ofstream out;
    //
    //    auto t = std::put_time(std::localtime(&time), "%F %T");
    //
    //    std::string fileName = "bulk_" + t + "log";
    //    out.open(fileName);
    //    if (out.is_open())
    //    {
    //        out << &stream << "\n";
    //    }
    //    out.close();
    //}
}