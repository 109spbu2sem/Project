#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>

using namespace std;
unsigned const v = 11;  // ������
unsigned const n = 11;  // �������, ������� �� ����� 

// ����� ����� ����
// ��������� ��� �������� �� ������� ��������
// � ������� ���������� ������ ���������

int**umnog(int**matr1, int**matr2, int v)
{
	int**matr3 = new int*[v];
	for (int i = 0; i < v; i++)
		matr3[i] = new int[v];

	/*
		1) A[n*m] * B[m*k] = AB[a*k];
		2) A[n*n] * B[n*n] = AB[n*n];
		3) A[n*m] * B[k*l] = X;

		if ("m1" - ���-�� �������� �-�� A == "m2" - ���-�� ����� �-�� B =>  A[n*m1] * B[m2*n] = AB[n*n];
		if ("m1" - ���-�� �������� �-�� A != "m2" - ���-�� ����� �-�� B =>  A[n*m1] * B[m2*n] = X; (�� ����������) 
	*/

	int i, j, k;
	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			for (k = 0, matr3[i][j] = 0; k < v; k++)
			{
				matr3[i][j] += matr1[i][k] * matr2[k][j]; 
			}
		}
	}
	return matr3;
}

int**slog(int**E1, int**E2, int**E3, int**E4, int v)
{
	// ����� ��������� E1 + E2 + E3 + E4;
	int i, j;
	int** matr_dostizh = new int*[v];
	for (int i = 0; i < n; i++)
		matr_dostizh[i] = new int[v];
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

int**umnogpoel(int**matr_dostizh, int **contr_dostizh)
{
	int i, j;
	int** C = new int*[v];
	for (int i = 0; i < v; i++)
		C[i] = new int[v];
	for (i = 0; i < v; i++)
	for (j = 0; j < v; j++)
		C[i][j] = matr_dostizh[i][j] * contr_dostizh[i][j];
	return C;
}

int** transp(int**helper, int v)
{
	int**test = new int*[v];
	for (int i = 0; i < v; i++)
		test[i] = new int[v];
	
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
}

int**blockdiag(int**C)
{
	int**block_diag_matr = new int*[v];
	int**matr_help = new int*[v];
	for (int i = 0; i < v; i++)
	{
		block_diag_matr[i] = new int[v];
		matr_help[i] = new int[v];
	}
	int*mass_help = new int[v*v];

	int i, j, k = 0, b = 0;
	for (i = 0; i < v; i++)
	for (j = 0; j < v; j++)
	{
		while (C[i][j] != 1)
		{
			if (j < v) j++; 
			if (j == v) { k++; break; }
		}
		if (k > 0) { k = 0; continue; }
		mass_help[b] = j; b++;
		for (int h = j + 1; h < v; h++)
		{
			if (C[h][j] == 1)
			{ 
				mass_help[b] = h; 
				b++;
				//k++;
				// ������� ����������) 
			}
		}
		
	}
	for (i = 0; i < v; i++)
		cout << mass_help[i] << " " << endl;
	return block_diag_matr;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));

	// �������� �������� ������� ���������
	int **matr_smezh = new int*[v];       
	for (int i = 0; i < v; i++)				
	{
		matr_smezh[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			if (rand() % 100 < 20) matr_smezh[i][j] = 1;
			else matr_smezh[i][j] = 0;
		}
	}

	/*matr_smezh[0][0] = 0; matr_smezh[0][1] = 1; matr_smezh[0][2] = 1; matr_smezh[0][3] = 0;
	matr_smezh[1][0] = 0; matr_smezh[1][1] = 0; matr_smezh[1][2] = 0; matr_smezh[1][3] = 0;
	matr_smezh[2][0] = 0; matr_smezh[2][1] = 1; matr_smezh[2][2] = 0; matr_smezh[2][3] = 1;
	matr_smezh[3][0] = 0; matr_smezh[3][1] = 0; matr_smezh[3][2] = 1; matr_smezh[3][3] = 0;*/

	// ������� ������� ���������
	// ��� ������ ����������
	cout << "___________________________________" << endl;
	cout << "___________�������_���������_______" << endl;
	for (int i = 0; i < v; i++)	
	for (int j = 0; j < v; j++)
	{
		if (j < v - 1) cout << matr_smezh[i][j] << " ";
		if (j == v - 1) cout << matr_smezh[i][j] << " " << endl;
	}

	// ������� ������� ������������ 
	int **E1 = new int*[v];
	int **E2 = new int*[v];
	int **E3 = new int*[v];
	int **E4 = new int*[v];
	int **matr_dostizh = new int*[v];
	int **contr_dostizh = new int*[v];
	int **C = new int*[v];
	int **BLOCK = new int*[v];
	for (int i = 0; i < v; i++)
	{
		E1[i] = new int[v];
		E2[i] = new int[v];
		E3[i] = new int[v];
		E4[i] = new int[v];
		matr_dostizh[i] = new int[v];
		contr_dostizh[i] = new int[v];
		C[i] = new int[v];
		BLOCK[i] = new int[v];
	}

	// ��������� ������ E*E; E^2*E; E^3*E;
	E1 = matr_smezh;
	E2 = umnog(E1, E1, v);
	E3 = umnog(E2, E1, v);
	E4 = umnog(E3, E1, v);

	// �������� ������: E+E2+E3+E4;
	matr_dostizh = slog(E1, E2, E3, E4, v);

	// �������� ������� ������������ � "�����������" ���� - �������� ������� ���������.
	for (int i = 0; i < v; i++)
	for (int j = 0; j < v; j++)
		matr_dostizh[i][j] = !!matr_dostizh[i][j];

	// x =  !!x; �������� - ���, ��� ���� 0 - ����� 0, !0 => 1;

	// ������� ������� ������������ R [R = matr_dostizh];
	cout << "___________________________________" << endl;
	cout << "_______�������_������������________" << endl;
	for (int i = 0; i < v; i++)
	for (int j = 0; j < v; j++)
	{
		if (j < v - 1) cout << matr_dostizh[i][j] << " ";
		if (j == v - 1) cout << matr_dostizh[i][j] << " " << endl;
	}
	cout << endl;

	// ������� ������� ����������������� Q, ������������� ������� ������������   [Q = contr_dostizh];
	contr_dostizh = transp(matr_dostizh, v);

	// ����� ����������������� ������� ������������
	cout << "___________�������_________________" << endl;
	cout << "_______�����������������___________" << endl;
	for (int i = 0; i < v; i++)
	for (int j = 0; j < v; j++)
	{
		if (j < v - 1) cout << contr_dostizh[i][j] << " ";
		if (j == v - 1) cout << contr_dostizh[i][j] << " " << endl;
	}
	cout << endl;
	
	// ������ ������� C, ���������� ������������ ���������� Q � R
	C = umnogpoel(matr_dostizh, contr_dostizh);

	cout << "___________________________________" << endl;
	cout << "_________�������_C_________________" << endl;
	// ����� ������� C
	for (int i = 0; i < v; i++)
	for (int j = 0; j < v; j++)
	{
		if (j < v - 1) cout << C[i][j] << " ";
		if (j == v - 1) cout << C[i][j] << " " << endl;
	}
	cout << endl;
	
	//BLOCK = blockdiag(C);
	
	
	
	
	return 0;
}