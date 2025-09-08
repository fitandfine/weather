/*
 * Weather CLI
 *
 * Simple command-line program to fetch weather information for a given city
 * using the wttr.in API. Demonstrates basic C++ I/O, string handling,
 * and executing system commands.
 *
 * Build: g++ -std=c++17 weather.cpp -o weather
 *
 * Usage:
 *   ./weather London
 *   ./weather "New York"
 */

#include <iostream>
#include <string>

// Function to build and run the curl command
void getWeather(const std::string &city) {
    // wttr.in API - outputs weather in plain text
    std::string command = "curl -s wttr.in/" + city + "?format=3";

    // Run the command using system()
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Failed to fetch weather. Please check your internet connection.\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <city>\n";
        return 1;
    }

    std::string city = argv[1];
    getWeather(city);

    return 0;
}
