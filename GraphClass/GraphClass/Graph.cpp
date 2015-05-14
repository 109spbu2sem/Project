#include "Graph.h"

int** Graph::umnog(int**matr1, int**matr2, int**matr3, int v)
{
	int i, j, k;
	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			for (k = 0, matr3[i][j] = 0; k < v; k++)
				matr3[i][j] += matr1[i][k] * matr2[k][j];
		}
	}
	return matr3;
};

int** Graph::slog(int**E1, int**E2, int**E3, int**E4, int**matr_dostizh, int v)
{
	int i, j;
	for (i = 0; i < v; i++)
	for (j = 0; j < v; j++)
		matr_dostizh[i][j] = E1[i][j] + E2[i][j];
	for (i = 0; i < v; i++)
	for (j = 0; j < v; j++)
		matr_dostizh[i][j] = matr_dostizh[i][j] + E3[i][j];
	for (i = 0; i < v; i++)
	for (j = 0; j < v; j++)
		matr_dostizh[i][j] = matr_dostizh[i][j] + E4[i][j];

	return matr_dostizh;
};

int** Graph::transp(int**helper, int**test, int v)
{
	for (int i = 0; i < v; i++)
	for (int j = 0; j < v; j++)
		test[i][j] = helper[i][j];

	int t;
	for (int i = 0; i < v; i++)
	{
		for (int j = i; j < v; j++)
		{
			t = test[i][j];
			test[i][j] = test[j][i];
			test[j][i] = t;
		}
	}

	return test;
};

int** Graph::GetC(int**matr_dostizh, int **contr_dostizh, int**C, int v)
{
	int i, j;
	for (i = 0; i < v; i++)
	for (j = 0; j < v; j++)
		C[i][j] = matr_dostizh[i][j] * contr_dostizh[i][j];
	return C;
};


void Graph::realiz(int** _matr_smezh, int _v)
{
	int **E1 = new int*[_v];
	int **E2 = new int*[_v];
	int **E3 = new int*[_v];
	int **E4 = new int*[_v];
	int **matr_dostizh = new int*[_v];
	int **contr_dostizh = new int*[_v];
	int **C = new int*[_v];
	for (int i = 0; i < _v; i++)
	{
		E1[i] = new int[_v];
		E2[i] = new int[_v];
		E3[i] = new int[_v];
		E4[i] = new int[_v];
		matr_dostizh[i] = new int[_v];
		contr_dostizh[i] = new int[_v];
		C[i] = new int[_v];
	}

	E1 = _matr_smezh;
	E2 = umnog(E1, E1, E2, _v);
	E3 = umnog(E2, E1, E3, _v);
	E4 = umnog(E3, E1, E4, _v);
	matr_dostizh = slog(E1, E2, E3, E4, matr_dostizh, _v);

	for (int i = 0; i < _v; i++)
	for (int j = 0; j < _v; j++)
		matr_dostizh[i][j] = !!matr_dostizh[i][j];
	contr_dostizh = transp(matr_dostizh, contr_dostizh, _v);
	C = GetC(matr_dostizh, contr_dostizh, C, _v);

	delete[] E1;
	delete[] E2;
	delete[] E3;
	delete[] E4;
	delete[] matr_dostizh;
	delete[] contr_dostizh;
	delete[] C;
};

Graph::Graph(){};
Graph::~Graph(){};