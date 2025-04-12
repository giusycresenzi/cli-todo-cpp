
#include "../include/todo.h"
#include "../include/CommandHandler.h"

int main() {
    std::cout << "Welcome to the CLI Todo App!" << std::endl;

    CommandHandler commandHandler;
    commandHandler.run();

    return 0;
}