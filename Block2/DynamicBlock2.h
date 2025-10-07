#include <vector>

#include "Block2.h"
#include "CommandBlock2.h"

namespace otus
{
    class DynamicBlock2 : public Block2
    {
    private:
        std::vector<Block2 *> blocks;
        bool isComlete = false;

    public:
        DynamicBlock2(/* args */);
        ~DynamicBlock2();

        void AddCommand(const std::string &command) override;

        bool IsComlete() const override;
        void MakeComlete();
    };
}