#ifndef OBJECTSKIN_H
#define OBJECTSKIN_H
#include "LineSkin.h"

/*template <typename Item> */class ObjectSkin
{
private:
	bool _visible; // false(0) invisible, true(1) visible
	bool _select; // false(0) object is free, true(1) object if picked
public:
	LineSkin line;
	Color background;
	//unsigned char visible; // 0 - invisible, 100 - full visible; // May be unused
	ObjectSkin();
	~ObjectSkin();
	void changeVisible();
	void changeSelect(bool b = true);
	virtual unsigned objectType() = 0;
	//virtual Item& getLink() = 0;
};

#endif // OBJECTSKIN_H 