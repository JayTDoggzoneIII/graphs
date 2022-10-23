comp = []
def _dfs(used:list, g:list, v:int) -> None:
    used[v] = True
    comp.append(v)
    for i in range(len(g[v])):
        to = g[v][i]
        if (not used[to]):
            _dfs(used,g,to)

def find_comps(used:list,g:list,n:int) -> list:
    ans = []
    for i in range(n):
        used[i] = False
    for i in range(n):
        if (not used[i]):
            comp.clear()
            _dfs(used,g,i)
            pr = []
            for j in range(len(comp)):
                pr.append(comp[j])
            ans.append(pr)
    return ans;

'''
-g - массив со списками смежностей.
 used - булевский массив забитый False-ами.
 n - число вершин в графе.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция find_comps Возвращает массив с массивами вершин которые находятся в одной компоненте связности.
'''