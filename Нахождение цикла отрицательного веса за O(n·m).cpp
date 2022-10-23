#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<int> solve(const vector< tuple<int,int,int> > &e, int n, int m)
{
    vector<int> d (n,INF);
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
        return {};
    else
    {
        int y = x;
        for (int i = 0;i < n;++i)
            y = p[y];
        vector<int> path;
        int cur = y;
        while (true)
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
            cur = p[cur];
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

/*
-e - массив ребер.
 n - количество вершин.
 m - количество ребер.
-Граф хранить в виде списка ребер.
 Элемент в массиве edges вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция solve возвращает массив, который является циклом отрицательного веса если он есть, 
 иначе пустой массив.
-Нумерация с 0.
(Алгоритм Форда - Беллмана)
*/