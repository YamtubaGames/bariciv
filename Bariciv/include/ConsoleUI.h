#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <string>
#include <iostream> // TODO: Switch to stdio instead of iostream for performance reasons

class ConsoleUI
{
    public:
        ConsoleUI();
        virtual ~ConsoleUI();

        void Message(std::string Text);
        std::string Prompt();
        std::string Prompt(std::string Text);
        void PromptBare();

    protected:

    private:
};

#endif // CONSOLEUI_H
