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
	//friend class CORE;
	string _way;
	fstream _save;
	CORE*_action;
public:
	Save();
	~Save();
	void ConnectCORE(CORE*core);
	void begin();
	virtual bool DrawPoint(unsigned, double, double, Color = 0);
	virtual bool DrawSegment(unsigned, double, double, double, double, Color = 0);
	virtual bool DrawCircle(unsigned, double, double, double, Color = 0);
	virtual bool Clear();
	void end();
	string fileWay(QString);
};
#endif // SAVE_H 