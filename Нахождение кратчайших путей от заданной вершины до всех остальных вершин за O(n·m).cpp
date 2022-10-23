#include <bits/stdc++.h>

using namespace std;

vector<int> FB(const vector<tuple<int,int,int> > &edges,int n,int m,int start)
{
    const int INF = 1e9;
    vector<int> f(n,INF);
    f[start] = 0;
    for (int k = 0;k<n-1;k+=1)
        for (int i = 0;i<m;i+=1)
        {
            int  u = get<0>(edges[i]);
            int  v = get<1>(edges[i]);
            int  w = get<2>(edges[i]);
            if (f[u]+w<f[v])
                f[v] = f[u]+w;
        }
    return f;
}

/*
-edges - массив ребер.
 n - количество вершин.
 m - количество ребер.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков ребер.
 Элемент в массиве edges вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция FB возвращает массив с кратчайшими длинами от start до каждой, 
 причем если пути нету то на месте длины пути будет константа INF.
-Нумерация с 0.
(Алгоритм Форда - Беллмана)
*/