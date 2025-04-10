#ifndef TODO_H
#define TODO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// all tasks are in the todo.txt file, each is a string
//load tasks
vector<string> loadTasks(const string& filename);

//save tasks
void saveTasks(const string& filename, const vector<string>& tasks);

// display all tasks
void displayTasks(const vector<string>& tasks);

//add a new task
void addTask(const string& filename, const string& task);

// remove a task
void deleteTask(vector<string>& tasks, int taskIndex);

// mark as done
void markAsDone(vector<string>& tasks, int taskIndex);

// search for a task
vector<string> searchTasks(const vector<string>& tasks, const string& keyword);

// sort tasks
void sortTasks(vector<string>& tasks);

// filter tasks
vector<string> filterTasks(const vector<string>& tasks, const string& keyword);

// display help
void displayHelp();

// display about
void displayAbout();


#endif