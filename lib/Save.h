#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include "storages/mylist.h"
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
	bool DrawPoint(unsigned, double, bool, double, bool, Color, bool);
	bool DrawSegment(unsigned, unsigned, unsigned, Color, bool);
	bool DrawCircle(unsigned, unsigned, double, bool, Color, bool);
	bool DrawRule(CONSTR_TYPE, unsigned, unsigned);
	bool DrawRule(CONSTR_TYPE, unsigned, unsigned, double);
	bool DrawRule(CONSTR_TYPE, unsigned, unsigned, unsigned, double);
	bool DrawRule(CONSTR_TYPE, unsigned, unsigned, unsigned);
};
#endif // SAVE_H