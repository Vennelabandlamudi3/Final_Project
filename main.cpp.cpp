#include <iostream>
#include "FileExplorer.h"

void displayMenu() {
    std::cout << "File Explorer Menu:\n";
    std::cout << "1. List directory contents (ls)\n";
    std::cout << "2. Change directory (cd)\n";
    std::cout << "3. Create a file (createfile)\n";
    std::cout << "4. Create a directory (createdir)\n";
    std::cout << "5. Delete a file/directory (delete)\n";
    std::cout << "6. View file contents (viewfile)\n";
    std::cout << "Type 'exit' to quit the application.\n";
}

std::string getUserCommand() {
    std::string command;
    std::cout << "Enter command: ";
    std::getline(std::cin, command);
    return command;
}

int main() {
    FileExplorer explorer("file_explorer.log");

    std::string command;
    bool isRunning = true;

    while (isRunning) {
        displayMenu();
        command = getUserCommand();

        if (command == "exit") {
            isRunning = false;
        } else if (command == "ls") {
            explorer.listDirectory(".");
        } else if (command == "cd") {
            std::string path;
            std::cout << "Enter directory path: ";
            std::getline(std::cin, path);
            explorer.changeDirectory(path);
        } else if (command == "createfile") {
            std::string path;
            std::cout << "Enter file path: ";
            std::getline(std::cin, path);
            explorer.createFile(path);
        } else if (command == "createdir") {
            std::string path;
            std::cout << "Enter directory path: ";
            std::getline(std::cin, path);
            explorer.createDirectory(path);
        } else if (command == "delete") {
            std::string path;
            std::cout << "Enter path to delete: ";
            std::getline(std::cin, path);
            explorer.deleteItem(path);
        } else if (command == "viewfile") {
            std::string path;
            std::cout << "Enter file path: ";
            std::getline(std::cin, path);
            explorer.viewFile(path);
        } else {
            std::cout << "Invalid command.\n";
        }
    }

    std::cout << "Exiting application.\n";
    return 0;
}
