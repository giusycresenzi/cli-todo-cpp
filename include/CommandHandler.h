#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>

// Function declarations for each command
void displayHelp();
void displayAbout();
void addTask(const std::string& task);
void removeTask(int taskId);
void listTasks();
void markTaskComplete(int taskId);
void clearCompletedTasks();

#endif // COMMAND_HANDLER_H