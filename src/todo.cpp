#include "../include/todo.h"
#include <fstream>

// it is a C++ program that provides a simple command-line interface for managing a todo list.
// It allows users to add, delete, mark tasks as done, search for tasks, filter tasks, and sort tasks.

using namespace std;

vector<string> loadTasks(const string& filename) {
    vector<string> tasks;
    int count_lines = 0;
    // Open the file in read mode
    ifstream file(filename); // input file stream
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            tasks.push_back(line);
            count_lines++;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open this file " << filename << endl;
    }
    // Check how many tasks were loaded
    if (tasks.empty()) {
        cout << "No tasks found in the file." << endl;
    } else {
        cout << "Loaded " << count_lines << " tasks from the file." << endl;
    }
    return tasks;
}

void saveTasks(const string& filename, const vector<string>& tasks) {
    ofstream file(filename); // output file stream
    // Open the file in write mode
    if (file.is_open()) {
        for (const string& task : tasks) { // could use auto instead of string
            file << task << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}
void displayTasks(const vector<string>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}
void addTask(const string& filename, const string& task) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << task << endl;
        file.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
}
void deleteTask(vector<string>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
    } else {
        cerr << "Error: Invalid task index" << endl;
    }
}
void markAsDone(vector<string>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex] += " [done]";
    } else {
        cerr << "Error: Invalid task index" << endl;
    }
}
vector<string> searchTasks(const vector<string>& tasks, const string& keyword) {
    vector<string> results;
    for (const auto& task : tasks) {
        if (task.find(keyword) != string::npos) {
            results.push_back(task);
        }
    }
    return results;
}
void sortTasks(vector<string>& tasks) {
    sort(tasks.begin(), tasks.end());
}
vector<string> filterTasks(const vector<string>& tasks, const string& keyword) {
    vector<string> results;
    for (const auto& task : tasks) {
        if (task.find(keyword) != string::npos) {
            results.push_back(task);
        }
    }
    return results;
}
void displayHelp() {
    cout << "Usage: todo [command] [options]" << endl;
    cout << "Commands:" << endl;
    cout << "  add <task>       Add a new task" << endl;
    cout << "  delete <index>   Delete a task by index" << endl;
    cout << "  done <index>     Mark a task as done" << endl;
    cout << "  search <keyword> Search for tasks containing the keyword" << endl;
    cout << "  filter <keyword> Filter tasks containing the keyword" << endl;
    cout << "  sort            Sort tasks alphabetically" << endl;
    cout << "  help            Display this help message" << endl;
}
void displayAbout() {
    cout << "Todo List Application" << endl;
    cout << "Version 1.0" << endl;
    cout << "Author: Giuseppe Crescenzi" << endl;
    cout << "Description: A simple command-line todo list application." << endl;
}
// this code is intended to be the implementation of a todo.h file, won't work on its own