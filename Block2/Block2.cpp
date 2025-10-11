#include "Block2.h"

namespace otus
{
    Block2::Block2(BlockType blockType) : blockType(blockType)
    {
    }

    void Block2::Reset()
    {
    }

    BlockType Block2::GetBlockType() const
    {
    }

    bool Block2::IsComlete() const
    {
        return true;
    }

    void Block2::MakeComlete() {}
}