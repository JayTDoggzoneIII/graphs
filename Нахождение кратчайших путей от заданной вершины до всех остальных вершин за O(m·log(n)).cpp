#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
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

/*
-g - ������ �� �������� ����������.
 n - ���������� ������.
 start - ������� ��� ������� ����������� ��������.
-���� ������� � ���� ������� ����������.
 ���� � i-�� ������� ���� ������� (j,w), ������ �� i ����� ������� � j �� ���� w.
-������� Dijkstra ���������� ������ � ����������� ������� �� start �� ������, 
 ������ ���� ���� ���� �� �� ����� ����� ���� ����� ��������� INF.
-��������� � 0.
(�������� ��������)
*/