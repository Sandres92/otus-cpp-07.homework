#pragma once

#include <string>
#include <vector>
#include <queue>

#include "Block.h"

namespace otus
{
    class CommandsBlock : public Block
    {
    public:
        explicit CommandsBlock();
        virtual ~CommandsBlock() = default;

        static inline int countBlock = 0;

    private:
        int idBlock = 0;

        std::vector<std::string> commands;

        void AddCommand(const std::string &command) override;

        size_t SizeElements() const noexcept override;
        size_t SizeBlocks() const noexcept override;

        std::string Front() override;

        void Pop() override;
        bool End() override;

        BlockType GetCurrentBlockType() const override;
        BlockType GetNextBlockType() const override;
    };
}