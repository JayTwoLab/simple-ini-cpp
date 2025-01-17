
#include "simple-ini.h"

int main() {

    const std::string filename = "config.ini";
    auto iniData = j2::parseINI(filename);

    if ( iniData.size() <= 0 ) {
	    std::cout << " Failed to load file : " << filename << std::endl;
	    return 0;
    }

    // Accessing data from the parsed INI file
    if (iniData.find("user") != iniData.end()) {
        std::string name = iniData["user"]["name"];
        int age = std::stoi(iniData["user"]["age"]);
        bool isAdmin = (iniData["user"]["admin"] == "true");

        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Admin: " << std::boolalpha << isAdmin << "\n";
    } else {
        std::cout << "No 'user' section found in INI file.\n";
    }

    return 0;
}

