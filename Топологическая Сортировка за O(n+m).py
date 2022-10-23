ans = []
def _dfs(used:list, g:list, v:int) -> None:
    used[v] = True
    for i in range(len(g[v])):
        to = g[v][i]
        if (not used[to]):
            _dfs(used,g,to)
    ans.append(v)
    
def top(used:list, g:list, n:int) -> None:
    for i in range(n):
        used[i] = False
    ans.clear()
    for i in range(n):
        if (not used[i]):
            _dfs(used,g,i)
    ans.reverse()


'''
-g - массив со списками смежностей.
 n - число вершин в графе.
 used - булевский массив забитый False-ами.
 ans - пустой массив для ответа.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция top перенумеровывает вершины таким образом, чтобы каждое ребро вело из вершины с меньшим номером в вершину с большим.
'''