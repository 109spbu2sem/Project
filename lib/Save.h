#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include "storages\storage_list.h"
#include "core.h"
#include <QString>


using namespace std;
class CORE;

class Save: public Interface{
	string _way;
	fstream _save;
	//CORE*_action;
public:
	Save();
	~Save();
	void begin();
	virtual bool DrawPoint(unsigned, double, double, Color, bool);
	virtual bool DrawSegment(unsigned, double, double, double, double, Color, bool);
	virtual bool DrawCircle(unsigned, double, double, double, Color, bool);
	virtual bool Clear();
	string fileWay(QString);
};
#endif // SAVE_H 