#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int> > &a,int n,int start)
{
    const int INF = -1;
    queue<int> q;
    vector<int> dist (n,INF);
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v:a[u])
        {
            if (dist[v] == INF)
            {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}

/*
-a - массив со списками смежностей.
 n - количество вершин.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей, граф должен быть НЕвзвешенным.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция bfs возвращает массив с кратчайшими длинами от start до каждой, 
 причем если пути нету то на месте длины пути будет константа INF.
-Нумерация с 0.
*/