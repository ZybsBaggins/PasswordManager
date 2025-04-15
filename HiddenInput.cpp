#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>

std::string getHiddenInput(const std::string& prompt) {
 std::cout << prompt;
 termios oldt, newt;
 std::string password;

 // Turn off echo:
 tcgetattr(STDIN_FILENO, &oldt);
 newt = oldt;
 newt.c_lflag &= ~ECHO;
 tcsetattr(STDIN_FILENO, TCSANOW, &newt);

 std::getline(std::cin, password);

 // Turn on echo again
 tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
 std::cout << std::endl;

 return password;
}
