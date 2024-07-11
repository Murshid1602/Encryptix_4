#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a Task
struct Task {
    string description;
    bool completed;
};

// Class to manage the To-Do List
class ToDoList {
private:
    vector<Task> tasks; // Vector to store tasks

public:
    // Function to display all tasks
    void displayTasks() {
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i].completed ? "[x] " : "[ ] ") << tasks[i].description << endl;
        }
    }

    // Function to add a new task
    void addTask(const string& desc) {
        Task newTask;
        newTask.description = desc;
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "Task added successfully." << endl;
    }

    // Function to edit an existing task
    void editTask(int index, const string& desc) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].description = desc;
            cout << "Task edited successfully." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Function to remove a task
    void removeTask(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Function to mark a task as completed
    void markCompleted(int index) {
        if (index > 0 && index <= tasks.size()) {
            if (!tasks[index - 1].completed) {
                tasks[index - 1].completed = true;
                cout << "Task marked as completed." << endl;
            } else {
                cout << "Task is already completed." << endl;
            }
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList myToDoList;
    int choice;
    string taskDescription;
    int editIndex, removeIndex, completeIndex;

    do {
        // Display menu to the user
        cout << "\nMenu:\n1. Display tasks\n2. Add task\n3. Edit task\n4. Remove task\n5. Mark task as completed\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myToDoList.displayTasks();
                break;
            case 2:
                cout << "Enter task description: ";
                cin.ignore(); // Clear newline from previous input
                getline(cin, taskDescription);
                myToDoList.addTask(taskDescription);
                break;
            case 3:
                cout << "Enter task number to edit: ";
                cin >> editIndex;
                cout << "Enter new task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                myToDoList.editTask(editIndex, taskDescription);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> removeIndex;
                myToDoList.removeTask(removeIndex);
                break;
            case 5:
                cout << "Enter task number to mark as completed: ";
                cin >> completeIndex;
                myToDoList.markCompleted(completeIndex);
                break;
            case 6:
                cout << "Exiting. Have a great day!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


