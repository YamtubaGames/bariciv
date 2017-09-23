#include "ConsoleUI.h"

ConsoleUI::ConsoleUI()
{
    //ctor
}

ConsoleUI::~ConsoleUI()
{
    //dtor
}

void ConsoleUI::Message(std::string Text)
{
    std::cout << Text << std::endl;
}

std::string ConsoleUI::Prompt()
{
    PromptBare();
    std::string outstring;
    std::getline(std::cin, outstring);
    return outstring;
}

std::string ConsoleUI::Prompt(std::string Text)
{
    std::cout << Text << " ";
    return Prompt();
}

void ConsoleUI::PromptBare()
{
    std::cout << "> ";
}
