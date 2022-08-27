#include "MemberAccount.h"


MemberAccount::MemberAccount(long accID, std::string First, std::string Last, std::string Phone, long long Balance)
{
	AccountID = accID;
	FirstName = First;
	LastName = Last;
	PhoneNumber = Phone;
	AccountBalance = Balance;
}

std::string MemberAccount::CreateEntry()
{
	std::string rval;
	std::string delim = "\t";
	rval.append(std::to_string(AccountID))
		.append(delim)
		.append(FirstName)
		.append(delim)
		.append(LastName)
		.append(delim)
		.append(PhoneNumber)
		.append(delim)
		.append(std::to_string(AccountBalance))
		.append("\n");
	return rval;
}

std::string MemberAccount::UpdateEntry()
{
	return std::string();
}

std::string MemberAccount::ReadEntry()
{
	return std::string();
}
