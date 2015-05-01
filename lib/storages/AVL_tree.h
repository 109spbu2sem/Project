#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
#include <stdexcept>

template<typename A, typename B> class TreeViewer;

template<typename A, typename B> class tree_storage
{
public:
	struct tuple{
		A a;
		B b;
	};
	friend class TreeViewer<A, B>;
	tree_storage()
	{ 
		_root = 0; 
		_size = 0;
	}
	~tree_storage()
	{
		del(_root);
	}
	void add(const A& a, const B& b)
	{
		if (_root == 0){
			_root = new cell;
			_root->parent = 0;
			_root->data.a = a;
			_root->data.b = b;
			_root->left = _root->right = 0;
		}
		else{
			cell *newcell = new cell;
			newcell->data.a = a;
			newcell->data.b = b;
			newcell->left = 0;
			newcell->right = 0;

			cell *cur = _root;
			cell *parent = 0;
			while (cur)
			{
				if (cur->data.a == a)
				{
					cur->data.b = b;
					return;
				}
				parent = cur;
				if (cur->data.a < a)
					cur = cur->right;
				else cur = cur->left;
			}
			if (parent->data.a < a) 
				parent->right = newcell;
			else 
				parent->left = newcell;
			newcell->parent = parent;
			balance(newcell);
		}
		++_size;
		
	}
	bool hasA(const A& a){
		cell *cur = _root;
		while (cur){
			if (cur->data.a == a) return true;
			if (cur->data.a < a) cur = cur->right;
			else cur = cur->left;
		}
		return false;
	};
	B& getBbyA(const A& a){
		cell *cur = _root;
		while (cur){
			if (cur->data.a == a) return cur->data.b;
			if (cur->data.a < a) cur = cur->right;
			else cur = cur->left;
		}
		throw std::logic_error("No such item");
	};
	unsigned size()const 
	{ 
		return _size; 
	};
	void remove(const A&a)
	{
		deletecell(findcell(a));
	}

	void clear()
	{
		del(_root);
		_size = 0;
		_root = 0;
	}

	TreeViewer<A, B>& getStartingViewer()
	{
		return TreeViewer<A, B>(this);
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
	cell* findcell(const A& a){
		cell *cur = _root;
		while (cur){
			if (cur->data.a == a) return cur;
			if (cur->data.a < a) cur = cur->right;
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
				if (cur->data.a < newcell->data.a) newcell->left = 0;
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
					_root = cur;
					cur->parent = 0;
				}
				else
				{
					cur->parent = c->parent;
					if (c->parent->data.a < c->data.a)
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
				balance(cur);
			}
			else
			{
				newcell = c->parent;
				c->parent = cur->parent;
				cur->parent = newcell;

				if (cur->parent)
				if (cur->parent->data.a < c->data.a)
				{
					cur->parent->right = cur;
					if (cur->parent->data.a == _root->data.a) _root->right = cur;
				}
				else
				{
					cur->parent->left = cur;
					if (cur->parent->data.a == _root->data.a) _root->left = cur;
				}
				if (c->parent)
				if (c->parent->data.a < cur->data.a)
				{
					c->parent->right = c;
					if (c->parent->data.a == _root->data.a) _root->right = c;
				}
				else
				{
					c->parent->left = c;
					if (c->parent->data.a == _root->data.a) _root->left = c;
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
	void show(cell* cur)
	{
		cell* c = cur;
		if (cur && cur->left)
		{
			cur = cur->left;
			cout << cur->parent->data.a << cur->parent->data.b << " ->left = " << cur->data.a << cur->data.b << endl;
			show(cur);
		}
		if (c && c->right)
		{
			c = c->right;
			cout << c->parent->data.a << c->parent->data.b << " ->right = " << c->data.a << c->data.b << endl;
			show(c);
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
};

template<typename A, typename B> int tree_storage<A, B>::heightdiff(cell *c)
{
	if (c == 0) return 0;
	return height(c->left) - height(c->right);
}
template<typename A, typename B> int tree_storage<A, B>::height(cell *c)
{
	if (c == 0) return 0;
	if (height(c->left) >= height(c->right))
		return 1 + height(c->left);
	if (height(c->left) < height(c->right))
		return 1 + height(c->right);
	return 0;
}
template<typename A, typename B> void tree_storage<A, B>::rotCCW(cell *c1)
{
	if(c1 == 0) return;
	//cout << c1->data.a << "   --1--   " << c1->data.b << endl;
	cell* parent = c1->parent;
	cell* T1 = c1->left;
	cell* c2 = c1->right;
	if (c2 == 0) return;
	cell *T2 = c2->left;
	cell *T3 = c2->right;

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
template<typename A, typename B> void tree_storage<A, B>::rotCW(cell *c1)
{
	if (c1 == 0) return;
	//cout << c1->data.a << "   --2--   " << c1->data.b << endl;
	cell* parent = c1->parent;
	cell* c2 = c1->left;
	cell* T1 = c2->left;
	if (c2 == 0) return;
	cell *T2 = c2->right;
	cell *T3 = c1->right;

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
template<typename A, typename B> void tree_storage<A, B>::lrotCCW(cell *c1)
{
	if (c1 == 0) return;
	//cout << c1->data.a << "   --3--   " << c1->data.b << endl;
	cell* c2 = c1->right;
	cell* c3 = c2->left;
	if (c2 == 0) return;
	if (c3 == 0) return;
	rotCW(c2);
	rotCCW(c1);
	return;
}
template<typename A, typename B> void tree_storage<A, B>::lrotCW(cell *c1)
{
	if (c1 == 0) return;
	//cout << c1->data.a << "   --4--   " << c1->data.b << endl;
	cell* c2 = c1->left;
	cell* c3 = c2->right;
	if (c2 == 0) return;
	if (c3 == 0) return;
	
	rotCCW(c2);
	rotCW(c1);
	return;
}
template<typename A, typename B> void tree_storage<A, B>::balance(cell *c)
{
	//cout << "!  " <<c->data.a << c->data.b << " = " <<heightdiff(c) << endl;
	if (heightdiff(c) <= -2 && height(c->right->left) <= height(c->right->right))
	{
		rotCCW(c);
		//cout << c->data.a << c->data.b << ", parent: " << c->parent->data.a << c->parent->data.b 
			//<< ", parent->right: " << c->parent->right->data.a << c->parent->right->data.b << endl;
	}
	else 
	if (heightdiff(c) <= -2 && height(c->right->left) > height(c->right->right))
	{
		lrotCCW(c);
		//cout << c->data.a << c->data.b << ", parent: " << c->parent->data.a << c->parent->data.b
			//<< ", parent->right: " << c->parent->right->data.a << c->parent->right->data.b << endl;
	}
	else
	if (heightdiff(c) >= 2 && height(c->left->right) <= height(c->left->left))
	{
		rotCW(c);
		//cout << c->data.a << c->data.b << ", parent: " << c->parent->data.a << c->parent->data.b
			//<< ", parent->left: " << c->parent->left->data.a << c->parent->left->data.b << endl;
	}
	else
	if (heightdiff(c) >= 2 && height(c->left->right) > height(c->left->left))
	{
		lrotCW(c);
		//cout << c->data.a << c->data.b << ", parent: " << c->parent->data.a << c->parent->data.b
			//<< ", parent->left: " << c->parent->left->data.a << c->parent->left->data.b << endl;
	}
	
	if (c->parent)
	{
		//cout << c->data.a << c->data.b << " PARENT: " << c->parent->data.a << c->parent->data.b << endl;
		balance(c->parent);
	}
	return;
}

template<typename A, typename B>class TreeViewer{
	typename tree_storage<A, B>::cell *_cur;
public:
	TreeViewer()
	{
		_cur = 0;
	}
	TreeViewer(tree_storage<A, B>& s)
	{
		_cur = s._root;
		if (_cur)
		while (_cur->left)
			_cur = _cur->left;
	}

	typename tree_storage<A, B>::tuple & getValue(){
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
		}

	};
	bool canMoveNext(){
		if (_cur == 0) return false;
		return true;
	};
};
#endif