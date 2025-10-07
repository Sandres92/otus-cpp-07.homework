#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <queue>

#include "Block.h"
#include "CommandsBlock.h"
#include "BlockType.h"

namespace otus
{
    class DynamicBlock : public Block
    {
    private:
        size_t numBlock = 0;

        std::time_t time;
        int idBlock = 0;

    protected:
        std::vector<Block *> blocks;

    public:
        static inline int countBlock = 0;

        explicit DynamicBlock();
        explicit DynamicBlock(BlockType blockType);
        virtual ~DynamicBlock() = default;

        void AddCommand(const std::string &command) override;

        size_t SizeElements() const noexcept override;
        size_t SizeBlocks() const noexcept override;

        BlockType GetCurrentBlockType() const override;
        BlockType GetNextBlockType() const override;

        std::string Front() override;
        void Pop() override;
        bool End() override;

        void MakeComlete() override;

        bool currenDynamic = false;
    };
}