#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdexcept>

template<typename Key, typename Value> class AVLVeiwer;

template<typename Key, typename Value> class Storage_AVL
{
public:
	struct tuple{
		Key key;
		Value value;
	};
	friend class AVLVeiwer<Key, Value>;
	Storage_AVL()
	{ 
		_root = 0; 
		_size = 0;
	}
	~Storage_AVL()
	{
		del(_root);
	}
	void add(const Key& a, const Value& b)
	{
		if (_root == 0){
			_root = new cell;
			_root->parent = 0;
			_root->data.key = a;
			_root->data.value = b;
			_root->left = _root->right = 0;
		}
		else{
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
			balance(newcell);
		}
		++_size;
		
	}
	bool hasKey(const Key& a){
		cell *cur = _root;
		while (cur){
			if (cur->data.key == a) return true;
			if (cur->data.key < a) cur = cur->right;
			else cur = cur->left;
		}
		return false;
	};
	Value& getValuebyKey(const Key& a){
		cell *cur = _root;
		while (cur){
			if (cur->data.key == a) return cur->data.value;
			if (cur->data.key < a) cur = cur->right;
			else cur = cur->left;
		}
		throw std::logic_error("No such item");
	};
	unsigned size()const 
	{ 
		return _size; 
	};
	bool remove(const Key&a)
	{
		try
		{
			deletecell(findcell(a));
		}
		catch (std::logic_error err)
		{
			return false;
		}
		return true;
	}
	//void showTree(/*const Key& a*/)
	/*{
		return show(_root);
	}*/

	void clear()
	{
		del(_root);
		_size = 0;
		_root = 0;
	}

	AVLVeiwer<Key, Value> getIterator()
	{
		AVLVeiwer<Key, Value> v(*this);
		return v;
	}
	
private:
	struct cell{
		cell *left;
		cell *right;
		cell *parent;
		tuple data;
	};
	cell *_root;
	unsigned _size;
	int heightdiff(cell *);
	int height(cell *);
	void rotCCW(cell *);
	void rotCW(cell *);
	void lrotCCW(cell *);
	void lrotCW(cell *);
	void balance(cell *);
	cell* findcell(const Key& a){
		cell *cur = _root;
		while (cur){
			if (cur->data.key == a) return cur;
			if (cur->data.key < a) cur = cur->right;
			else cur = cur->left;
		}
		throw std::logic_error("No such item");
	};
	void deletecell(cell* cur)
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
				balance(newcell);
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
			if (heightdiff(cur) <= 0)
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
					if (c->right == cur && c->left)
					{
						c->left->parent = cur;
						cur->left = c->left;
					}
					else if (c->left == cur && c->right)
					{
						c->right->parent = cur;
						cur->right = c->right;
					}
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
				balance(cur);
			}
			else
			{
				newcell = c->parent;
				c->parent = cur->parent;
				cur->parent = newcell;

                if (cur->parent){
                    if ( cur->parent->data.key < c->data.key)
                    {
                        cur->parent->right = cur;
                        if (cur->parent->data.key == _root->data.key) _root->right = cur;
                    }
                    else
                    {
                        cur->parent->left = cur;
                        if (cur->parent->data.key == _root->data.key) _root->left = cur;
                    }
                }
                if (c->parent){
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

				deletecell(c);
			}
		}
	}
	void del(cell* c)
	{
		if (c)
		{

			if (c && c->left)
			{
				del(c->left);
			}
			if (c && c->right)
			{
				del(c->right);
			}
			delete c;
		}
	}
	/*void show(cell* c)
	{
		cell* cur = c;
		if (c && c->left)
		{
			c = c->left;
			cout << c->parent->data.key << c->parent->data.value << " ->left = " << c->data.key << c->data.value << endl;
			show(c);
		}
		if (cur && cur->right)
		{
			cur = cur->right;
			cout << cur->parent->data.key << cur->parent->data.value << " ->right = " << cur->data.key << cur->data.value << endl;
			show(cur);
		}
	}*/
};

template<typename Key, typename Value> int Storage_AVL<Key, Value>::heightdiff(cell *c)
{
	if (c == 0) return 0;
	return height(c->left) - height(c->right);
}
template<typename Key, typename Value> int Storage_AVL<Key, Value>::height(cell *c)
{
	if (c == 0) return 0;
	if (height(c->left) >= height(c->right))
		return 1 + height(c->left);
	if (height(c->left) < height(c->right))
		return 1 + height(c->right);
	return 0;
}
template<typename Key, typename Value> void Storage_AVL<Key, Value>::rotCCW(cell *c1)
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
template<typename Key, typename Value> void Storage_AVL<Key, Value>::rotCW(cell *c1)
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
template<typename Key, typename Value> void Storage_AVL<Key, Value>::lrotCCW(cell *c1)
{
	if (c1 == 0) return;
	if (!c1->right) return;
	if (!c1->right->left) return;

	rotCW(c1->right);
	rotCCW(c1);
	return;
}
template<typename Key, typename Value> void Storage_AVL<Key, Value>::lrotCW(cell *c1)
{
	if (!c1) return;
	if (!c1->left) return;
	if (!c1->left->right) return;
	
	rotCCW(c1->left);
	rotCW(c1);
	return;
}
template<typename Key, typename Value> void Storage_AVL<Key, Value>::balance(cell *c)
{
	if (heightdiff(c) <= -2 && height(c->right->left) <= height(c->right->right))
	{
		rotCCW(c);
	}
	else 
	if (heightdiff(c) <= -2 && height(c->right->left) > height(c->right->right))
	{
		lrotCCW(c);
	}
	else
	if (heightdiff(c) >= 2 && height(c->left->right) <= height(c->left->left))
	{
		rotCW(c);
	}
	else
	if (heightdiff(c) >= 2 && height(c->left->right) > height(c->left->left))
	{
		lrotCW(c);
	}
	
	if (c->parent)
	{
		balance(c->parent);
	}
	return;
}

template<typename Key, typename Value>class AVLVeiwer
{
	typename Storage_AVL<Key, Value>::cell *_cur;
public:
	AVLVeiwer()
	{
		_cur = 0;
	}
	AVLVeiwer(Storage_AVL<Key, Value>& s)
	{
		_cur = s._root;
		if (_cur)
		while (_cur->left)
			_cur = _cur->left;
	}

	typename Storage_AVL<Key, Value>::tuple & getValue()
	{
		if (_cur) return _cur->data;
		throw std::runtime_error("Invalid viewer");
	};

	void moveNext(){
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
	bool canMoveNext(){
		if (_cur == 0) return false;
		return true;
	};
};
#endif
