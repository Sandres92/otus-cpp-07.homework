#include "LogSystem.h"
#include "../Block/DynamicBlock.h"
#include "../Block2/DynamicBlock2.h"

namespace otus
{
    void LogSystem::AddLogger(std::unique_ptr<ILogger> logger)
    {
        loggers.push_back(std::move(logger));
    }

    std::string LogSystem::FormString(const DynamicBlock2 &dynamicBlock)
    {
        return "";
    }

    void LogSystem::Print(const DynamicBlock2 &dynamicBlock)
    {
        // if (dynamicBlock.SizeBlocks() == 0)
        //{
        //     return;
        // }
        //
        // std::cout << "bulk: ";
        //
        // for (size_t i = 0; i != blocks._size_(); ++i)
        //{
        //    if (i != 0 && i < (blocks._size_() - 1))
        //    {
        //        std::cout << ", ";
        //    }
        //    else if (i != 0 && i == (blocks._size_() - 1) && !blocks[i]->End())
        //    {
        //        std::cout << ", ";
        //    }
        //
        //    while (!blocks[i]->End())
        //    {
        //        std::cout << blocks[i]->Front();
        //        blocks[i]->Pop();
        //
        //        if (!blocks[i]->End())
        //        {
        //            std::cout << ", ";
        //        }
        //    }
        //}
        // std::cout << "\n";

        std::string logString = FormString(dynamicBlock);
        std::cout << logString;
    }

    void LogSystem::SaveToFile(const DynamicBlock2 &dynamicBlock)
    {
        std::string logString = FormString(dynamicBlock);
        // save to file
    }
}