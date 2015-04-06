#include <iostream>
using namespace std;

struct cell {
	int a;
	char b;
	//cell*parent;
	cell*right;
	cell*left;
};
int main() {
	cell*min1,*min2;
	cell*node;
	int sum;
	int count = 0;
	int size = 7;
	char ch[7] = { 'b', 'e', 'p', ' ', 'o', 'r', '!' };
	int num[7] = { 3, 4, 2, 2, 2, 1, 1 };
	cell*connect = new cell[size];
	for (unsigned i = 0; i < 7; ++i) {
		connect[i].a = num[i];
		connect[i].b = ch[i];
		connect[i].left = 0;
		connect[i].right = 0;
	}
	for (unsigned i = 0; i < 6; ++i)
	for (unsigned j = i+1; j < 7; ++j)
	if (connect[i].a > connect[j].a) {
		swap(connect[i].a, connect[j].a);
		swap(connect[i].b, connect[j].b);
	}
	while (size != 1) {
		min1->a = connect[count].a;
		min2->a = connect[count + 1].a;
		min1->b = connect[count].b;
		min2->b = connect[count + 1].b;
		sum = min1->a + min2->a;
		node->left = min1;
		node->right = min2;
		node->a = sum;
		--size;
		cell*newconnect = new cell[size - 1];
		for (unsigned i = 0; i < size - 1; ++i) {
			newconnect[i] = connect[i + 2];
			if (newconnect[i].a > sum) {
				newconnect[i + 1].a = newconnect[i].a;
				newconnect[i].a = sum;
				++i;
			}
		}
		connect = newconnect;
	}
	return 0;
}