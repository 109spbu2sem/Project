#ifndef MY_AVL_TREE_H
#define MY_AVL_TREE_H
#include <stdexcept>

template<typename key_type, typename item_type> class myavltree
{
public:

	struct tuple
	{
		key_type key;
		item_type value;
	};

	friend class myiterator;

	myavltree()
	{
		_root = 0;
		_size = 0;
	}

	~myavltree()
	{
		_del(_root);
	}

	void add(const key_type& a, const item_type& b)
	{
		if (_root == 0)
		{
			_root = new cell;
			_root->parent = 0;
			_root->data.key = a;
			_root->data.value = b;
			_root->left = _root->right = 0;
		}
		else
		{
			cell *newcell = new cell;
			newcell->data.key = a;
			newcell->data.value = b;
			newcell->left = 0;
			newcell->right = 0;

			cell *cur = _root;
			cell *parent = 0;
			while (cur)
			{
				if (cur->data.key == a)
				{
					cur->data.value = b;
					return;
				}
				parent = cur;
				if (cur->data.key < a)
					cur = cur->right;
				else cur = cur->left;
			}
			if (parent->data.key < a)
				parent->right = newcell;
			else
				parent->left = newcell;
			newcell->parent = parent;
			_balance_cell(newcell);
		}
		++_size;

	}

	bool hasKey(const key_type& a)
	{
		cell *cur = _root;
		while (cur)
		{
			if (cur->data.key == a) return true;
			if (cur->data.key < a) cur = cur->right;
			else cur = cur->left;
		}
		return false;
	}

	item_type& getValuebyKey(const key_type& a)
	{
		cell *cur = _root;
		while (cur)
		{
			if (cur->data.key == a) return cur->data.value;
			if (cur->data.key < a) cur = cur->right;
			else cur = cur->left;
		}
		throw std::logic_error("No such item");
	}

	unsigned size() const
	{
		return _size;
	}


	bool remove(const key_type&a)
	{
		try
		{
			_delete_cell(_findcell(a));
		}
		catch (std::logic_error)
		{
			return false;
		}
		return true;
	}

	void clear()
	{
		_del(_root);
		_size = 0;
		_root = 0;
	}

	// begin iterator

	template<typename key_type, typename item_type> class myiterator
	{
		typename myavltree<key_type, item_type>::cell *_cur;
	public:
		myiterator()
		{
			_cur = 0;
		}
		myiterator(myavltree<key_type, item_type>& s)
		{
			_cur = s._root;
			if (_cur)
				while (_cur->left)
					_cur = _cur->left;
		}

		typename myavltree<key_type, item_type>::tuple & getValue()
		{
			if (_cur) return _cur->data;
			throw std::runtime_error("Invalid viewer");
		};

		void moveNext()
		{
			if (_cur->right != 0)
			{
				_cur = _cur->right;
				while (_cur->left)
					_cur = _cur->left;
			}
			else
			{
				if (_cur->parent)
				{
					if (_cur->parent->left == _cur)
						_cur = _cur->parent;
					else
					{
						while (_cur->parent && _cur == _cur->parent->right)
							_cur = _cur->parent;
						_cur = _cur->parent;
					}
				}
				else _cur = _cur->parent;
			}

		};
		bool canMoveNext()
		{
			if (_cur == 0) return false;
			return true;
		};
	};

	// end iterator

	myiterator<key_type, item_type> getIterator()
	{
		myiterator<key_type, item_type> v(*this);
		return v;
	}

private:
	struct cell
	{
		cell *left;
		cell *right;
		cell *parent;
		tuple data;
	};
	cell *_root;
	unsigned _size;
	int _heightdiff(cell *);
	int _height(cell *);
	void _rotCCW(cell *);
	void _rotCW(cell *);
	void _lrotCCW(cell *);
	void _lrotCW(cell *);
	void _balance_cell(cell *);
	cell* _findcell(const key_type& a)
	{
		cell *cur = _root;
		while (cur)
		{
			if (cur->data.key == a) return cur;
			if (cur->data.key < a) cur = cur->right;
			else cur = cur->left;
		}
		throw std::logic_error("No such item");
	};
	void _delete_cell(cell* cur)
	{
		if (cur->left == 0 && cur->right == 0)
		{
			if (cur->parent)
			{
				cell* newcell = cur->parent;
				if (cur->data.key < newcell->data.key) newcell->left = 0;
				else newcell->right = 0;
				delete cur;
				_size--;
				_balance_cell(newcell);
			}
			else
			{
				delete cur;
				_size = 0;
				_root = 0;
			}
		}
		else
		{

			cell* c = cur;
			cell* newcell;
			if (_heightdiff(cur) <= 0)
			{
				cur = cur->right;
				while (cur->left) cur = cur->left;
			}
			else
			{
				cur = cur->left;
				while (cur->right) cur = cur->right;
			}
			if (cur->parent == c)
			{
				if (c == _root)
				{
					_root = cur;
					cur->parent = 0;
				}
				else
				{
					cur->parent = c->parent;
					if (c->parent->data.key < c->data.key)
					{
						c->parent->right = cur;
						if (c->parent == _root) _root->right = cur;
					}
					else
					{
						c->parent->left = cur;
						if (c->parent == _root) _root->left = cur;
					}
				}
				delete c;
				_size--;
				_balance_cell(cur);
			}
			else
			{
				newcell = c->parent;
				c->parent = cur->parent;
				cur->parent = newcell;

				if (cur->parent)
					if (cur->parent->data.key < c->data.key)
					{
					cur->parent->right = cur;
					if (cur->parent->data.key == _root->data.key) _root->right = cur;
					}
					else
					{
						cur->parent->left = cur;
						if (cur->parent->data.key == _root->data.key) _root->left = cur;
					}
				if (c->parent)
					if (c->parent->data.key < cur->data.key)
					{
					c->parent->right = c;
					if (c->parent->data.key == _root->data.key) _root->right = c;
					}
					else
					{
						c->parent->left = c;
						if (c->parent->data.key == _root->data.key) _root->left = c;
					}


				newcell = cur->left;
				cell* newcell2 = cur->right;
				if (cur->left) cur->left->parent = c;
				if (cur->right) cur->right->parent = c;
				cell* newcell3 = c->left;
				cell* newcell4 = c->right;
				if (c == _root)
				{
					_root = cur;
					_root->left = c->left;
					_root->right = c->right;
				}
				c->left->parent = cur;
				c->right->parent = cur;

				cur->left = newcell3;
				cur->right = newcell4;
				c->left = newcell;
				c->right = newcell2;

				_delete_cell(c);
			}
		}
	}
	void _del(cell* c)
	{
		if (c)
		{

			if (c && c->left)
			{
				_del(c->left);
			}
			if (c && c->right)
			{
				_del(c->right);
			}
			delete c;
		}
	}
};

