#include "FileLogger.h"

namespace otus
{
    void FileLogger::SaveToFile(std::string fileName, const std::ostringstream &stream) const
    {
        std::ofstream out(fileName, std::ios::out);
        if (out.is_open())
        {
            out << stream.str();
        }
        out.close();
    }
}