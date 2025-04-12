#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "todo.h"
#include <string>

class CommandHandler {
public:
    // Default c'tor
    CommandHandler() : filename("todo.txt") {
        tasks_vector = loadTasks(filename);
    }
    //overloaded c'tor to allow for different file names if needed
    CommandHandler(const std::string& filename) : filename(filename) {
        tasks_vector = loadTasks(filename);
    }

    // Destructor
    ~CommandHandler();

    // default "help" so that it explains the commands by default
    void handleCommands(const std::string& command = "help", std::vector<std::string> tasks, std::string filename = "todo.txt");

private:
    std::vector<std::string> tasks_vector; // we will be using this to store and manipulate the tasks
    std::string filename; // the name of the file to save the tasks (in this case todo.txt)

    void displayHelp();
    void displayAbout();
    void add();
    void del();
    void done();
    std::vector<std::string> search();
    void sort();
    void exit();
};
#endif // COMMAND_HANDLER_H