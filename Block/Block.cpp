#include "Block.h"

namespace otus
{
    Block::Block(BlockType blockType) : blockType(blockType)
    {
    }

    void Block::Reset()
    {
        pointer = 0;
    }

    BlockType Block::GetBlockType() const
    {
        return blockType;
    }

    bool Block::IsComlete() const
    {
        return isComlete;
    }

    void Block::MakeComlete()
    {
        isComlete = true;
    }
}