template<typename key_type, typename item_type> int myavltree<key_type, item_type>::_heightdiff(cell *c)
{
	if (c == 0) return 0;
	return _height(c->left) - _height(c->right);
}
template<typename key_type, typename item_type> int myavltree<key_type, item_type>::_height(cell *c)
{
	if (c == 0) return 0;
	if (_height(c->left) >= _height(c->right))
		return 1 + _height(c->left);
	if (_height(c->left) < _height(c->right))
		return 1 + _height(c->right);
	return 0;
}
template<typename key_type, typename item_type> void myavltree<key_type, item_type>::_rotCCW(cell *c1)
{
	if(c1 == 0) return;
	cell* parent = c1->parent;
	cell* c2 = c1->right;
	if (c2 == 0) return;
	cell *T2 = c2->left;

	c1->right = T2;
	if (T2)	T2->parent = c1;

	c2->left = c1;
	c1->parent = c2;

	c2->parent = parent;
	if (parent) {
		if (parent->right == c1)
			parent->right = c2;
		else
			parent->left = c2;
	}
	if (c1 == _root) _root = c2;
}
template<typename key_type, typename item_type> void myavltree<key_type, item_type>::_rotCW(cell *c1)
{
	if (c1 == 0) return;
	cell* parent = c1->parent;
	cell* c2 = c1->left;
	if (c2 == 0) return;
	cell *T2 = c2->right;

	c1->left = T2;
	if(T2) T2->parent = c1;

	c2->right = c1;
	c1->parent = c2;

	c2->parent = parent;
	if (parent)
	{
		if (parent->right == c1)
			parent->right = c2;
		else
			parent->left = c2;
	}
	if (c1 == _root) _root = c2;

}
template<typename key_type, typename item_type> void myavltree<key_type, item_type>::_lrotCCW(cell *c1)
{
	if (c1 == 0) return;
	if (!c1->right) return;
	if (!c1->right->left) return;

	_rotCW(c1->right);
	_rotCCW(c1);
	return;
}
template<typename key_type, typename item_type> void myavltree<key_type, item_type>::_lrotCW(cell *c1)
{
	if (!c1) return;
	if (!c1->left) return;
	if (!c1->left->right) return;
	
	_rotCCW(c1->left);
	_rotCW(c1);
	return;
}
template<typename key_type, typename item_type> void myavltree<key_type, item_type>::_balance_cell(cell *c)
{
	if (_heightdiff(c) <= -2 && _height(c->right->left) <= _height(c->right->right))
	{
		_rotCCW(c);
	}
	else 
	if (_heightdiff(c) <= -2 && _height(c->right->left) > _height(c->right->right))
	{
		_lrotCCW(c);
	}
	else
	if (_heightdiff(c) >= 2 && _height(c->left->right) <= _height(c->left->left))
	{
		_rotCW(c);
	}
	else
	if (_heightdiff(c) >= 2 && _height(c->left->right) > _height(c->left->left))
	{
		_lrotCW(c);
	}
	
	if (c->parent)
	{
		_balance_cell(c->parent);
	}
	return;
}

#endif // MY_AVL_TREE_H
