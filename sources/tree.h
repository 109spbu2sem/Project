template<typename A,typename B> class tree_storage
{
	struct cell
	{
		cell *left;
		cell *right;
		A a;
		B b;
	};
	cell *_root;
public:
	tree_storage()
	{
		_root = 0;
	};
	~tree_storage(void);
	void add(const A& a, const B& b)
	{
		if (_root ==0)
	{
		_root = new cell;
		_root->a = a;
		_root->b = b;
		_root->left = 0;
		_root->right = 0;
		_root->cur = 0;
	}
		else
		{
			newcell = new cell;
			newcell->a = a;
			newcell->b =b;
			newcell->left = 0;
			newcell->right = 0;
			cell *cur = _root;
			cell *parent = 0;
			while (cur)
			{
				if(cur->a == a)
					cur->b = b;
				parent = cur;
				if (cur->a < a)
					cur = cur->right;
				else 
					cur = cur->left;
			}
			if (parent->a < a) 
				parent->right = newcell;
			else
				parent->left = newcell;
		}

	}
	bool hasA(const A& a)
	{
		cell *cur = _root;
		while (!cur)
		{
			if (cur->a == a) 
				return true;
			if (cur->a < a)
				cur = cur->right;
			else 
				cur = cur->left;
		}

	}
	B& getBbyA(const A& a);

};
