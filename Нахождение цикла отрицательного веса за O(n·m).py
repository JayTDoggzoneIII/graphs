INF = 10**9
def solve(e:list,n:int,m:int) -> list:
    d = [0]*n
    p = [-1]*n
    for i in range(n):
        x = -1
        for j in range(m):
            if (d[e[j][1]] > d[e[j][0]] + e[j][2]):
                d[e[j][1]] = -INF if (-INF > d[e[j][0]] + e[j][2]) else d[e[j][0]] + e[j][2]
                p[e[j][1]] = e[j][0]
                x = e[j][1]
    if (x == -1):
        return [];
    else:
        y = x
        for i in range(n):
            y = p[y]
        path = []
        cur = y
        while (True):
            path.append(cur)
            if (cur == y and len(path) > 1):
                break;
            cur = p[cur]
        path.reverse()
        return path;

'''
-e - массив ребер.
 n - количество вершин.
 m - количество ребер.
-Граф хранить в виде списка ребер.
 Элемент в массиве edges вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция solve возвращает массив, который является циклом отрицательного веса если он есть, 
 иначе пустой массив.
-Нумерация с 0.
(Алгоритм Форда - Беллмана)
'''
