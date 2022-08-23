#pragma once
#include <string>

class MemberAccount {
public:
	MemberAccount(long accID, std::string First, std::string Last, std::string Phone, long long Balance);

	long AccountID = 0;
	std::string FirstName;
	std::string LastName;
	std::string PhoneNumber;
	long long AccountBalance = 0;

	std::string CreateEntry();
	std::string UpdateEntry();
	std::string ReadEntry();
};