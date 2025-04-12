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

    std::vector<std::string> getTasks() const {
        return tasks_vector;
    }
    void setTasks(const std::vector<std::string>& tasks) {
        this->tasks_vector = tasks;
    }
    std::string getFilename() const {
        return filename;
    }
    void setFilename(const std::string& filename) {
        this->filename = filename;
    }

    // default "help" in the main so that it explains the commands by default
    void run(const std::string& command);

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