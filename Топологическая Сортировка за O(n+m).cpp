#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
void _dfs (vector<bool> &used, vector<vector<int> > &g,int v)
{
	used[v] = true;
	for (int i = 0; i<g[v].size(); ++i)
    {
		int to = g[v][i];
		if (!used[to])
			_dfs (used,g,to);
	}
	ans.push_back (v);
}

void topological_sort(vector<bool> &used,vector<vector<int> > &g, int n)
{
	for (int i = 0; i<n; ++i)
		used[i] = false;
	ans.clear();
	for (int i = 0; i<n; ++i)
		if (!used[i])
			_dfs (used,g,i);
	reverse (ans.begin(), ans.end());
}


/*
-g - массив со списками смежностей.
 n - число вершин в графе.
 used - булевский массив забитый false-ами.
 ans - пустой массив для ответа.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция top перенумеровывает вершины таким образом, чтобы каждое ребро вело из вершины с меньшим номером в вершину с большим.
*/