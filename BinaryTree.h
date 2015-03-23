#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename A, typename B> class BinaryTree
{
	struct cell {
		A a;
		B b;
		cell*right;
		cell*left;
	};
cell*_root;
cell*_cur;
public:
	BinaryTree() {
		_root = 0;
		_cur = 0;
	}
	~BinaryTree() {
		cell parent = _cur;
		while (_cur) {
			while (_cur->left)
				_cur = _cur->left;
			while (_cur->right)
				_cur = _cur ->right;
			if (!_cur->left && !_cur->right) {
				delete[] _cur;
				_cur = _root;
			}
		}
	}
	void add(A&, B&);
	bool hasA(A&);
	B & getBbyA(A);
};
template<typename A, typename B> void BinaryTree<A,B>::add(A&a, B&b){
	if (_root == 0) {
		_root = new cell;
		_root->a = a;
		_root->b = b;
		_root->right = 0;
		_root->left = 0;
	}
	else {
		cell*newcell = new cell;
		cell*parent;
		newcell->a = a;
		newcell->b = b;
		newcell->right = 0;
		newcell->left = 0;
		_cur = _root;
		while (_cur) {
			if (_cur->a == a)
				_cur->b == b;
			parent = _cur;
			if (_cur->a < a)
				_cur = _cur->right;
			if (_cur->a > a)
				_cur = _cur->left
		}
		if (parent->a < a)
			parent->right = newcell;
		if (parent->a > a)
			parent->left = newcell;
	}
}
template<typename A, typename B> bool BinaryTree<A, B>::hasA(A&a) {
	_cur = _root;
	while (_cur) {
		if (_cur->a == a)
			true;
		if (_cur->a < a)
			_cur = _cur->right;
		if (_cur->a > a)
			_cur = _cur->left;
	}
	return false;
}
template<typename A, typename B> B&getBbyA(A a) {
	_cur = _root;
	while (_cur) {
		if (_cur->a == a)
			return _cur->b;
		if (_cur->a < a)
			_cur = _cur->right;
		if (_cur->a > a)
			_cur = _cur->left;
	}
	throw std::invalid_argument("Nooooope");
}
#endif 

