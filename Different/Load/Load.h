#include <string>
#include <fstream>
#include "storages\storage_list.h"
#include "core.h"
using namespace std;

class Load {
	string*_way;
	ifstream _load;
	CORE::Primitive*_ans;
	streamoff*_cur;
public:
	Load();
	CORE::Primitive load();
	string fileWay(string);
};