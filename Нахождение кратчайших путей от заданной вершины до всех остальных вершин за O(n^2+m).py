INF = 10**9
def Dijkstra(g:list,start:int,n:int) -> list:
    dist = [INF]*(n+1)
    dist[start] = 0
    prev = [0]*(n+1)
    used = [False]*(n+1)
    u = start
    while (u):
        used[u] = True
        for edge in g[u]:
            v = edge[0]
            w = edge[1]
            if (dist[u]+w<dist[v]):
                dist[v] = dist[u]+w
                prev[v] = u
        u = 0
        min_dist = INF
        for i in range(1,n+1):
            if (not used[i] and dist[i]<min_dist):
                u = i
                min_dist = dist[i]
    return dist;

'''
-g - массив со списками смежностей.
 n - количество вершин.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент (j,w), значит из i можно попасть в j за цену w.
-Функция Dijkstra возвращает массив с кратчайшими длинами от start до каждой, 
 причем если пути нету то на месте длины пути будет константа INF.
-Нумерация с 1.
(Алгоритм Дейкстры)
'''