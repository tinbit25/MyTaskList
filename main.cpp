#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;


string descriptions[MAX_TASKS];
int priorities[MAX_TASKS];
int numTasks = 0;

void displayMenu() {
    cout << "===== Self-Management System =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Complete" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Edit Task" << endl;
    cout << "6. Search Task" << endl;
    cout << "7. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Please enter your choice: ";
}

void addTask() {
    if (numTasks == MAX_TASKS) {
        cout << "Task list is full. Cannot add more tasks." << endl;
        return;
    }

    string description;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);
    descriptions[numTasks] = description;

    int priority;
    cout << "Enter the priority for the task (1 - low, 2 - medium, 3 - high): ";
    cin >> priority;
    priorities[numTasks] = priority;

    numTasks++;

    cout << "Task added successfully!" << endl;
}


void viewTasks() {
    if (numTasks == 0) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (int i = 0; i < numTasks; i++) {
        cout << "Task #" << i + 1 << ": " << descriptions[i] << " (Priority: " << priorities[i] << ")" << endl;
    }
}


void markTaskComplete() {
    if (numTasks == 0) {
        cout << "No tasks found." << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the index of the task to mark as complete: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > numTasks) {
        cout << "Invalid task index. Please try again." << endl;
        return;
    }
    for (int i = taskIndex - 1; i < numTasks - 1; i++) {
        descriptions[i] = descriptions[i + 1];
        priorities[i] = priorities[i + 1];
    }

    numTasks--;

    cout << "Task marked as complete." << endl;
}


void deleteTask() {
    if (numTasks == 0) {
        cout << "No tasks found." << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the index of the task to delete: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > numTasks) {
        cout << "Invalid task index. Please try again." << endl;
        return;
    }


    for (int i = taskIndex - 1; i < numTasks - 1; i++) {
        descriptions[i] = descriptions[i + 1];
        priorities[i] = priorities[i + 1];
    }

    numTasks--;

    cout << "Task deleted." << endl;
}


void editTask() {
    if (numTasks == 0) {
        cout << "No tasks found." << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the index of the task to edit: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > numTasks) {
        cout << "Invalid task index. Please try again." << endl;
        return;
    }

    cin.ignore();

    string newDescription;
    cout << "Enter the new description for the task: ";
    getline(cin, newDescription);
    descriptions[taskIndex - 1] = newDescription;

    int newPriority;
    cout << "Enter the new priority for the task (1 - low, 2 - medium, 3 - high): ";
    cin >> newPriority;
    priorities[taskIndex - 1] = newPriority;

    cout << "Task updated." << endl;
}


void searchTask() {
    if (numTasks == 0) {
        cout << "No tasks found." << endl;
        return;
    }

    string keyword;
    cout << "Enter the keyword to search for: ";
    cin.ignore();
    getline(cin, keyword);

    int count = 0;
    for (int i = 0; i < numTasks; i++) {
        if (descriptions[i].find(keyword) != string::npos) {
            cout << "Task #" << i + 1 << ": " << descriptions[i] << " (Priority: " << priorities[i] << ")" << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "No matching tasks found." << endl;
    }

}

int main() {

string validUsername = "tinbite";
    string validPassword = "123";

    string username, password;

    cout << "\t\t\t\t\t\t   LOGIN" << endl;
    cout << "\t\t\t\t\t\t============" << endl;


    cout << "\t\t\t\t\t\tEnter username\n ";
    cout<<"\t\t\t\t\t\t";
    cin >> username;
    cout << "\t\t\t\t\t\tEnter password\n ";
    cout<<"\t\t\t\t\t\t";
    cin >> password;


    if (username == validUsername && password == validPassword) {

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskComplete();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                editTask();
                break;
            case 6:
                searchTask();
                break;
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 7);
    }
 else {
        cout << "Authentication failed. Invalid username or password." << endl;
    }
    return 0;
    }

