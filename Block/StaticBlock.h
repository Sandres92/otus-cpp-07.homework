#include "DynamicBlock.h"
#include "BlockType.h"
#include "Block.h"

namespace otus
{
    using QuantityCommands_t = size_t;

    class StaticBlock : public DynamicBlock
    {
    private:
        static inline QuantityCommands_t quantityCommands = 0;

    public:
        explicit StaticBlock();
        virtual ~StaticBlock() = default;

        void AddCommand(const std::string &command) override;
        void Print();

        static void SetQuantityCommands(QuantityCommands_t _quantityCommands)
        {
            quantityCommands = _quantityCommands;
        }
    };
}