#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
void _FU(vector< vector<int> > &a, int n)
{
    for (int k = 0;k < n;++k)
        for (int i = 0;i < n;++i)
            for (int j = 0;j < n;++j)
                a[i][j] = (a[i][j]<(a[i][k]+a[k][j])) ? a[i][j] : a[i][k]+a[k][j];
}

void solve(vector< vector<int> > &g, int n)
{
    _FU(g,n);
    for (int k = 0;k < n;++k)
        for (int i = 0;i < n;++i)
            for (int j = 0;j < n;++j)
                if (g[k][j] < INF && g[j][j] < 0 && g[j][i] < INF)
                    g[k][i] = -INF;
}

/*
-g - матрица смежностей.
 n - количество вершин.
-Граф хранить в виде матрицы смежности.
 g[i][j]-ый элемент означает -> из i в j за цену g[i][j], 
 цена равная INF означает, что нет пути из i в j.
-Функция solve делает из матрицы следующую вещь - если g[i][j] == -INF, значит путь из i в j бесконечно мал,
 иначе g[i][j] является кратчайшим путем из i в j.
-Нумерация с 0.
(Алгоритм Флойда - Уоршелла)
*/