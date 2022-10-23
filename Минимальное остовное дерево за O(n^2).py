INF = 10**9
def MST(g:list, n:int) -> list:
    ans = []
    used = [False]*n
    min_e = [INF]*n
    min_e[0] = 0
    sel_e = [-1]*n
    for i in range(n):
        v = -1
        for j in range(n):
            if (not used[j] and (v == -1 or min_e[j] < min_e[v])):
                v = j
        if (min_e[v] == INF):
            return [];
        used[v] = True
        if (sel_e[v] != -1):
            ans.append((v,sel_e[v],g[v][sel_e[v]]))
        for to in range(n):
            if (g[v][to] < min_e[to]):
                min_e[to] = g[v][to]
                sel_e[to] = v
    return ans;

'''
-g - матрица весов.
 n - количество вершин.
-Граф хранить в виде матрицы, алгоритм работает для НЕОРИЕНТИРОВАННОГО графа.
 g[i][j]-ый элемент означает -> из i в j за цену g[i][j], 
 цена равная INF означает, что нет пути из i в j.
-Функция MST возвращает граф в виде списка ребер являющийся Минимальным Остовным Деревом.
-Нумерация с 0;
(Алгоритм Ярника-Прима-Дейкстры)
'''