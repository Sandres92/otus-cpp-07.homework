#pragma once

#include "Bulk.h"

namespace otus
{
    class Bulk_moc : public Bulk
    {
    private:
    public:
        Bulk_moc() = default;
        ~Bulk_moc() = default;

        std::vector<std::string> GetCommands_Moc() const;
    };
}