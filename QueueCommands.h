
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>

#include "Command/IComand.h"
#include "Command/ArrayCommands.h"

namespace otus
{
    using QuantityCommandType = size_t;

    class QueueCommands : ICommand
    {
    private:
        static inline QuantityCommandType quantityCommand = 0;

        std::vector<ICommand *> commands;
        std::time_t time;
        size_t pointer = 0;

    public:
        QueueCommands();
        ~QueueCommands();

        void AddCommand(const std::string &command) override;

        size_t Size() const noexcept;

        void Front();
        void Pop();

        void Print();
    };
}