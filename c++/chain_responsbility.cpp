#include <iostream>
#include <vector>
class BaseHandler
{
    public:
    virtual BaseHandler *SetNext(BaseHandler *BaseHandler) = 0;
    virtual std::string Handle(std::string request) = 0;
};

class AbstractHandler : public BaseHandler
{
    private:
    BaseHandler *next_handler;
    public:
    AbstractHandler(): next_handler(nullptr){}
    BaseHandler* SetNext(BaseHandler* handler) override 
    {
        this->next_handler = handler;
        return handler;
    }

    std::string Handle(std::string request) override
    {
        if(this->next_handler)
        {
            return this->next_handler->Handle(request);
        }
        return {};
    }
};

class MonkeyHandler: public AbstractHandler
{
    public:
    std::string Handle(std::string request) override
    {
        if (request == "Banana")
        {
            return "Monkey: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class SquirrelHandler: public AbstractHandler
{
    public:
    std::string Handle(std::string request) override
    {
        if (request == "Nut")
        {
            return "Squirrel: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class DogHandler: public AbstractHandler
{
    public:
    std::string Handle(std::string request) override
    {
        if (request == "MeatBall")
        {
            return "Dog: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

void ClientCode(BaseHandler &handler)
{
    std::vector<std::string> food = {"Nut", "Banana", "Cup of coffee"};
    for (const std::string& f : food)
    {
        std::cout << "Who wants to eat this " << f << std::endl;
        const std::string result = handler.Handle(f);
        if(!result.empty())
        {
            std::cout << "  " << result;
        }
        else
        {
            std::cout << "  " << f << " was left untouched\n";
        }
    }
}


int main()
{
    MonkeyHandler* Monkey = new MonkeyHandler;
    SquirrelHandler* Squirrel = new SquirrelHandler;
    DogHandler* Dog = new DogHandler;
    Monkey->SetNext(Squirrel)->SetNext(Dog);

    std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
    ClientCode(*Monkey); 
    std::cout <<"\nSubChain: Squirrel > Dog\n\n";
    ClientCode(*Squirrel);
    delete Dog;
    delete Squirrel;
    delete Monkey;
    return 0;
}


