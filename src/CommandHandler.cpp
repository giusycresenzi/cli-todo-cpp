#include '/include/CommandHandler.h'
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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
void addTask(vector<string>& tasks, const string& task) {
    tasks.push_back(task);
    cout << "Task added: " << task << endl;
}

void deleteTask(vector<string>& tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Invalid index. Task not deleted." << endl;
        return;
    }
    cout << "Task deleted: " << tasks[index] << endl;
    tasks.erase(tasks.begin() + index);
}

void markTaskDone(vector<string>& tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        cout << "Invalid index. Task not marked as done." << endl;
        return;
    }
    tasks[index] += " [DONE]";
    cout << "Task marked as done: " << tasks[index] << endl;
}

void searchTasks(const vector<string>& tasks, const string& keyword) {
    cout << "Search results for \"" << keyword << "\":" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].find(keyword) != string::npos) {
            cout << i << ": " << tasks[i] << endl;
        }
    }
}

void filterTasks(const vector<string>& tasks, const string& keyword) {
    cout << "Filtered tasks containing \"" << keyword << "\":" << endl;
    for (const auto& task : tasks) {
        if (task.find(keyword) != string::npos) {
            cout << task << endl;
        }
    }
}

void sortTasks(vector<string>& tasks) {
    sort(tasks.begin(), tasks.end());
    cout << "Tasks sorted alphabetically." << endl;
}