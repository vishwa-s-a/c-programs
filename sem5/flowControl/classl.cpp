#include <iostream> 
#include <cstdlib> 
#include <cstring> 
std::string ip_classless(const std::string& ip_address) { 
 int i, j, k;
 int octets[4];
 std::string mask;
 int bits = 0;
 for (i = 0, j = 0, k = 0; i < ip_address.length(); i++) {
 if (ip_address[i] == '.') { 
 octets[j++] = std::stoi(ip_address.substr(k, i - k));
 k = i + 1;
 } 
 } 
 octets[j] = std::stoi(ip_address.substr(k));
 for (i = 0; i < 4; i++) {
 int octet = octets[i];
 for (j = 7; j >= 0; j--) { 
 if (octet >= (1 << j)) { 
 bits++;
 octet -= (1 << j);
 } else if (bits % 8 != 0) { 
 break;
 } 
 } 
 } 
 mask = ip_address + "/" + std::to_string(bits);
 return mask;
} 
int main() { 
 std::string ip_address;
 std::cout << "Enter an IP address in classful notation: ";
 std::cin >> ip_address;
std::cout << "Classless address: " << ip_classless(ip_address) << std::endl;
 return 0;
}