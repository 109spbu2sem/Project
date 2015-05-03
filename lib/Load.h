#ifndef LOAD_H
#define LOAD_H

#include <string>
#include <QString>
#include <fstream>
#include <QFile>
#include <QXmlStreamReader>
#include "storages\storage_list.h"
#include "core.h"
using namespace std;


class Load {
	QString _way;
	ifstream _load;
	streamoff _cur;
	QFile*_file;
	QXmlStreamReader _xml;
public:
	Load();
	void fileWay(QString);
	void begin();
	void point();
	void segment();
	void circle();
};

#endif //LOAD_H