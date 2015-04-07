#ifndef _TREESTOR_H
#define _TREESTOR_H
template<typename A,typename B> class tree_storage
{
public:
	struct tuple{
		A a;
		B b;
	};
	tree_storage(){_root = 0;_size = 0;};
	~tree_storage(){};


	template<typename A,typename B>class Viewer{
		typename tree_storage<A,B>::cell *_cur;		
	public:		
		Viewer(){_cur = 0;}
		Viewer(tree_storage&s){
			_cur = s._root;			
			if (_cur)
				while (_cur->left)
					_cur = _cur->left;				
		}

		typename tree_storage::tuple & getValue(){
			if (_cur) return _cur->data;
			throw std::runtime_error("Invalid viewer");};

		void moveNext(){
			if (_cur->right != 0){
				_cur = _cur->right;
				while (_cur->left)
					_cur = _cur->left;
			}
			else{				
				if (_cur->parent){
					if (_cur->parent->left == _cur) 
						// Идем по левой ветке
						_cur = _cur->parent;
					else{
						// Идем по правой ветке
						while (_cur->parent && _cur == _cur->parent->right)
							_cur = _cur->parent;
						_cur = _cur->parent;
					}
				}
			}
			
		};
		bool canMoveNext(){
			if ( _cur == 0) return false;
			return true;
		};
	};
	void add(const A& a,const B& b ){
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
			while (cur){
				if (cur->data.a == a){
					cur->data.b = b;
					return;
				}
					
				parent = cur;
				if (cur->data.a < a) 					
					cur = cur->right;
				else cur = cur->left;
			}
			if (parent->data.a < a) parent->right = newcell;
			else parent->left = newcell;
			newcell->parent = parent;
		}
		++_size;
	}
	bool hasA(const A& a){
		cell *cur = _root;
		while (cur){			
			if (cur->data.a == a ) return true;
			if (cur->data.a < a) cur = cur->right;
			else cur = cur->left;
		}
		return false;
	};
	B& getBbyA(const A& a){
		cell *cur = _root;
		while (cur){			
			if (cur->a == a ) return cur->b;
			if (cur->a < a) cur = cur->right;
			else cur = cur->left;
		}
		throw 1;
	};
	unsigned size()const {return _size;};

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

	friend class Viewer<A,B>;
};

template<typename A,typename B> int tree_storage<A,B>::heightdiff(cell *c){
	if (c == 0) return 0;
	return height(c->left) - height(c->right);
}
template<typename A,typename B> int tree_storage<A,B>::height(cell *c){
	if (c == 0) return 0;
	return 1+max(height(c->left),height(c->right));
}
template<typename A,typename B> void tree_storage<A,B>::rotCCW(cell *c1){
	if (c1 == 0) return;
	cell *parent = c1->parent;
	//cell* T1 = c1->left;
	cell*c2 = c1->right;
	if (c2 == 0) return;
	cell *T2 = c2->left;
	//cell *T3 = c2->right;
	
	c1->right = T2;
	T2->parent = c1;

	c2->left = c1;
	c1->parent = c2;

	c2->parent = parent;
	if (parent) {
		if (parent->right == c1 ) 
			parent->right = c2;
		else
			parent->left = c2;
	} 




}
#endif