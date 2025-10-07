#pragma once

#include <iostream>
#include <string>

#include "BlockType.h"

namespace otus
{
    class Block
    {
    private:
    protected:
        std::size_t pointer = 0;
        BlockType blockType;
        bool isComlete = false;

    public:
        explicit Block(BlockType blockType);
        virtual ~Block() = default;

        virtual void AddCommand(const std::string &command) = 0;

        virtual std::size_t SizeElements() const noexcept = 0;
        virtual std::size_t SizeBlocks() const noexcept = 0;

        virtual std::string Front() = 0;
        virtual void Pop() = 0;
        virtual bool End() = 0;

        bool IsComlete() const;
        virtual void MakeComlete();

        void Reset();
        BlockType GetBlockType() const;
        virtual BlockType GetCurrentBlockType() const = 0;
        virtual BlockType GetNextBlockType() const = 0;
    };
}