#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <QString>
#include <fstream>
#include <QFile>
#include <QXmlStreamReader>
#include "storages/mylist.h"
#include "core.h"
using namespace std;


class Load {
	QString _way;
	QFile*_file;
	QXmlStreamReader _xml;
	CORE*_action;
public:
	Load();
	Load(CORE*, QString);
	void begin();
	void point();
	void segment();
	void circle();
	void constraint();
};

#endif //LOAD_H