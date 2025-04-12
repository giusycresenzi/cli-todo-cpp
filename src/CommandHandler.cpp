#include "../include/CommandHandler.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

CommandHandler::~CommandHandler() {
    // Save tasks to file when the CommandHandler object is destroyed
    saveTasks(filename, tasks_vector);
    cout << "Tasks saved to " << filename << endl;
}

void CommandHandler::run(const string& command) {
    string inputCommand = command;
    while (inputCommand != "exit") {
        if (inputCommand == "help") {
            displayHelp();
        } else if (inputCommand == "about") {
            displayAbout();
        } else if (inputCommand == "list") {
            displayTasks(tasks_vector);
        } else if (inputCommand == "add") {
            add();
        } else if (inputCommand == "delete") {
            del();
        } else if (inputCommand == "done") {
            done();
        } else if (inputCommand == "search") {
            vector<string> search_result = search();
            displayTasks(search_result);
        } else if (inputCommand == "sort") {
            sort();
        } else {
            cout << "Unknown command. Type 'help' for a list of commands." << endl;
        }
        cout << "Enter command: ";
        getline(cin, inputCommand);
    }
    saveTasks(filename, tasks_vector);
    cout << "Tasks saved to " << filename << endl;
    cout << "Exiting application. Goodbye!" << endl;
}

void CommandHandler::displayHelp() {
    cout << "Usage: todo [command] [options]" << endl;
    cout << "Commands:" << endl;
    cout << "  list             Display all tasks" << endl;
    cout << "  add <task>       Add a new task" << endl;
    cout << "  delete           Delete a task by index or full name" << endl;
    cout << "  done             Mark a task as done by index or full name" << endl;
    cout << "  search           Search for tasks containing the keyword" << endl;
    cout << "  sort             Sort tasks alphabetically" << endl;
    cout << "  help             Display this help message" << endl;
    cout << "  about            Display information about the application" << endl;
    cout << "  exit             Exit the application" << endl;
}
void CommandHandler::displayAbout() {
    cout << "Todo List Application" << endl;
    cout << "Version 1.0" << endl;
    cout << "Author: Giuseppe Crescenzi, giusycrescenzi on GitHub" << endl;
    cout << "Description: A simple command-line todo list application." << endl;
}

void CommandHandler::add() {
    string task;
    cout << "Enter task: ";
    getline(cin, task);
    addTask(tasks_vector, task); // Assuming addTask is defined in todo.h
}

void CommandHandler::del() {
    string identifier;
    cout << "Enter the task number or name to delete: ";
    getline(cin, identifier);

    // Check if the input is a number (index)
    if (all_of(identifier.begin(), identifier.end(), ::isdigit)) {
        // Input is a number, call deleteTask by index
        int taskIndex = stoi(identifier);
        deleteTask(tasks_vector, taskIndex);
    } else {
        // Input is a string, call deleteTask by task name
        deleteTask(tasks_vector, identifier);
    }
}

void CommandHandler::done() {
    string identifier;
    cout << "Enter the task number or name to mark as done: ";
    getline(cin, identifier);
    if (all_of(identifier.begin(), identifier.end(), ::isdigit)) {
        int taskNumber = stoi(identifier);
        markAsDone(tasks_vector, taskNumber);
    } else {
        markAsDone(tasks_vector, identifier);
    }
    
}

vector<string> CommandHandler::search() {
    string keyword;
    cout << "Enter keyword to search: ";
    getline(cin, keyword);
    return searchTasks(tasks_vector, keyword);
}

void CommandHandler::sort() {
    sortTasksAlphabetic(tasks_vector);
    cout << "Tasks sorted alphabetically." << endl;
    displayTasks(tasks_vector); // Display sorted tasks
}