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
	bool _flag;
	myvector<int> _vector;
public:
	Load();
	Load(CORE*, QString);
	void testPoints();
	void testBegin();
	void testPoint();
	void testSegment();
	void testCircle();
	void testConstraint();
	void begin();
	void point();
	void segment();
	void circle();
	void constraint();
	bool isCorrect();
};

#endif //LOAD_H