#include <string>

#include "Block2.h"

namespace otus
{
    class CommandBlock2 : public Block2
    {
    private:
        std::string command;

    public:
        CommandBlock2(/* args */);
        ~CommandBlock2();

        void AddCommand(const std::string &command) override;
        bool IsComlete() const override;

        std::string Front() override;
        void Pop() override;
        bool End() override;

        size_t Size() const noexcept override;
    };
}