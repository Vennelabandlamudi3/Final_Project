Project Name:

            
            File Explorer Application

    
Objective:
            The purpose of this project is to create a console-based file explorer application using C++. 
            This application will interact with the Linux operating system to manage files and directories through the command line.

Project Overview: 
                  The file explorer will allow users to perform basic operations such as listing files, navigating between directories, creating and deleting files and directories,
                  copying and moving files, searching for files, and managing file permissions. Additionally, the application will include a logging feature that records all actions 
                  both on the screen and in a text file, ensuring that users can track all operations performed.

TEAM MEMBERS:

             Tharun Vasu Thammisetti
             Vennela Bandlamudi
             Rajat Agarwal


Development Plan:

Day 1: Set up the project, design the basic structure, and implement file listing.

Day 2: Add features for navigating directories.

Day 3: Implement file and directory manipulation functions.

Day 4: Add a search feature to find files within the explorer.

Day 5: Include file permission management capabilities.

Logging Feature:

               The application will have a built-in logger that logs all activities to a text file as well as displaying them on the console.
               Both client and server components will have their own log files.


Main Application Files:

main.cpp:    

               Contains the main function and the primary loop to process user commands.

FileExplorer.cpp:
               
               Contains the implementation of core file operations.

FileExplorer.h:

                Header file that declares the functions for file operations.
 
 Logger.cpp:    
           
                Contains the implementation of the logging functionality.

Logger.h:  

                Header file that declares the logger class and methods.

Makefile: 
                Automates the build process, managing compilation and linking.
                
Execution Instructions:

 Setting Up the Environment:

                 Place the corresponding .cpp and .h files in the src/ directory.

                 Create the logs/ directory where the log files will be stored.

 Compiling the Application:

                 Navigate to the FileExplorerApp directory in the terminal.

 Compile the application using g++:

                 make

 
 Running the Application:

                 ./bin/file_explorer



 Log Files:

                  All operations performed will be logged in logs/client_log.txt.
                
               


















