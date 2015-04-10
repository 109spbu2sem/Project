#ifndef _TWOTREESTOR_H
#define _TWOTREESTOR_H
template<typename A,typename B> class twotree_storage
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
						// Ќаходимс€ слева от родител€
						_cur = _cur->parent;
					else{
						// Ќаходимс€ справа от родител€
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
		cell *cur = _root;
		
		// ѕростой случай - можем добавить лист 
		// с данными к текущему узлу
		if (cur->right == 0){
			if (cur->aleft < a ){
				cur->right = new cell;
				cur->right->data = new tuple;
				cur->right->data->a = a;
				cur->right->data->b = b;
			}

		}
	}
	bool hasA(const A& a){
		cell *cur = _root;
		while (cur && cur->center ){
			if (a < cur->aleft) 
				cur = cur->left;
			else if (cur->right && cur->aright <= a)
				cur = cur->right;
			else
				cur = cur->center;
		}	
		if (cur && cur->data && cur->data->a == a) return true;		
		return false;
	};
	B& getBbyA(const A& a){

		throw 1;
	};
	unsigned size()const {return _size;};

private:
		struct cell{
		cell *left;
		A aleft;
		cell *center;
		A aright;
		cell *right;
		cell *parent;
		tuple *data;
		cell():left(0),center(0),right(0),parent(0),data(0){};
	};
	cell *_root;
	unsigned _size;
	
	int height(cell *);
	
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