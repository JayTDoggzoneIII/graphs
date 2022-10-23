#include <bits/stdc++.h>

using namespace std;

bool _compW(const tuple<int,int,int> &t1, const tuple<int,int,int> &t2)
{
    return get<2>(t1) < get<2>(t2);
}

int _dsu_get(int v, vector<int> &p)
{
    return v == p[v] ? v : p[v] = _dsu_get(p[v],p);
}

void _dsu_unite(int a, int b, vector<int> &p)
{
    a = _dsu_get(a,p);
    b = _dsu_get(b,p);
    if (rand()&1)
        swap(a,b);
    if (a!=b)
        p[a] = b;
}

vector< tuple<int,int,int> > MST(vector< tuple<int,int,int> > g, int n, int m)
{
    vector< tuple<int,int,int> > res;
    int cost = 0;
    sort(g.begin(),g.end(),_compW);
    vector<int> p (n);
    for (int i = 0;i < n;++i)
        p[i] = i;
    for (auto i : g)
    {
        int u,v,w;
        u = get<0>(i);
        v = get<1>(i);
        w = get<2>(i);
        if (_dsu_get(u,p) != _dsu_get(v,p))
        {
            cost+=w;
            res.push_back(make_tuple(u,v,w));
            _dsu_unite(u,v,p);
        }
    }
    return res;
}

/*
-g - массив ребер.
 n - количество вершин.
 m - количество ребер.
-Граф хранить в виде списка ребер, алгоритм работает для НЕОРИЕНТИРОВАННОГО графа.
 Элемент в массиве g вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция MST возвращает граф в виде списка ребер являющийся Минимальным Остовным Деревом.
-Нумерация с 0;
(Алгоритм Краскала с системой непересекающихся множеств)
*/