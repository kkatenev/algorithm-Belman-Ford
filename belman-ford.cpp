﻿#include <iostream>
#include "stdio.h"

#define inf 100000
using namespace std;
struct Edges{
int u, v, w; //v|u - смежные вершины, w - вес
};
const int Vmax=1000;
const int Emax=Vmax*(Vmax-1)/2;
int i, j, n, e, start;
Edges edge[Emax];
int d[Vmax]; //хранение сначала макс. элементов, а затем результатов 
//алгоритм Беллмана-Форда
void bellman_ford(int n, int s)
{
	int i, j;

	for (i = 0; i < n; i++) 
		d[i] = inf;
	d[s] = 0;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < e; j++)
			if (d[edge[j].v] + edge[j].w < d[edge[j].u]) //если сумма, составленная из веса ребра w(v, u) и веса хранящегося в элементе d[v]
				d[edge[j].u] = d[edge[j].v] + edge[j].w; //меньше веса d[u], то она присваивается последнему.

	for (i = 0; i < n; i++) if (d[i] == inf)
		cout << endl << start << "->" << i + 1 << "=" << "Not";
	else cout << endl << start << "->" << i + 1 << "=" << d[i];
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int w;

	cout << "Количество вершин > ";
	cin >> n;
	e = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << i + 1 << "->" << j + 1 << " > "; cin >> w;
			if (w != 0)
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = w;
				e++;
			}
		}

	cout << "Стартовая вершина > "; 
	cin >> start;
	cout << "Список кратчайших путей:";
	bellman_ford(n, start - 1);
	system("pause>>void");
}