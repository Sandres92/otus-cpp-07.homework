#include <string>
#include <vector>
#include <queue>

#include "IComand.h"

namespace otus
{
    class ArrayCommands : public ICommand
    {
    public:
        ArrayCommands() = default;
        virtual ~ArrayCommands() = default;

    private:
        size_t pointer = 0;
        std::vector<std::string> commands;

        void AddCommand(const std::string &command) override;
    };
}