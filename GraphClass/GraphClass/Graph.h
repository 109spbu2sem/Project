#ifndef GRAPH_H
#define GRAPH_H

class Graph // :public GenerateOfMatrix					//"Inherit a class generating matrix"
{
	//int**_matr_smezh;						// This is the resulting matrix
	//int*_v;							// The dimension of the matrix

	int**umnog(int**matr1, int**matr2, int**matr3, int v);
	int**slog(int**E1, int**E2, int**E3, int**E4, int**matr_dostizh, int v);
	int**transp(int**helper, int**test, int v);
	int**GetC(int**matr_dostizh, int **contr_dostizh, int**C, int v);

public:
	Graph();
	~Graph();
	void realiz(int**_matr_smezh, int _v);
};

#endif
