from collections import deque
INF = -1
def bfs(a:list,n:int,start:int) -> list:
    q = deque([start])
    dist = [INF]*(n)
    dist[start] = 0
    while (len(q)):
        u = q.popleft()
        for v in a[u]:
            if (dist[v] == INF):
                dist[v] = dist[u]+1
                q.append(v)             
    return dist;

'''
-a - массив со списками смежностей.
 n - количество вершин.
 start - вершина для которой запускается алгоритм.
-Граф хранить в виде списков смежностей, граф должен быть НЕвзвешенным.
 Если в i-ом массиве есть элемент j, значит из i можно попасть в j.
-Функция bfs возвращает массив с кратчайшими длинами от start до каждой, 
 причем если пути нету то на месте длины пути будет константа INF.
-Нумерация с 0.
'''