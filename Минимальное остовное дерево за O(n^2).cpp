#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector< tuple<int,int,int> > MST(const vector< vector<int> > &g, int n)
{
    vector<bool> used(n,false);
    vector<int> min_e (n,INF);
    vector<int> sel_e (n,-1);
    vector< tuple<int,int,int> > ans;
    min_e[0] = 0;
    for (int i = 0;i < n;++i)
    {
        int v = -1;
        for (int j = 0;j < n;++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF)
            return {};

        used[v] = true;
        if (sel_e[v] != -1)
            ans.push_back(make_tuple(v,sel_e[v],g[v][sel_e[v]]));

        for (int to = 0;to < n;++to)
            if (g[v][to] < min_e[to])
            {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    return ans;
}

/*
-g - матрица весов.
 n - количество вершин.
-Граф хранить в виде матрицы, алгоритм работает для НЕОРИЕНТИРОВАННОГО графа.
 g[i][j]-ый элемент означает -> из i в j за цену g[i][j], 
 цена равная INF означает, что нет пути из i в j.
-Функция MST возвращает граф в виде списка ребер являющийся Минимальным Остовным Деревом.
-Нумерация с 0;
(Алгоритм Ярника-Прима-Дейкстры)
*/