namespace otus
{
    class ICommand
    {
    private:
    public:
        ICommand() = default;
        virtual ~ICommand() = default;

        virtual void AddCommand(const std::string &command) = 0;
    };
}