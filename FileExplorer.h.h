#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <string>
#include "Logger.h"

class FileExplorer {
public:
    FileExplorer(const std::string& logFile);
    void listDirectory(const std::string& path);
    void changeDirectory(const std::string& path);
    void createFile(const std::string& path);
    void createDirectory(const std::string& path);
    void deleteItem(const std::string& path);
    void viewFile(const std::string& path);

private:
    std::string currentPath;
    Logger logger;
};

#endif // FILEEXPLORER_H
