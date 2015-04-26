#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include "storages\storage_list.h"
#include "core.h"
using namespace std;

class Save {
	string _way;
	fstream _save;
	CORE*_action;
	CORE::Primitive _ans;
public:
	Save();
	~Save();
	void ConnectCORE(CORE*);
	void save();
	string fileWay(string);
};
#endif