#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename A, typename B> class BinaryTree
{
	struct tuple
	{
		A a;
		B b;
	};
	struct cell
	{
		cell*left;
		cell*right;
		cell *tuple;
		cell*parent;
	};
	cell*_root;
	cell*_cur;


	template<typename A, typename B> class Viewer
	{
		typename BinaryTree <A, B>::cell *_cur;
		typename BinaryTree <A, B>::cell *_rightmost;
	public:
		Viewer()
		{
			_cur = 0;
			_rightmost = 0;
		}
		Viewer(BinaryTree&s)
		{
			_cur = s._root;
			_rightmost = s._root;
			if (_cur)
			{
				while (_cur->left)
					_cur = _cur->left;
				while (_rightmost->right)
					_rightmost = _rightmost->right;
			}
		}

		typename BinaryTree <A, B>::tuple & getCurrent()// обращение к текущему
		{
			if (_cur) return _cur->data;
			throw runtime_error("invalid");

		};
		void moveNext()// перемещение к следующему элементу
		{
			if (_cur->right != 0)
			{
				_cur = _cur->right;
				while (_cur->left)
					_cur = _cur->left;
			}
			else
			{
				if (_cur->left == 0)
				{
					if (_cur->parent->left == _cur)
						_cur = _cur->parent;
					else
					while (_cur->parent && _cur == _cur->parent->right)
						_cur = _cur->parent;
					_cur = _cur->parent;
				}
			}
		};
		bool canMoveNext() // возможность обращения к сл эл
		{
			if (_rightmost == _cur) return false;
			return true;

		}
	};
public:
	BinaryTree()
	{
		_root = 0;
		_cur = 0;
	}
	~BinaryTree()
	{
		_cur = _root;
		cell *parent = _cur;
		while (parent)
		{

			while (_cur->left)
			{
				parent = _cur;
				_cur = _cur->left;
			}

			while (_cur->right)
			{
				parent = _cur;
				_cur = _cur->right;
			}
			if (!_cur->left && !_cur->right)
			{
				if (parent->left == _cur)
				{
					delete[] _cur;
					parent->left = 0;
				}
				else
				{
					delete[] _cur;
					parent->right = 0;
				}
				if (_cur == _root)
					break;
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
			_root->right = 0;
		}
		else
		{
			cell*newcell = new cell;
			cell* parent;
			newcell->a = a;
			newcell->b = b;
			newcell->left = 0;
			newcell->right = 0;
			_cur = _root;
			while (_cur)
			{
				if (_cur->a == a)
					_cur->b = b;
				parent = _cur;
				if (_cur->a < a)
					_cur = _cur->right;
				else
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
			else
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
			else
				_cur = _cur->left;
		}
		throw std::invalid_argument("Error!");
	};

	int heightdiff(cell *c)
	{
		if (c == 0) return 0;
		return height(c->left) - height(c->right);
	};

	int height(cell *c)
	{
		if (c == 0) return 0;
		return 1 + max(height(c->left), height(c->right));
	};

	void rotCCW(cell *c1)
	{
		if (c1 == 0) return;
		cell *parent = c1->parent;
		cell*c2 = c1->right;
		if (c2 == 0) return;
		cell *T2 = c2->left;
		c1->right = T2;
		T2->parent = c1;
		c2->left = c1;
		c1->parent = c2;
		c2->parent = parent;
		if (parent)
		{
			if (parent->right == c1)
				parent->right = c2;
			else
				parent->left = c2;
		}
	};

	void rotCCW2(cell *c1)
	{
		if (c1 == 0) return;
		cell*parent = c1->parent;
		cell*c2 = c1->left;
		if (c2 == 0) return;
		cell*T2 = c2->right;
		c1->left = T2;
		T2->parent = c1;
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
	};
};

#endif