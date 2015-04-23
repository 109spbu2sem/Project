#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

template<typename Item> class Matrix
{
private:
	unsigned _height;
	unsigned _weight;
	Item** _root;
public:
	Matrix(unsigned weight, unsigned height)
	{
		if (weight < 2 && height < 2) throw std::invalid_argument("Wrong height or weight.");
		_height = height;
		_weight = weight;
		_root = new Item*[height];
		for (unsigned i = 0; i < height; i++)
		{
			_root[i] = new Item[weight];
		}
	}
	~Matrix()
	{
		if (_root)
		{
			for (unsigned i = 0; i < _height; i++)
			{
				delete[] _root[i];
			}
			delete[] _root;
		}
	}
	void set(const unsigned x, const unsigned y, const Item& item)
	{
		_root[x][y] = item;
	}
	Item& get(const unsigned x, const unsigned y) const
	{
		return _root[x][y];
	}
	unsigned height() const
	{
		return _height;
	}
	unsigned wieght() const
	{
		return _weight;
	}
	void transpose()
	{
		if (_root)
		{
			//create new matrix
			Item** root = new Item*[_weight];
			for (unsigned i = 0; i < _weight; i++)
			{
				root[i] = new Item[_height];
			}

			//copying elements from old matrix to new
			for (unsigned i = 0; i < _height; i++)
			{
				for (unsigned j = 0; j < _weight; j++)
				{
					root[i][j] = _root[j][i];
				}
			}
			
			//delete old matrix
			for (unsigned i = 0; i < _height; i++)
			{
				delete[] _root[i];
			}
			delete[] _root;

			//redefine variables
			_root = root;
			unsigned t = _height;
			_height = _weight;
			_weight = t;

		}
	}
};

#endif