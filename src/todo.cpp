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
        cerr << "Error: Unable to open this file: " << filename << endl;
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
    cout << "Your tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ") " << tasks[i] << endl;
    }
}
void addTask(vector<string>& tasks, const string& task) {
    tasks.push_back(task); // Add the task to the vector
    cout << "Task added: " << task << endl;
}
void deleteTask(vector<string>& tasks, int taskNumber) {
    int taskIndex = taskNumber - 1; // Convert to zero-based index
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
    } else {
        cerr << "Error: Invalid task number" << endl;
    }
}
void deleteTask(vector<string>& tasks, const string& task) {
    auto it = find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        tasks.erase(it);
    } else {
        cerr << "Error: Task not found" << endl;
    }
}
void markAsDone(vector<string>& tasks, int taskNumber) {
    int taskIndex = taskNumber - 1;
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex] += " [done]";
    } else {
        cerr << "Error: Invalid task index" << endl;
    }
}
void markAsDone(vector<string>& tasks, const string& task) {
    auto it = find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        *it += " [done]";
    } else {
        cerr << "Error: Task not found" << endl;
    }
}
vector<string> searchTasks(const vector<string>& tasks, const string& keyword) {
    vector<string> results;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].find(keyword) != string::npos) {
            results.push_back(tasks[i]);
        }
    }
    return results;
}
void sortTasksAlphabetic(vector<string>& tasks) {
    sort(tasks.begin(), tasks.end());
}

// this code is intended to be the implementation of a todo.h file, won't work on its own