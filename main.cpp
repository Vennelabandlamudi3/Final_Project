#include "FileExplorer.h"
#include "Logger.h"
#include <iostream>

void displayMenu() {
    std::cout << "File Explorer Menu:\n"
              << "1. List directory contents (ls)\n"
              << "2. Create a file (createfile)\n"
              << "3. Create a directory (createdir)\n"
              << "4. Copy an item (copy)\n"
              << "5. Move an item (move)\n"
              << "6. Delete an item (delete)\n"
              << "7. Search for a file (search)\n"
              << "8. Change file permissions (chmod)\n"
              << "Type 'exit' to quit the application.\n";
}

std::string getUserCommand() {
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;
    return command;
}

void processCommand(const std::string &command, const std::string &path, Logger &logger) {
    if (command == "ls") {
        logger.log("Listing directory contents...");
        FileExplorer::listDirectory(path);
    } else if (command == "createfile") {
        std::string filePath;
        std::cout << "Enter file path: ";
        std::cin >> filePath;
        logger.log("Creating file: " + filePath);
        FileExplorer::createFile(filePath);
    } else if (command == "createdir") {
        std::string dirPath;
        std::cout << "Enter directory path: ";
        std::cin >> dirPath;
        logger.log("Creating directory: " + dirPath);
        FileExplorer::createDirectory(dirPath);
    } else if (command == "copy") {
        std::string source, destination;
        std::cout << "Enter source path: ";
        std::cin >> source;
        std::cout << "Enter destination path: ";
        std::cin >> destination;
        logger.log("Copying from " + source + " to " + destination);
        FileExplorer::copyItem(source, destination);
    } else if (command == "move") {
        std::string source, destination;
        std::cout << "Enter source path: ";
        std::cin >> source;
        std::cout << "Enter destination path: ";
        std::cin >> destination;
        logger.log("Moving from " + source + " to " + destination);
        FileExplorer::moveItem(source, destination);
    } else if (command == "delete") {
        std::string deletePath;
        std::cout << "Enter path to delete: ";
        std::cin >> deletePath;
        logger.log("Deleting item at " + deletePath);
        FileExplorer::deleteItem(deletePath);
    } else if (command == "search") {
        std::string searchPath, filename;
        std::cout << "Enter path to search in: ";
        std::cin >> searchPath;
        std::cout << "Enter filename to search for: ";
        std::cin >> filename;
        logger.log("Searching for " + filename + " in " + searchPath);
        FileExplorer::searchFile(searchPath, filename);
    } else if (command == "chmod") {
        std::string targetPath, permissions;
        std::cout << "Enter path: ";
        std::cin >> targetPath;
        std::cout << "Enter permissions (e.g., 755): ";
        std::cin >> permissions;
        logger.log("Changing permissions of " + targetPath + " to " + permissions);
        FileExplorer::changePermissions(targetPath, permissions);
    } else {
        logger.log("Unknown command: " + command);
        std::cout << "Unknown command.\n";
    }
}

int main() {
    Logger logger("logs/client_log.txt");
    std::string command;
    while (true) {
        displayMenu();
        command = getUserCommand();
        if (command == "exit") {
            break;
        }
        processCommand(command, ".", logger);
    }
    return 0;
}
