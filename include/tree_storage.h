#ifdef _TREESTOR_H
#define _TREESTOR_H
template<typename A,typename B>class tree_storage
{
	struct cell{
		cell *left;
		cell *right;
		cell *parent;
		A a;
		B b;
	};
	cell *_root;
	int heightdiff(cell *);
	int height(cell *);
	void rotCCW(cell *);
	void rotCW(cell *);
public:
	tree_storage(){_root=0;};
	~tree_storage();

	void add(const A& a,const B& b){
		if(_root==0){
			_root=new cell;
			_root->parent=0;
			_root->a;
			_root->b;
			_root->left=_root->right=0;
		}
		else{
			cell *newcell=new cell;
			newcell->a=a;
			newcell->b=b;
			newcell->left=0;
			newcell->right=0;
			
			cell *cur=_root;
			cell *parent=0;
			while(cur){
				if (cur->a==a) cur->b=b;
				parent=cur;
				if (cur->a<a) 
					cur=cur->right;
				else cur=cur->left;
				
	
		}
		
		if(parent->a<a)parent->right=newcell;
		else parent->left=newcell;
		newcell->parent=parent;
		}
	}
	bool hasA(const A& a){
		cell *cur=_root;
		while(cur){
			if (cur->a==a) return true;
			if (cur->a<a) cur=cur->right;
			else cur=cur->left;
				}
		return false;
	};
	B& getBbyA(const A& a){
		cell *cur=_root;
		while(cur){
			
			if (cur->a==a) return b;
			if (cur->a<a) cur=cur->right;
			else cur=cur->left;
				}
		throw 1;

	};
};
template<typename A,typename B> int  tree_storage::int heightdiff(cell *c){
	if (c==0) return 0;
	return height (c->left)-height (c->right);

}
template<typename A,typename B> int  tree_storage::int height(cell *c){
	if (c==0) return 0;
	return 1+max(height (c->left),height (c->right));
}

template<typename A,typename B> int  tree_storage::void rotCCW(cell *c1){
	if(c1==0) return;
	cell *parent=c1->parent;
	//cell* T1=c1->left;
	cell* c2=c1->right;
	if(c2==0) return;
	cell *T2=c2->left;
	//cell *T3=c2->right;
	
	c1->right=T2;
	T2->parent=c1;
	
	c2->left=c1;
	c1->parent=c2;

	c2->parent=parent;
	if(parent){
		if(parent->right==c1)
			parent->right=c2;
		else
			parent->left=c2;
	}
}



template<typename A,typename B> int  tree_storage::void rotCW(cell *c1){
	if(c1==0) return;
	cell *parent=c1->parent;
	//cell* T1=c1->left;
	cell* c2=c1->left;
	if(c2==0) return;
	cell *T2=c2->right;
	//cell *T3=c2->right;
	
	c1->left=T2;
	T2->parent=c1;
	
	c2->right=c1;
	c1->parent=c2;

	c2->parent=parent;
	if(parent){
		if(parent->left==c1)
			parent->left=c2;
		else
			parent->right=c2;
	}
}
#endif
