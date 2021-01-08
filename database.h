#pragma once
#include <qstringlist.h>
#include <vector>
#include "structs.h"

class Database
{
public:
	void populate_db();
	QStringList get();

	Item* obj_from_name(std::string name);

	static Database* GetInstance();
private:
	QStringList item_names;
	std::vector<Item*> items;

	static Database* m_pInstance;
};