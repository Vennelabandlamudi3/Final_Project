#include "FileExplorer.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

FileExplorer::FileExplorer(const std::string& logFile) : currentPath("."), logger(logFile) {}

void FileExplorer::listDirectory(const std::string& path) {
    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            logger.log(entry.path().string());
        }
    } else {
        logger.log("Directory does not exist");
    }
}

void FileExplorer::changeDirectory(const std::string& path) {
    if (fs::exists(path) && fs::is_directory(path)) {
        currentPath = path;
        logger.log("Changed directory to: " + path);
    } else {
        logger.log("Directory does not exist");
    }
}

void FileExplorer::createFile(const std::string& path) {
    std::ofstream file(path);
    if (file.is_open()) {
        file.close();
        logger.log("File created: " + path);
    } else {
        logger.log("Failed to create file: " + path);
    }
}

void FileExplorer::createDirectory(const std::string& path) {
    if (fs::create_directory(path)) {
        logger.log("Directory created: " + path);
    } else {
        logger.log("Failed to create directory or it already exists");
    }
}

void FileExplorer::deleteItem(const std::string& path) {
    if (fs::exists(path)) {
        fs::remove_all(path);
        logger.log("Deleted: " + path);
    } else {
        logger.log("Item does not exist: " + path);
    }
}

void FileExplorer::viewFile(const std::string& path) {
    if (fs::exists(path) && fs::is_regular_file(path)) {
        std::ifstream file(path);
        std::string line;
        while (std::getline(file, line)) {
            logger.log(line);
        }
        file.close();
    } else {
        logger.log("File does not exist: " + path);
    }
}
