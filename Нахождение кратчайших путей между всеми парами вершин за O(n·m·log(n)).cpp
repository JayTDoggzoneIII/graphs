#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<int> FB(const vector< tuple<int,int,int> > &e, int n, int m,int start)
{
    vector<int> d (n,INF);
    d[start] = 0;
    vector<int> p (n,-1);
    int x;
    for (int i = 0;i < n;++i)
    {
        x = -1;
        for (int j = 0;j < m;++j)
            if (d[get<1>(e[j])] > d[get<0>(e[j])] + get<2>(e[j]))
            {
                d[get<1>(e[j])] = (-INF > d[get<0>(e[j])] + get<2>(e[j])) ? -INF : d[get<0>(e[j])] + get<2>(e[j]);
                p[get<1>(e[j])] = get<0>(e[j]);
                x = get<1>(e[j]);
            }
    }
    if (x == -1)
        return d;
    else
        return {};
}


vector<int> Dijkstra(const vector< vector< pair<int,int> > > &g, int n, int start)
{
    vector<int> dist(n,INF);
    vector<int> p(n,0);
    dist[start] = 0;
    priority_queue< pair<int,int> > q;
    q.push(make_pair(0,start));
    while (!q.empty())
    {
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
        if (cur_d > dist[v])
            continue;
        int l = g[v].size();
        for (int j = 0;j < l;++j)
        {
            int to = g[v][j].first;
            int len = g[v][j].second;
            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                p[to] = v;
                q.push(make_pair(-dist[to],to));
            }
        }
    }
    return dist;
}

vector< tuple<int,int,int> > new_graph(const vector< tuple<int,int,int> > &g, int n)
{
    vector< tuple<int,int,int> > _g (g);
    for (tuple<int,int,int> uvw : g)
    {
        int u = get<0>(uvw);
        int v = get<1>(uvw);
        _g.push_back(make_tuple(n,u,0));
    }
    return _g;
}

vector< vector<int> > Johnson(const vector< tuple<int,int,int> > &g, int n, int m)
{
    vector< tuple<int,int,int> > _g = new_graph(g,n);
    vector<int> b1 = FB(_g,n+1,_g.size(),n);
    vector<int> b2;
    if (b1.empty())
        return {{}};
    vector< vector<int> > mas1(n,vector<int> (n,0));
    vector< vector< pair<int,int> > > mas2(n);
    for (tuple<int,int,int> uvw : g)
    {
        int u = get<0>(uvw);
        int v = get<1>(uvw);
        int w = get<2>(uvw);
        mas1[u][v] = w+b1[u]-b1[v];
    }
    for (tuple<int,int,int> uvw : g)
    {
        int u = get<0>(uvw);
        int v = get<1>(uvw);
        mas2[u].push_back(make_pair(v,mas1[u][v]));
    }
    for (int i = 0;i < n;++i)
    {
        b2 = Dijkstra(mas2,n,i);
        for (int j = 0;j < n;++j)
            mas1[i][j] = b2[j]+b1[j]-b1[i];
    }
    return mas1;
}

/*
-g - массив ребер.
 n - количество вершин.
 m - количество ребер.
-Граф хранить в виде списка ребер.
 Элемент в массиве g вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция Johnson возвращает матрицу с кратчайшими длинами от каждой до каждой, 
 причем если пути нету то на месте длины пути будет константа INF, а если есть
 путь бесконечно малого веса, возвращает пустую матрицу.
-Нумерация с 0;
(Алгоритм Джонсона)
*/