#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename A, typename B> class BinaryTree
{
	struct cell
	{
		cell*left;
		cell*right;
		A a;
		B b;
	};
	cell*_root; // корень
	cell*_cur;  // текущий
	cell*parent;
public:
	BinaryTree()
	{
		_root = 0; 
		_cur = 0;
	}
	~BinaryTree()
	{
		parent = _cur;
		while (_cur)
		{
			while (_cur->left)
				_cur = _cur->left;
			while (_cur->right)
				_cur = _cur->right;
			if (!_cur->left && !_cur->right)
			{
				delete[] _cur;
				_cur = _root;
			}
		}

	};
	void add(const A&a, const B&b)
	{
		if (_root == 0)
		{
			_root = new cell;
			_root->a = a;
			_root->b = b;
			_root->left = 0;
			_root->rigth = 0;
		}
		else
		{
			cell*newcell = new cell;
			_root->a = a;
			_root->b = b;
			_root->left = 0;
			_root->rigth = 0;
			_cur = _root;
			while (_cur)
			{
				if (_cur->a == a)
					_cur->b = b;
				parent = _cur;
				if (_cur->a < a)
					_cur = _cur->right;
				if(cur->a > a)
					_cur = _cur->left;
			}
			if (parent->a < a)
				parent->right = newcell;
			else
				parent->left = newcell;
		}
	}

	bool hasA(const A&a)
	{
		_cur = _root;
		while (_cur)
		{
			if (_cur->a == a)
				return true;
			if (_cur->a < a)
				_cur = _cur->right;
			if (_cur->a > a)
				_cur = _cur->left;
		}
		return false;
	};

	B& getBbyA(const A&a)
	{
		_cur = _root;
		while (_cur)
		{
			if (_cur->a == a)
				return _cur->b;
			if (_cur->a < a)
				_cur = _cur->right;
			if (_cur->a > a)
				_cur = _cur->left;
		}
		throw std::invalid_argument("Error!");
	};
};

#endif