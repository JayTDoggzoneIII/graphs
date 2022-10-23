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

def FB(e:list,n:int,m:int,start:int) -> list:
    d = [INF]*n
    d[start] = 0
    p = [-1]*n
    for i in range(n):
        x = -1
        for j in range(m):
            if (d[e[j][1]] > d[e[j][0]] + e[j][2]):
                d[e[j][1]] = -INF if (-INF > d[e[j][0]] + e[j][2]) else d[e[j][0]] + e[j][2]
                p[e[j][1]] = e[j][0]
                x = e[j][1]
    if (x == -1):
        return d;
    else:
        return [];
 
def new_graph(g:list, n:int) -> tuple:
    [*_g]= g
    for u,v,w in g:
        _g.append((n,u,0))
    return _g;
 
def Johnson(g:list,n:int,m:int) -> list:
    _g = new_graph(g,n)
    b1 = FB(_g,n+1,len(_g),n)
    if (not len(b1)):
        return [[]];
    mas1 = [[0]*(n) for i in range(n)]
    mas2 = [[] for i in range(n)]
    for u,v,w in g:
        mas1[u][v] = w+b1[u]-b1[v]
    for u,v,w in g:
        mas2[u].append((v,mas1[u][v]))
    for i in range(n):
        b2 = Dijkstra(mas2,n,i)
        for j in range(n):
            mas1[i][j] = b2[j] + b1[j]-b1[i]
    return mas1;

'''
-g - массив ребер.
 n - количество вершин.
 m - количество ребер.
-Граф хранить в виде списка ребер.
 Элемент в массиве g вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция Johnson возвращает матрицу с кратчайшими длинами от каждой до каждой, 
 причем если пути нету то на месте длины пути будет константа INF, а если есть
 путь бесконечно малого веса, возвращает пустую матрицу.
-Нумерация с 0;
(Алгоритм Джонсона)
'''