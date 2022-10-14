#include <iostream.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;
int main()
{
    // Change the color of background to black
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);

    // Change the color of the text to green
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

    // Abort the program if the user presses CTRL+C
    SetConsoleCtrlHandler(NULL, TRUE);

    // Security check [1]
    // Abort if the user is not running Windows NT or later
    if (GetVersion() < 0x80000000)
    {
        cout << "This program requires Windows NT or later." << endl;
        return 1;
    }

    // Security check [2]
    // CHECKING FOR ADMINISTRATOR PERMISSIONS (ELEVATED PRIVILEGES)
    // Abort if the user does not have administrative rights
    if (!IsUserAnAdmin())
    {
        cout << "This program requires administrative rights." << endl;
        return 1;
    }

    // Security check [3]
    // CHECKING FOR ADMINISTRATOR PERMISSIONS (ELEVATED PRIVILEGES)
    // Abort if the user does not have sufficient rights
    if (!IsUserAdmin())
    {
        cout << "This program requires sufficient rights." << endl;
        return 1;
    }

    // clear the screen
    system("cls");

    // Security check [4]
    // Abort if there is any pending reboot
    if (IsPendingReboot())
    {
        cout << "This program cannot run while the system is rebooting." << endl;
        return 1;
    }

    // Set the title of the window
    SetConsoleTitle("CLEAN WIN");

    // Display the copyright notice
    // Display the version number
    // Display the date of last update
    // Display the author's name
    // Display the author's email address
    // Display the author's website
    // Display the author's GitHub repository
    // Lets the user know that the program is running

    cout << "Copyright (c) 2021-2022, KARTHIK LAL" << endl;
    cout << "Version 2.1" << endl;
    cout << "Last updated: 2022-09-06" << endl;
    cout << "Author: KARTHIK LAL" << endl;
    cout << "Email: karthik.lal558@gmail.com" << endl;
    cout << "Website: karthiklal.live" << endl;
    cout << "GitHub: https://github.com/karthik558" << endl;

    // Checking if choco is installed or not
    if (system("choco -v") == 0)
    {
        cout << "Chocolatey is installed." << endl;
    }
    else
    {
        cout << "Chocolatey is not installed." << endl;
    }

    // Ask the user if they want to install choco or not (Y/N)
    cout << "Do you want to install Chocolatey? (Y/N): ";
    char choco;
    cin >> choco; // get the user's input and store it in the variable git

    // If the user enters Y or y, then install choco
    if (choco == 'Y' || choco == 'y')
    {
        // Install choco
        system("powershell -Command \"Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))\"");
    }
    else
    {
        cout << "Chocolatey is not installed." << endl;
    }

    // Checking if git is installed or not
    if (system("git --version{") == 0)
    {
        cout << "Git is already installed on this PC" << endl;
    }
    else
    {
        cout << "Git is not installed on this PC" << endl; // Displaying a message
    }

    // Ask the user if they want to install git or not (Y/N)
    char git; // git is a variable of type char
    cout << "Do you want to install git? (Y/N): ";
    cin >> git; // get the user's input and store it in the variable git

    // If the user enters Y or y, then install git
    if (git == 'Y' || git == 'y')
    {
        cout << "Installing git..." << endl;
        system("choco install git -y");
        cout << "git has been installed." << endl;
    }
    // If the user enters N or n, then do not install git
    else if (git == 'N' || git == 'n')
    {
        cout << "git will not be installed." << endl;
    }
    // If the user enters anything other than Y, y, N or n, then display an error message
    else
    {
        cout << "Invalid input." << endl;
    }
    // Check if git is installed on the system or not
    // If git is not installed, then install it and then continue the program execution
    if (system("git --version") != 0)
    {
        cout << "Git is not installed on your system." << endl;
        cout << "Installing Git..." << endl;
        system("choco install git");
    }

    // If user wants to pull the latest changes from the GitHub repository then do clone the repository and then pull the latest changes from the GitHub repository
    // If user does not want to pull the latest changes from the GitHub repository then do clone the repository and then do not pull the latest changes from the GitHub repository
    cout << "Do you want to pull the latest changes from the GitHub repository? (y/n): ";
    char choice; // variable to store the user's choice
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Pulling the latest changes from the GitHub repository..." << endl;
        system("git clone https://github.com/karthik558/clean-windows && cd clean-windows && git pull");
    }
    else
    {
        cout << "Continuing the program execution..." << endl;
        // Continue the below program execution without pulling the latest changes from the GitHub repository
    }

    // Lets the user know that the program is running
    cout << "LET'S START THE SCRIPT...." << endl;

    // Clear the screen
    system("cls");

    // Run the script on full screen mode
    system("start /max /wait clean-win.exe");

    // Welcome to the script again and wait for 3 seconds
    cout << "YOU ARE USING KARTHIK LAL WINDOWS CLEAN SCRIPT" << endl;
    Sleep(2000);

    // Print the EULA Agreement and wait for 3 seconds
    cout << "EULA Agreement - Please read the following EULA agreement." << endl;
    cout << "[1] This script is provided as is with no warranty of any kind. The author is not responsible for any damage caused by this script." << endl;
    cout << "[2] This script is designed to clean up the Windows operating system." << endl;
    cout << "[3] This operation may take a few minutes/hours to complete." << endl;
    cout << "[4] [4] Please do not close the console window until the script is finished." << endl;
    cout << "[5] This script is fully automated and does not require any user input to complete. (after accepting the EULA)" << endl;
    cout << "[6] This script will not clean up the following: " << endl;
    cout << "[*] Windows Defender" << endl;
    cout << "[*] Windows Defender Antivirus" << endl;
    cout << "[*] Windows Defender Online" << endl;
    cout << "[*] Windows Defender SmartScreen " << endl;
    cout << "[*] Windows Defender Trust Center " << endl;
    cout << "[*] Windows Defender Web Scan " << endl;

    // Wait for 3 seconds
    Sleep(3000);

    cout << "Do you accept the EULA agreement? (y/n)" << endl;
    char answer;   // Variable to store the user's answer
    cin >> answer; // Get the user's answer

    if answer
        == 'y'
        {
            // Clear the screen
            system("cls");
            cout << "EULA Agreement accepted. Starting the script.." << endl;
        }
    else
    {
        // Clear the screen
        system("cls");
        cout << "EULA Agreement rejected. Exiting the script.." << endl;
        return 0;
    }

    // Print the banner before starting the script
    cout << "██╗  ██╗ █████╗ ██████╗ ████████╗██╗  ██╗██╗██╗  ██╗" << endl;
    cout << "██║ ██╔╝██╔══██╗██╔══██╗╚══██╔══╝██║  ██║██║██║ ██╔╝" << endl;
    cout << "█████╔╝ ███████║██████╔╝   ██║   ███████║██║█████╔╝" << endl;
    cout << "██╔═██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║██╔═██╗" << endl;
    cout << "██║  ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║██║  ██╗" << endl;
    cout << "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝" << endl;

    cout << "███████╗ ██████╗██████╗ ██╗██████╗ ████████╗" << endl;
    cout << "██╔════╝██╔════╝██╔══██╗██║██╔══██╗╚══██╔══╝" << endl;
    cout << "███████╗██║     ██████╔╝██║██████╔╝   ██║" << endl;
    cout << "╚════██║██║     ██╔══██╗██║██╔═══╝    ██║" << endl;
    cout << "███████║╚██████╗██║  ██║██║██║        ██║" << endl;
    cout << "╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝╚═╝        ╚═╝" << endl;

    // Wait for 3 seconds
    Sleep(3000);

    // End explorer.exe processs
    system("taskkill /f /im explorer.exe");
    cout << "BYE BYE EXPLORER.exe" << endl;
    Sleep(1000);

    // Clear DNS cache
    system("ipconfig /flushdns");
    cout << "DNS cache cleared" << endl;
    Sleep(1000);

    // Remove all .log files from the system
    system("del /q /s /f /a /t /c *.log");
    cout << "All .log files removed" << endl;
    Sleep(1000);

    // Remove all .tmp files from the system
    system("del /q /s /f /a /t /c *.tmp");
    cout << "All .tmp files removed" << endl;
    Sleep(1000);

    // Remove all *.tmp files from the system
    system("del /q /s /f /a /t /c *.tmp");
    cout << "All *.tmp files removed" << endl;
    Sleep(1000);

    // Remove all _mp_*.tmp files from the system
    system("del /q /s /f /a /t /c _mp_*.tmp");
    cout << "All _mp_*.tmp files removed" << endl;
    Sleep(1000);

    // Remove all *_mp.tmp files from the system
    system("del /q /s /f /a /t /c *_mp.tmp");
    cout << "All *_mp.tmp files removed" << endl;
    Sleep(1000);

    // Remove all *.log files from the system
    system("del /q /s /f /a /t /c *.log");
    cout << "All *.log files removed" << endl;
    Sleep(1000);

    // Remove all *.gid files from the system
    system("del /q /s /f /a /t /c *.gid");
    cout << "All *.gid files removed" << endl;
    Sleep(1000);

    // Remove all *.chk files from the system
    system("del /q /s /f /a /t /c *.chk");
    cout << "All *.chk files removed" << endl;
    Sleep(1000);

    // Remove all .old files from the system
    system("del /q /s /f /a /t /c *.old");
    cout << "All .old files removed" << endl;
    Sleep(1000);

    // Remove all *.old files from the system
    system("del /q /s /f /a /t /c *.old");
    cout << "All *.old files removed" << endl;
    Sleep(1000);

    // Clear recycled files from the system
    system("del /q /s /f /a /t /c *.~*");
    cout << "All *.~* files removed" << endl;
    Sleep(1000);

    // Remove all .bak files from the system
    system("del /q /s /f /a /t /c *.bak");
    cout << "All *.bak files removed" << endl;
    Sleep(1000);

    // Remove all *.bak files from the system
    system("del /q /s /f /a /t /c *.bak");
    cout << "All *.bak files removed" << endl;
    Sleep(1000);

    // Clear prefetch files from the system
    system("del /q /s /f /a /t /c *.pf");
    cout << "All *.pf files removed" << endl;
    Sleep(1000);

    // Remove all temp files from the windows directory
    system("del /q /s /f /a /t /c *.tmp");
    cout << "All *.tmp files removed" << endl;
    Sleep(1000);

    // Remove all default stored cookies from the system
    system("del /q /s /f /a /t /c cookies.txt");
    cout << "All cookies.txt files removed" << endl;
    Sleep(1000);

    // Remove all temporary_internet_files from the system
    system("del /q /s /f /a /t /c temporary_internet_files");
    cout << "All temporary_internet_files files removed" << endl;
    Sleep(1000);

    // Remove all recent files from the system
    system("del /q /s /f /a /t /c recent");
    cout << "All recent files removed" << endl;
    Sleep(1000);

    // Scanning all protected system files, and replacing corrupted files
    system("sfc /scannow");
    cout << "Scanning all protected system files, and replacing corrupted files" << endl;
    Sleep(1000);

    // Print out the directory_tree_list
    system("dir /s");
    cout << "Directory tree list printed" << endl;
    Sleep(1000);

    // Clear all the system restore points
    system("del /q /s /f /a /t /c *.restore");
    cout << "All *.restore files removed" << endl;
    Sleep(1000);

    // Clear the screen
    system("cls");

    // End the script
    cout << "Thank you for using my script" << endl;
    cout << "Regards KARTHIK LAL" << endl;
    Sleep(4000);

    // Restart explorer.exe processs
    system("explorer.exe");
    cout << "Welcome back explorer.exe " << endl;
    Sleep(500);

    // Removing temp and %temp% directories from the system
    system("rmdir /s /q temp");
    cout << "temp directory removed" << endl;
    Sleep(1000);
    system("rmdir /s /q %temp%");
    cout << "%temp% directory removed" << endl;
    Sleep(1000);

    // Removing temp and %temp% directories from the %userprofile% directory
    system("rmdir /s /q %userprofile%\\temp");
    cout << "%userprofile%\\temp directory removed" << endl;
    Sleep(1000);
    system("rmdir /s /q %userprofile%\\%temp%");
    cout << "%userprofile%\\%temp% directory removed" << endl;
    Sleep(1000);

    // Clear the windows run history
    reg = "reg delete \"HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU\" /f";
    system(reg.c_str());
    cout << "Windows run history cleared" << endl;
    Sleep(1000);

    // Print out the bye banner
    cout << "    ▄████████    ▄████████    ▄████████      ▄██   ▄    ▄██████▄ ███    █▄" << endl;
    cout << "  ███    ███   ███    ███   ███    ███      ███   ██▄ ███    ███ ███    ███" << endl;
    cout << "███      █▀    ███    █▀    ███    █▀       ███▄▄▄███ ███    ███ ███    ███ " << endl;
    cout << "███           ▄███▄▄▄       ███▄▄▄          ▀▀▀▀▀▀███ ███    ███ ███    ███ " << endl;
    cout << "▀███████████ ▀▀███▀▀▀     ▀▀███▀▀▀          ▄██   ███ ███    ███ ███    ███" << endl;
    cout << "         ███   ███    █▄    ███    █▄       ███   ███ ███    ███ ███    ███" << endl;
    cout << "   ▄█    ███   ███    ███   ███    ███      ███   ███    ███     █████████" << endl;
    cout << " ▄████████▀    ██████████   ██████████       ▀█████▀   ▀██████▀  ████████▀" << endl;

    // To the end of the script
    Sleep(1500);
    getch();
    return 0;
}

