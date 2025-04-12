#ifndef TODO_H
#define TODO_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// all tasks are in the todo.txt file, each is a string

// THOSE TWO FUNCTIONS ARE FOR LOADING AND SAVING TASKS ON THE .TXT FILE
//load tasks from file to a vector that we'll be using
vector<string> loadTasks(const string& filename);
// over-writes the file with the current vector
void saveTasks(const string& filename, const vector<string>& tasks);

// ALL THE FOLLOWING ACT ON THE VECTOR
void displayTasks(const vector<string>& tasks);
//add a new task from the command line
void addTask(vector<string>& tasks, const string& task);
void deleteTask(vector<string>& tasks, int taskNumber);
void deleteTask(vector<string>& tasks, const string& task); // overload to delete by task name
void markAsDone(vector<string>& tasks, int taskNumber);
void markAsDone(vector<string>& tasks, const string& task); // overload to mark as done by task name
// search for a task by keyword
vector<string> searchTasks(const vector<string>& tasks, const string& keyword);
void sortTasksAlphabetic(vector<string>& tasks);

#endif