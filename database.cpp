#include "database.h"
#include "curl.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>

Database* Database::m_pInstance;

void Database::populate_db()
{
	std::string api_key = "YOUR API KEY HERE";

	std::string request_str = "https://tarkov-market.com/api/v1/items/all/?x-api-key=" + api_key;
	std::string response = Curl::GetInstance()->curl_request(request_str.c_str());

	rapidjson::Document document;
	document.Parse(response.c_str());

	// Todo: retarded
	for (int i = 0; i < 2157; i++)
	{
		// For interface list, kinda fucked but who cares
		// maybe move to own getter to return a QStringList? TODO
		item_names.emplace_back(document[i]["name"].GetString());
		Item* item = new Item(document[i]["uid"].GetString(), document[i]["bsgId"].GetString(), document[i]["name"].GetString(), document[i]["shortName"].GetString(), document[i]["avg24hPrice"].GetInt());
		items.push_back(item);
		//std::cout << document[i]["name"].GetString() << "\n";
	}

	std::cout << "\n~ Database populated.\n";
}

QStringList Database::get()
{
	return item_names;
}

Item* Database::obj_from_name(std::string name)
{
	for (Item* i : items)
	{
		if (i->name == name)
		{
			return i;
		}
	}
}

Database* Database::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Database();

	return m_pInstance;
}
