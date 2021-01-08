#pragma once
#include <string>

class Item
{
public:
	Item(std::string uid, std::string bsgid, const char* name, const char* name_formatted, int price) :
		uid(uid),
		bsgid(bsgid),
		name(name),
		name_formatted(name_formatted),
		price(price)
	{};

	std::string uid;
	std::string bsgid;
	std::string name;
	std::string name_formatted;
	std::string image_location;
	int price;
private:

};
