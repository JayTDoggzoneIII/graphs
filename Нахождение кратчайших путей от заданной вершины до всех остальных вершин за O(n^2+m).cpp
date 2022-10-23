#include <bits/stdc++.h>

using namespace std;

vector<int> d(const vector<vector<pair<int,int> > > &g,int start,int n)
{
    const int INF=1e9;
    vector<int> dist(n+1,INF);
    dist[start] = 0;
    vector<int> prev(n+1,0);
    vector<bool> used(n+1,false);
    int u = start;
    while(u)
    {
        used[u] = true;
        for (auto edge:g[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                prev[v] = u;
            }
        }
        u = 0;
        int min_dist = INF;
        for (int i = 1;i<=n;i+=1)
        {
            if(!used[i] && dist[i]<min_dist)
            {
                u = i;
                min_dist = dist[i];
            }
        }
    }
    return dist;
}

/*
-g - массив со списками смежностей.
 n - количество вершин.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент (j,w), значит из i можно попасть в j за цену w.
-Функция Dijkstra возвращает массив с кратчайшими длинами от start до каждой, 
 причем если пути нету то на месте длины пути будет константа INF.
-Нумерация с 1.
(Алгоритм Дейкстры)
*/