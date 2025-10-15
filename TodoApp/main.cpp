

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Task class to represent each to-do item
class Task {
public:
    string description;

    Task(string desc) {
        description = desc;
    }

   void display(int index) const {
    cout << index + 1 << ". " << description << endl;
}
};

// Function declarations
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks, const string& filename);
void loadTasks(vector<Task>& tasks, const string& filename);

int main() {
    vector<Task> tasks;  // STL vector to store Task objects
    string filename = "Joe_tasks.txt";

    loadTasks(tasks, filename);  // Load tasks from file on startup

    int choice;
    do {
        // Menu
        cout << "\n====== TO-DO LIST MANAGER ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Save Tasks\n";
        cout << "5. Load Tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline left in input buffer

        // Conditionals and function calls
        if (choice == 1) {
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            removeTask(tasks);
        } else if (choice == 4) {
            saveTasks(tasks, filename);
        } else if (choice == 5) {
            loadTasks(tasks, filename);
        } else if (choice != 0) {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    saveTasks(tasks, filename);  // Auto-save on exit
    cout << "Goodbye!\n";

    return 0;
}

// Add task
void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    getline(cin, desc);  // Read full line
    tasks.push_back(Task(desc));  // Expressions & class usage
    cout << "Task added.\n";
}

// View all tasks

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
    } else {
        cout << "\nYour Tasks:\n";
        for (size_t i = 0; i < tasks.size(); i++) {  // Loop
            tasks[i].display(i);
        }
    }
}

// Remove a task by index
void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    // Conditionals
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
    cin.ignore();  // Clear input buffer
}

// Save tasks to file
void saveTasks(const vector<Task>& tasks, const string& filename) {
    ofstream outFile(filename);  // File output
    for (const Task& task : tasks) {
        outFile << task.description << endl;
    }
    outFile.close();
    cout << "Tasks saved to " << filename << ".\n";
}

// Load tasks from file
void loadTasks(vector<Task>& tasks, const string& filename) {
    ifstream inFile(filename);  // File input
    string line;
    tasks.clear();  // Clear old tasks

    while (getline(inFile, line)) {
        if (!line.empty()) {
            tasks.push_back(Task(line));
        }
    }
    inFile.close();
    cout << "Tasks loaded from " << filename << ".\n";
}
