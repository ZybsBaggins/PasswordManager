#include "PasswordEntry.h"
#include <sstream>

PasswordEntry::PasswordEntry(const std::string& service, const std::string& username, const std::string& password)
  : service(service), username(username), password(password) {}

std::string PasswordEntry::getService() const { return service; }
std::string PasswordEntry::getUsername() const { return username; }
std::string PasswordEntry::getPassword() const { return password; }

std::string PasswordEntry::serialize() const {
 return service + "|" + username + "|" + password;
}

PasswordEntry PasswordEntry::deserialize(const std::string& line) {
 std::stringstream ss(line);
 std::string service, username, password;
 std::getline(ss, service, '|');
 std::getline(ss, username, '|');
 std::getline(ss, password, '|');
 return PasswordEntry(service, username, password);
}
