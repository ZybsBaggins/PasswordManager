#ifndef BANK_H
#define BANK_H

#include "PasswordEntry.h"
#include <vector>
#include <string>

class Bank {
 private:
  std::vector<PasswordEntry> entries;
  std::string encryptionKey;

  std::string encrypt(const std::string& text) const;
  std::string decrypt(const std::string& text) const;

 public:
  Bank(const std::string& masterPassword);

  void addEntry(const PasswordEntry& entry);
  void deleteEntry(const std::string& service);
  void listEntries() const;
  void viewEntry(const std::string& service) const;

  void saveToFile(const std::string& filename) const;
  void loadFromFile(const std::string& filename);
};

#endif
