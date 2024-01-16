#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        std::cout << "Task '" << description << "' added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks found.\n";
        } else {
            std::cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << "\n";
            }
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task '" << tasks[taskIndex - 1].description << "' marked as completed.\n";
        } else {
            std::cout << "Invalid task index. Please provide a valid index.\n";
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            std::cout << "Task '" << tasks[taskIndex - 1].description << "' removed successfully.\n";
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            std::cout << "Invalid task index. Please provide valid index.\n";
        }
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        std::cout << "\nTask Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice between (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter the task you want to add in this: ";
                std::cin.ignore();  // Clear input buffer
                std::getline(std::cin, taskDescription);
                taskManager.addTask(taskDescription);
                break;
            }
            case 2:
                taskManager.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                taskManager.viewTasks();
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> taskIndex;
                taskManager.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                taskManager.viewTasks();
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> taskIndex;
                taskManager.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting Task Manager. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
//codsoft c++