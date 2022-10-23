INF = 10**9
def _FU(a:list,n:int) -> None:
    for k in range(n):
        for i in range(n):
            for j in range(n):
                a[i][j] = a[i][j] if (a[i][j]<(a[i][k]+a[k][j])) else a[i][k]+a[k][j]

def solve(g:list,n:int) -> None:
    _FU(g,n)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if (g[k][j] < INF and g[j][j] < 0 and g[j][i] < INF):
                    g[k][i] = -INF

'''
-g - матрица смежностей.
 n - количество вершин.
-Граф хранить в виде матрицы смежности.
 g[i][j]-ый элемент означает -> из i в j за цену g[i][j], 
 цена равная INF означает, что нет пути из i в j.
-Функция solve делает из матрицы следующую вещь - если g[i][j] == -INF, значит путь из i в j бесконечно мал,
 иначе g[i][j] является кратчайшим путем из i в j.
-Нумерация с 0.
(Алгоритм Флойда - Уоршелла)
'''