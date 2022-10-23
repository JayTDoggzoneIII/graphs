from heapq import heappop,heappush
INF = 10**9
def Dijkstra(g:list,n:int,start:int) -> list:
    dist = [INF]*n
    p = [0]*n
    dist[start] = 0
    q = []
    heappush(q,(0,start))
    while (len(q)):
        v = q[0][1]
        cur_d = -q[0][0]
        heappop(q)
        if (cur_d > dist[v]):
            continue;
        for j in range(len(g[v])):
            to = g[v][j][0]
            length = g[v][j][1]
            if (dist[v] + length < dist[to]):
                dist[to] = dist[v] + length
                p[to] = v
                heappush(q,(-dist[to],to))
    return dist;

'''
-g - массив со списками смежностей.
 n - количество вершин.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей.
 Если в i-ом массиве есть элемент (j,w), значит из i можно попасть в j за цену w.
-Функция Dijkstra возвращает массив с кратчайшими длинами от start до каждой, 
 причем если пути нету то на месте длины пути будет константа INF.
-Нумерация с 0.
(Алгоритм Дейкстры)

'''