#include <string>
#include <fstream>
#include "storage_list.h"
#include "core.h"
using namespace std;
class Save {
	string _way;
	fstream _save;
	CORE _action;
public:
	Save();
	void save();
	string fileWay(string);
};