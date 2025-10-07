#pragma once

#include <iostream>
#include <string>

#include "../Block/BlockType.h"

namespace otus
{
    class Block2
    {
    private:
    protected:
        std::size_t pointer = 0;
        BlockType blockType;

    public:
        explicit Block2(BlockType blockType);
        virtual ~Block2() = default;

        virtual void AddCommand(const std::string &command) = 0;

        virtual std::size_t Size() const noexcept = 0;

        virtual std::string Front() = 0;
        virtual void Pop() = 0;
        virtual bool End() = 0;

        virtual bool IsComlete() const = 0;
        virtual void MakeComlete();

        void Reset();
        BlockType GetBlockType() const;
        // virtual BlockType GetCurrentBlockType() const = 0;
        // virtual BlockType GetNextBlockType() const = 0;
    };
}