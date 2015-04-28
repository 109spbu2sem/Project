#ifndef SAVE_H
#define SAVE_H

#include <string>
#include <fstream>
#include "storages\storage_list.h"
#include "core.h"
#include <QFileDialog>

using namespace std;

class Save: public Interface{
	string _way;
	fstream _save;
	CORE*_action;
public:
	Save();
	~Save();
	void ConnectCORE(CORE*core);
	void begin();
	virtual bool Interface::DrawPoint(unsigned, double, double, Color = 0);
	virtual bool Interface::DrawSegment(unsigned, double, double, double, double, Color = 0);
	virtual bool Interface::DrawCircle(unsigned, double, double, double, Color = 0);
	virtual bool Interface::Clear();
	void end();
	string fileWay(QString);
};
#endif // SAVE_H 