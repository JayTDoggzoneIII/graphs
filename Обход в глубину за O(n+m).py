﻿def dfs(start:int,g:list,visited:list) -> None:
    visited[start] = True
    for next in g[start]:
        if (not visited[next]):
            dfs(next,g,visited)

'''
-g - массив со списками смежностей.
 visited - булевый массив размером на количество вершин забитый False-ами.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция dfs находит лексикографически первый путь в графе.
-Нумерация с 0.
'''