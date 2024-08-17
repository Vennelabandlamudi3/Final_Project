#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <string>

class FileExplorer {
public:
    static void listDirectory(const std::string &path);
    static void createFile(const std::string &path);
    static void createDirectory(const std::string &path);
    static void copyItem(const std::string &source, const std::string &destination);
    static void moveItem(const std::string &source, const std::string &destination);
    static void deleteItem(const std::string &path);
    static void searchFile(const std::string &path, const std::string &filename);
    static void changePermissions(const std::string &path, const std::string &permissions);
};

#endif
