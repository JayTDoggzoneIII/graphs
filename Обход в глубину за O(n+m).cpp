#include <bits/stdc++.h>

using namespace std;

void dfs(int start,const vector<vector<int> > &g,vector<bool> &visited)
{
    visited[start] = true;
    for (auto next:g[start])
    {
        if (!visited[next])
        {
            dfs(next,g,visited);
        }
    }
}

/*
-g - массив со списками смежностей.
 visited - булевый массив размером на количество вершин забитый false-ами.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция dfs находит лексикографически первый путь в графе.
-Нумерация с 0.
*/