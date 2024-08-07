#ifndef SIMPLE_INI_H
#define  SIMPLE_INI_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

#include <iosfwd>
#include <cstddef>

namespace j2 { 

// Utility function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, last - first + 1);
}

// Function to parse an INI file
std::map< std::string, std::map<std::string, std::string> > parseINI(const std::string& filename) {
	
    std::ifstream file(filename);
    std::string line;
    std::string currentSection;
    std::map<std::string, std::map<std::string, std::string>> iniData;

    while (std::getline(file, line)) {
        line = j2::trim(line);

        // Skip comments and empty lines
        if (line.empty() || line[0] == ';' || line[0] == '#') {
            continue;
        }

        // Handle section headers
        if (line.front() == '[' && line.back() == ']') {
            currentSection = line.substr(1, line.size() - 2);
        } else {
            // Handle key-value pairs
            size_t equalPos = line.find('=');
            if (equalPos != std::string::npos) {
                std::string key = j2::trim(line.substr(0, equalPos));
                std::string value = j2::trim(line.substr(equalPos + 1));
                iniData[currentSection][key] = value;
            }
        }
    }

   return iniData;
}

} // end of namespace

#endif 
