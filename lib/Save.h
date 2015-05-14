#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include "storages\storage_list.h"
#include "core.h"
#include <QString>


using namespace std;
class CORE;

class Save {
	string _way;
	fstream _save;
public:
	Save();
	Save(QString);
	~Save();
	bool DrawPoint(unsigned, double, double, Color, bool);
	bool DrawSegment(unsigned, unsigned, unsigned, Color, bool);
	bool DrawCircle(unsigned, unsigned, double, Color, bool);
};
#endif // SAVE_H 