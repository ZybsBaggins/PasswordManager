#include "Bank.h"
#include "HiddenInput.cpp"
#include <iostream>

int main() {
 std::string masterPassword = getHiddenInput("Enter master password: ");
 //std::getline(std::cin, masterPassword);

 Bank bank(masterPassword);
 bank.loadFromFile("bank.dat");

 std::string command;
 while(true) {
  std::cout << "\nCommands: add, view, list, delete, save, exit\n>";
  std::getline(std::cin, command);

   if (command == "add") {
    std::string service, user, pass;
    std::cout << "Service: ";
    std::getline(std::cin, service);
    std::cout << "Username: ";
    std::getline(std::cin, user);
    std::cout << "Password: ";
    std::getline(std::cin, pass);
    bank.addEntry(PasswordEntry(service, user, pass));
   }
   else if (command == "view") {
    std::string service;
    std::cout << "Service to view: ";
    std::getline(std::cin, service);
    bank.viewEntry(service);
   }
   else if (command == "list") {
    bank.listEntries();
   }
   else if (command == "delete") {
    std::string service;
    std::cout << "Service to delete: ";
    std::getline(std::cin, service);
    bank.deleteEntry(service);
   }
   else if (command == "save") {
    bank.saveToFile("bank.dat");
    std::cout << "Bank saved \n";
   }
   else if (command == "exit") {
    break;
   }
   else {
    std::cout << "Unknown command\n";
   }
 }

 return 0;
}
