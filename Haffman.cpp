#include <iostream>
using namespace std;

struct cell {
	int a;
	char b;
	cell*right;
	cell*left;
};
struct con {
	char name;
	int num;
	con*next;
	con*firstcon;
	con*lastcon;
	con*currentcon;
};
int main() {
	cell*min1, *min2;
	cell*node;
	int sum;
	int count = 0;
	int size = 7;
	con*code = new con[size];
	char*ch = new char[size];
	ch[0] = 'b'; ch[1] = 'e'; ch[2] = 'p'; ch[3] = ' '; ch[4] = 'o'; ch[5] = 'r'; ch[6] = '!';
	int*num = new int[size];
	num[0] = 3; num[1] = 4; num[2] = 2; num[3] = 2; num[4] = 2; num[5] = 1; num[6] = 1;
	cell*connect = new cell[size];
	for (unsigned i = 0; i < 7; ++i) {
		connect[i].a = num[i];
		connect[i].b = ch[i];
		connect[i].left = 0;
		connect[i].right = 0;
	}
	for (unsigned i = 0; i < 6; ++i)
	for (unsigned j = i + 1; j < 7; ++j)
	if (connect[i].a > connect[j].a) {
		swap(connect[i].a, connect[j].a);
		swap(connect[i].b, connect[j].b);
	}
	while (size != 1) {
		min1 = new cell;
		min2 = new cell;
		node = new cell;
		*min1 = connect[count];
		*min2 = connect[count + 1];
		sum = min1->a + min2->a;
		node->left = min1;
		node->right = min2;
		node->a = sum;
		node->b = 0;
		--size;
		if (size == 1)
			cout << node->a << endl;
		else {
			cell*newconnect = new cell[size];
			for (unsigned i = 0; i < size - 1; ++i) {
				newconnect[i] = connect[i + 2];
				if (newconnect[i].a >= sum) {
					newconnect[i + 1] = newconnect[i];
					newconnect[i] = *node;
					++i;
					for (unsigned j = i; i < size; ++i)
						newconnect[i] = connect[i + 1];
				}
				if (newconnect[i].a < sum && i == size - 2)
					newconnect[i + 1] = *node;
			}
			connect = newconnect;
			for (unsigned i = 0; i < size; ++i)
				cout << connect[i].a;
			cout << endl;
		}
	}
	cell*cur;
	cell*parent;
	cur = node;
	count = 0;
	size = 7;
	while (count < size) {
		if (cur->left) {
			code[count].firstcon = new con;
			code[count].firstcon->num = 0;
			code[count].firstcon->next = 0;
		}
		else {
			code[count].firstcon = new con;
			code[count].firstcon->num = 1;
			code[count].firstcon->next = 0;
		}
		code[count].lastcon = code[count].firstcon;
		while (true) {
			while (cur->left) {
				parent = cur;
				cur = cur->left;
				code[count].currentcon = new con;
				code[count].currentcon->num = 0;
				code[count].currentcon->next = 0;
				code[count].lastcon->next = code[count].currentcon;
				code[count].lastcon = code[count].currentcon;
			}
			if (cur->right) {
				parent = cur;
				cur = cur->right;
				code[count].currentcon = new con;
				code[count].currentcon->num = 1;
				code[count].currentcon->next = 0;
				code[count].lastcon->next = code[count].currentcon;
				code[count].lastcon = code[count].currentcon;
			}
			if (!cur->left && !cur->right) {
				if (cur->b != 0) {
					code[count].lastcon->next = 0;
					code[count].name = cur->b;
					++count;
				}
				if (parent->left == cur) {
					delete[] cur;
					parent->left = 0;
				}
				else {
					delete[] cur;
					parent->right = 0;
				}
				cur = node;
				break;
			}
		}
	}
/*	con*curr = new con;
	curr = code[6].firstcon;
	while (curr->next) {
		curr = curr->next;
		cout << curr->num;
	}
	cout << endl;
	cout << code[0].name << code[1].name << code[2].name << code[3].name << code[4].name << code[5].name << code[6].name;*/
	return 0;
}