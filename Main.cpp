#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int NumOfN = 4;

void PrintTArr(int*** MatrSum)
{
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << endl;
		for (int j = 0; j < NumOfN; j++)
		{
			for (int g = 0; g < NumOfN; g++)
			{
				cout << MatrSum[i][j][g] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

void PrintDArr(int** MatrSum)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(3) << MatrSum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int DiferArr(int** MatrDif1, int** MatrDif2)
{
	int res = 0;
	for (int i = 0; i < NumOfN; i++)
	{
		for (int j = 0; j < NumOfN; j++)
		{
			if (MatrDif1[i][j] != MatrDif2[i][j])
				res++;
		}
	}
	return res;
}

void DifArr(int*** MatrSum, int** MatrDif)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MatrDif[i][j] = DiferArr((MatrSum[i]), (MatrSum[j]));
		}
	}
}

void KlusterArr(int*** MatrSum, vector<vector<double>> dano)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < NumOfN; j++)
		{
			for (int g = 0; g < NumOfN; g++)
			{
				if (dano[i][j] <= dano[i][g])
				{
					MatrSum[i][j][g] = 1;
				}
			}
		}
	}
}

int main()
{
	vector<vector<double>> dano = {
		{ 1  , 2.5, 2.5, 4  , 5  , 6.5, 6.5, 8 },
		{ 1.5, 4  , 1.5, 3  , 5  , 8  , 6  , 7 },
		{ 1  , 3  , 4  , 2  , 7  , 5  , 8  , 6 },
		{ 1  , 2.5, 4  , 2.5, 5  , 6  , 8  , 7 },
		{ 7  , 1  , 3  , 2  , 6  , 4  , 5  , 8 },
		{ 1  , 6  , 5  , 3  , 8  , 4  , 2  , 7 },
		{ 2  , 5  , 1  , 4  , 3  , 6  , 7  , 8 },
		{ 2  , 1  , 4  , 3  , 7  , 8  , 6  , 5 },
		{ 1.5, 1.5, 3  , 5  , 4  , 6  , 7  , 8 },
		{ 5  , 3  , 2  , 1  , 8  , 4  , 7  , 6 }
	};
	vector<vector<double>> danok1 = {
		{ 1  , 2.5, 2.5, 4   },
		{ 1.5, 4  , 1.5, 3   },
		{ 1  , 3  , 4  , 2   },
		{ 1  , 2.5, 4  , 2.5 },
		{ 7  , 1  , 3  , 2   },
		{ 1  , 6  , 5  , 3   },
		{ 2  , 5  , 1  , 4   },
		{ 2  , 1  , 4  , 3   },
		{ 1.5, 1.5, 3  , 5   },
		{ 5  , 3  , 2  , 1   }
	};
	vector<vector<double>> danok2 = {
		{ 5  , 6.5, 6.5, 8 },
		{ 5  , 8  , 6  , 7 },
		{ 7  , 5  , 8  , 6 },
		{ 5  , 6  , 8  , 7 },
		{ 6  , 4  , 5  , 8 },
		{ 8  , 4  , 2  , 7 },
		{ 3  , 6  , 7  , 8 },
		{ 7  , 8  , 6  , 5 },
		{ 4  , 6  , 7  , 8 },
		{ 8  , 4  , 7  , 6 }
	};
	//cout << dano[9][1] << endl;
	int*** MatrSum;
	MatrSum = new int**[10];
	for (int i = 0; i < 10; i++)
	{
		MatrSum[i] = new int*[NumOfN];
		for (int j = 0; j < NumOfN; j++)
		{
			MatrSum[i][j] = new int[NumOfN];
			for (int g = 0; g < NumOfN; g++)
			{
				MatrSum[i][j][g] = 0;
			}
		}
	}
	int** MatrDif;
	MatrDif = new int*[10];
	for (int j = 0; j < 10; j++)
	{
		MatrDif[j] = new int[10];
		for (int g = 0; g < 10; g++)
		{
			MatrDif[j][g] = 0;
		}
	}
	//cout << DiferArr(MatrSum[0], MatrSum[0]) << endl;
	KlusterArr(MatrSum, danok1);
	//int i =  DiferArr(MatrSum[1], MatrSum[0]);
	DifArr(MatrSum, MatrDif);
	PrintDArr(MatrDif);
	PrintTArr(MatrSum);
	system("pause");
}