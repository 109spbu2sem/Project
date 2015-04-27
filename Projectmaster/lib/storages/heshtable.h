#ifndef HESHTABLE_H
#define HESHTABLE_H

#include "storage_array.h"
#include "storage_list.h"
#include <string>

template <typename hashtype> class StringHesh
{
public:
	unsigned operator()(const hashtype &h)
	{
		unsigned res = 0;
		unsigned char *pc = (unsigned char*)(&h);
		for (unsigned i = 0; i < sizeof(h); i++)
		{
			res += *pc++;
		}
		return res;
	}
};

template <typename hashtype> class HashRs
{
public:
	unsigned operator()(const hashtype &h)
	{
		unsigned i = sizeof(h);
		const char * str = static_cast<const char*>&h;
		static const unsigned b = 378551;
		unsigned a = 63689;
		unsigned hash = 0;

		for (; i > 0; str++, i--)
		{
			hash = hash * a + (unsigned char)(*str);
			a *= b;
		}

		return hash;

	}
};

template <typename FirstType, typename SecondType> class HeshViewer;

template <typename FirstType, typename SecondType, typename HeshType = HashRs<FirstType>> class HeshTable
{
private:
	struct ABstruct
	{
		FirstType first;
		SecondType second;
	};
	Storage_Array<Storage_List<ABstruct>> _table;
	HeshType _heshtable;
	unsigned _size;
public:
	friend class HeshViewer < FirstType, SecondType > ;
	HeshTable()
	{
		_size = 0;
	}
	~HeshTable()
	{

	}
	void add(const FirstType &a, const SecondType &b)
	{
		_heshtable(a);
		_size++;
	}
	bool find(const FirstType &a, const SecondType &b)
	{
		return false;
	}
	unsigned size()
	{
		return _size;
	}
	HeshViewer<FirstType, SecondType> getStartingViewer()
	{
		HeshViewer<FirstType, SecondType> v(*this);
		return v;
	}
};

template <typename FirstType, typename SecondType> class HeshViewer
{
private:
	ArrayViewer < Storage_List < typename HeshTable<FirstType, SecondType>::ABstruct >> _topViewer;
	ListViewer < typename HeshTable<FirstType, SecondType>::ABstruct > _bottomViewer;
public:
	HeshViewer();
	HeshViewer(HeshTable<typename FirstType, typename SecondType>& table)
	{
		_topViewer = table._table.getStartingViewer();
		_bottomViewer = _topViewer.getValue().getStartingViewer();
		while (_topViewer.canMoveNext() && _bottomViewer.canMoveNext())
		{
			_topViewer.moveNext();
			_bottomViewer = _topViewer.getValue().getStartingViewer();
		}
	}
	FirstType& getFirst()
	{
		return _bottomViewer.getValue().first;
	}
	SecondType& getSecond()
	{
		return _bottomViewer.getValue().second;
	}
	bool canMoveNext()
	{
		if (_bottomViewer.canMoveNext() && _topViewer.canMoveNext()) return true;
		return false;
	}
	void moveNext()
	{
		if (_bottomViewer.canMoveNext())
			_bottomViewer.moveNext();
		else if (_topViewer.canMoveNext())
				_topViewer.moveNext();
	}
	void moveNextCell()
	{
		if (_topViewer.canMoveNext())
		{
			_topViewer.moveNext();
		}
	}
};

#endif // HESHTABLE_H