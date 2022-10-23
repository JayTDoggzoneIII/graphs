#include <bits/stdc++.h>

using namespace std;

vector<int> comp;
void _dfs (vector<bool> &used, vector<vector<int> > &g,int v)
{
	used[v] = true;
	comp.push_back(v);
	for (int i = 0; i<g[v].size(); ++i)
    {
		int to = g[v][i];
		if (!used[to])
			_dfs (used,g,to);
	}
}

vector< vector<int> > find_comps(vector<bool> &used, vector<vector<int> > &g, int n)
{
    vector< vector<int> > ans;
    for (int i = 0;i < n;++i)
        used[i] = false;
    for (int i = 0;i < n;++i)
    {
        if (!used[i])
        {
            comp.clear();
            _dfs(used,g,i);
            vector<int> pr;
            for (int j = 0;j < comp.size();++j)
                pr.push_back(comp[j]);
            ans.push_back(pr);
        }
    }
    return ans;
}

/*
-g - массив со списками смежностей.
 used - булевский массив забитый false-ами.
 n - число вершин в графе.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция find_comps Возвращает массив с массивами вершин которые находятся в одной компоненте связности.
*/