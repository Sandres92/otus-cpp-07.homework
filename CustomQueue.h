
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>

namespace otus
{
    using QuantityCommandType = size_t;

    class CustomQueue
    {
    private:
        QuantityCommandType quantityCommand = 0;
        std::vector<std::string> commands;
        int time;
        std::vector<std::unique_ptr<CustomQueue>> blocks;

    public:
        CustomQueue(QuantityCommandType quantityCommand);
        ~CustomQueue();

        void AddCommand(std::string command);

        size_t Size() const noexcept;

        void Front();
        void Pop();

        void Print();
    };
}