/*================================================================
AUTHOR: KARTHIK LAL & :: EMAIL: karthik.lal558@gmail.com
DATE: 10-06-2022
WINDOWS CLEANER SCRIPT - STABLE VERSION
TOOLS ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND AND THE AUTHOR IS NOT RESPONSIBLE FOR ANY DAMAGE CAUSED BY THE USE OF THESE TOOLS
USE AT YOUR OWN RISK
FORCED TO RUN ONLY WITH ADMINISTRATOR PRIVILEGES.
[
DEPENDENCIES FOR RUNNING THIS SCRIPT:
WINDOWS MACHINE (7, 8, 8.1, 10, 11)
GIT (https://git-scm.com/download/win)
CHOCOLATEY (CHOCLATEY.ORG)
]
[
DEPENDENCIES FOR COMPILING THIS SCRIPT:
VISUAL STUDIO CODE (https://code.visualstudio.com/download)
VISUAL STUDIO CODE EXTENSIONS:
C/C++ (MICROSOFT)
C/C++ INTELLISENSE (MICROSOFT)
C/C++ SNIPPETS (TOMMY)
GNU COMPILER COLLECTION (MICROSOFT)
CODE RUNNER (FORMERLY RUN CODE) (JUN HO)
C/C++ FORMATTER (MICROSOFT)
]
LICESNSE: GNU GENERAL PUBLIC LICENSE V3.0
OPENSOURCE SOFTWARE LICENSE AGREEMENT FOR WINDOWS DISTRIBUTION SYSTEM (https://www.gnu.org/licenses/gpl-3.0.en.html)
Copying and distribution of this file, with or without modification, are permitted in any medium without royalty provided the copyright notice and this notice are preserved.
Copyright (c) 2022 KARTHIK LAL
================================================================*/