#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks, const std::string& description);
void viewTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks, int index);
void removeTask(std::vector<Task>& tasks, int index);

int main() {
    std::vector<Task> tasks; 
    int choice;
    std::string description;
    int index;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear input buffer
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> index;
                removeTask(tasks, index - 1);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added.\n";
}


void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description
                  << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}


void markTaskCompleted(std::vector<Task>& tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks[index].completed = true;
    std::cout << "Task marked as completed.\n";
}


void removeTask(std::vector<Task>& tasks, int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + index);
    std::cout << "Task removed.\n";
}
