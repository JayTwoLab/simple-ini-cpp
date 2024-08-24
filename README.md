# simple-ini-cpp

- Simple INI parser for C++ 17

## How to Use

- Just include header file ```simple-ini.h``` 

## Example 

- config.ini

```ini
[user]
name=John
age=99
admin=true
```

- main.cpp

```cpp
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
```

## License

- ```simple-ini``` is under MIT License. https://github.com/JayTwoLab/simple-ini-cpp/

- It is a part of JayTwo(j2) Library.
