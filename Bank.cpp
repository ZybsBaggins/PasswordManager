#include "Bank.h"
#include <fstream>
#include <iostream>
#include <algorithm>

Bank::Bank(const std::string& masterPassword) : encryptionKey(masterPassword) {}

std::string Bank::encrypt(const std::string& text) const {
 std:: string result = text;
 for (size_t i = 0; i < result.size(); ++i)
  result[i] ^= encryptionKey[i % encryptionKey.size()];
 return result;
}

std::string Bank::decrypt(const std::string& text) const {
 return encrypt(text); //xor symmetric
}

void Bank::saveToFile(const std::string& filename) const {
 std::ofstream ofs(filename, std::ios::binary);
 if (!ofs) {
  std::cerr << "Could not open file \n";
  return;
 }

 for (const auto& entry : entries) {
  std::string serialized = entry.serialize();
  std::string encrypted = encrypt(serialized);
  ofs << encrypted << "\n";
 }
}

void Bank::addEntry(const PasswordEntry& entry) {
 entries.push_back(entry);
}

void Bank::deleteEntry(const std::string& service) {
 entries.erase(std::remove_if(entries.begin(), entries.end(),
  [&](const PasswordEntry& e) {return e.getService() == service; }),
  entries.end());
}

void Bank::listEntries() const {
 if (entries.empty()) {
  std::cout << "Vault is empty.\n";
  return;
 }
 for (const auto& e : entries)
  std::cout << "- " << e.getService() << "\n";
}

void Bank::viewEntry(const std::string& service) const {
 for (const auto& e : entries) {
  if (e.getService() == service) {
   std::cout << "Service: " << e.getService() << "\n";
   std::cout << "Username: " << e.getUsername() << "\n";
   std::cout << "Password: " << e.getPassword() << "\n";
   return;
  }
 }
 std::cout << "Entry not found. \n";
}

void Bank::loadFromFile(const std::string& filename) {
 std::ifstream in(filename);
 if (!in) return;

 std::string line;
 while (std::getline(in, line)) {
  std::string decrypted = decrypt(line);
  entries.push_back(PasswordEntry::deserialize(decrypted));
 }
 in.close();
}


