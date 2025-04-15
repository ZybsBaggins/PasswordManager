#ifndef PASSWORDENTRY_H
#define PASSSWORDENTRY_H

#include <string>

class PasswordEntry{
 private:
  std::string service;
  std::string username;
  std::string password;

 public:
  PasswordEntry(const std:: string& service, const std::string& username, const std::string& password);

  std::string getService() const;
  std::string getUsername() const;
  std::string getPassword() const;

  std::string serialize()const;
  static PasswordEntry deserialize(const std::string& line);
};

#endif

