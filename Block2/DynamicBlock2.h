#include <vector>
#include <chrono>

#include "Block2.h"
#include "CommandBlock2.h"

namespace otus
{
    using QuantityCommands_t = size_t;
    class DynamicBlock2 : public Block2
    {
    private:
        static inline QuantityCommands_t quantityCommands = 1;

        std::vector<Block2 *> blocks;
        bool isComlete = false;

        std::time_t time;
        std::size_t pointer = 0;

    public:
        DynamicBlock2();
        ~DynamicBlock2();

        void AddCommand(const std::string &command) override;

        std::string Front() override;
        void Pop() override;
        bool End() override;

        bool IsComlete() const override;
        void MakeComlete();

        void PushBack(Block2 *block);

        std::size_t Size() const noexcept override;

        void MarkTime();

        static void SetQuantityCommands(QuantityCommands_t _quantityCommands)
        {
            quantityCommands = _quantityCommands;
        }

        // template <typename It>
        // class DynamicBlockIterator
        //{
        // private:
        //     It curr;
        //     It currOut;
        //
        // public:
        //    DynamicBlockIterator() = default;
        //    DynamicBlockIterator(It it) : curr(it), currOut(it)
        //    {
        //        if ((this->curr)->GetBlockType() == BlockType::DynamicBlock)
        //        {
        //            currOut = this->curr;
        //            this->curr = *currOut->begin();
        //        }
        //    }
        //    ~DynamicBlockIterator() = default;
        //
        //    bool operator==(const DynamicBlockIterator &it)
        //    {
        //        return it == curr;
        //    }
        //    bool operator!=(const DynamicBlockIterator &it)
        //    {
        //        return it != curr;
        //    }
        //
        //    DynamicBlockIterator &operator++()
        //    {
        //        ++(this->curr);
        //        if (this->curr.GetBlockType() == BlockType::DynamicBlock)
        //        {
        //            currOut = this->curr;
        //            this->curr = currOut.begin();
        //        }
        //
        //        if (this->currOut.GetBlockType() == BlockType::DynamicBlock &&
        //            this->curr == this->currOut.end())
        //        {
        //            this->curr = this->currOut;
        //            ++(this->curr);
        //        }
        //
        //        return *this;
        //    }
        //
        //    std::string operator*() const
        //    {
        //        return this->curr->Front();
        //    }
        //};
        //
        // DynamicBlockIterator<decltype(blocks.begin())> begin() noexcept
        //{
        //    DynamicBlockIterator<decltype(blocks.begin())> it(blocks.begin());
        //    return it;
        //}
        //
        // DynamicBlockIterator<decltype(blocks.begin())> end() noexcept
        //{
        //    DynamicBlockIterator<decltype(blocks.begin())> it(blocks.end());
        //    return it;
        //}
    };
}