#include "FileExplorer.h"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void FileExplorer::listDirectory(const std::string &path) {
    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto &entry : fs::directory_iterator(path)) {
            std::cout << entry.path().filename().string() << std::endl;
        }
    } else {
        std::cerr << "Directory does not exist." << std::endl;
    }
}

void FileExplorer::createFile(const std::string &path) {
    std::ofstream ofs(path);
    if (ofs) {
        std::cout << "File created successfully." << std::endl;
    } else {
        std::cerr << "Failed to create file." << std::endl;
    }
}

void FileExplorer::createDirectory(const std::string &path) {
    if (fs::create_directory(path)) {
        std::cout << "Directory created successfully." << std::endl;
    } else {
        std::cerr << "Failed to create directory." << std::endl;
    }
}

void FileExplorer::copyItem(const std::string &source, const std::string &destination) {
    try {
        fs::copy(source, destination, fs::copy_options::recursive);
        std::cout << "Item copied successfully." << std::endl;
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void FileExplorer::moveItem(const std::string &source, const std::string &destination) {
    try {
        fs::rename(source, destination);
        std::cout << "Item moved successfully." << std::endl;
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void FileExplorer::deleteItem(const std::string &path) {
    try {
        fs::remove_all(path);
        std::cout << "Item deleted successfully." << std::endl;
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void FileExplorer::searchFile(const std::string &path, const std::string &filename) {
    try {
        for (const auto &entry : fs::recursive_directory_iterator(path)) {
            if (entry.path().filename() == filename) {
                std::cout << "Found: " << entry.path().string() << std::endl;
            }
        }
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void FileExplorer::changePermissions(const std::string &path, const std::string &permissions) {
    try {
        fs::perms perm = static_cast<fs::perms>(std::stoul(permissions, nullptr, 8));
        fs::permissions(path, perm);
        std::cout << "Permissions changed successfully." << std::endl;
    } catch (fs::filesystem_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
