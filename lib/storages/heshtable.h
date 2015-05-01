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
		const char * str = reinterpret_cast<const char*>(&h);
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

template <typename FirstType, typename SecondType> class HashViewer;

template <typename FirstType, typename SecondType, typename HashType = HashRs<FirstType>> class HashTable
{
private:
	struct ABstruct
	{
		FirstType first;
		SecondType second;
	};
	//Storage_Array<Storage_List<ABstruct>> _table;
	Storage_List<ABstruct>* _table;
	HashType _hashfun;
	unsigned _size;
	static const unsigned _TABLERATIO = 1021;
public:
	friend class HashViewer < FirstType, SecondType > ;
	HashTable()
	{
		_size = 0;
		_table = new Storage_List<ABstruct>[_TABLERATIO];
	}
	~HashTable()
	{
		Storage_List<ABstruct>* temp = _table;
		for (unsigned i = 0; i < _TABLERATIO; i++)
		{
			temp->clear();
			temp++;
		}
		delete[] _table;
	}
	void add(const FirstType &a, const SecondType &b)
	{
		ABstruct c = { a, b };
		_table[_hashfun(a) % _TABLERATIO].add(c);	
		_size++;
	}
	bool find(const FirstType &a, const SecondType &b)
	{
		for (ListViewer<ABstruct> i(_table[_hashfun(a) % _TABLERATIO]);
			i.canMoveNext(); i.moveNext())
		{
			if (i.getValue().second == b && i.getValue().first == a)
				return true;
		}
		return false;
	}

	bool remove(const FirstType &a, const SecondType &b)
	{
		unsigned f = _hashfun(a);
		for (ListViewer<ABstruct> i(_table[f % _TABLERATIO]);
			i.canMoveNext(); i.moveNext())
		{
			if (i.getValue().second == b && i.getValue().first == a)
			{
				_table[f % _TABLERATIO].remove(&i);
				_size--;
				return true;
			}
		}
		return false;
	}

	bool remove(HashViewer<FirstType, SecondType>* viewer)
	{
		if (viewer)
		{
			viewer->_topViewer->remove(&viewer->_bottomViewer);
			_size--;
			return true;
		}
		return false;
	}

	void clear()
	{
		if (_table)
		{
			Storage_List<ABstruct>* temp = _table;
			for (unsigned i = 0; i < _TABLERATIO; i++, temp++)
			{
				temp->clear();
			}
			_size = 0;
		}
	}

	unsigned size() const
	{
		return _size;
	}
	HashViewer<FirstType, SecondType> getStartingViewer()
	{
		HashViewer<FirstType, SecondType> v(*this);
		return v;
	}
};

template <typename FirstType, typename SecondType> class HashViewer
{
private:
	Storage_List < typename HashTable<FirstType, SecondType>::ABstruct >* _topViewer;
	Storage_List < typename HashTable<FirstType, SecondType>::ABstruct >* _end;
	ListViewer < typename HashTable<FirstType, SecondType>::ABstruct > _bottomViewer;
public:
	friend class HashTable < FirstType, SecondType > ;
	HashViewer();
	HashViewer(HashTable<typename FirstType, typename SecondType>& table)
	{
		_topViewer = table._table;
		_end = &(_topViewer[HashTable<FirstType, SecondType>::_TABLERATIO - 1]);
		_bottomViewer = _topViewer->getStartingViewer();
		while (!_bottomViewer.canMoveNext() && _topViewer != _end )
		{
			_topViewer++;
			_bottomViewer = _topViewer->getStartingViewer();
		}
	}
	FirstType& getFirst()
	{
		try
		{
			return _bottomViewer.getValue().first;
		}
		catch (std::out_of_range a)
		{
			throw a;
		}
	}
	SecondType& getSecond()
	{
		try
		{
			return _bottomViewer.getValue().second;
		}
		catch (std::out_of_range a)
		{
			throw a;
		}
	}
	bool canMoveNext()
	{
		if (_topViewer != _end) return true;
		else if (_bottomViewer.canMoveNext()) return true;
		return false;
	}
	void moveNext()
	{
		if (_bottomViewer.canMoveNext())
			_bottomViewer.moveNext();
		else while (_topViewer != _end)
		{
			_topViewer++;
			_bottomViewer = _topViewer->getStartingViewer();
			if (_bottomViewer.canMoveNext()) break;
		}
	}
	void moveNextHash()
	{
		while (_topViewer != _end)
		{
			_topViewer++;
			_bottomViewer = _topViewer->getStartingViewer();
			if (_bottomViewer.canMoveNext()) break;
		}
	}
};

#endif // HASHTABLE_H