from random import randint

def _keyW(t:tuple) -> int:
    return t[2];

def _dsu_get(v:int,p:list) -> int:
    if (v == p[v]):
        return v;
    else:
        p[v] = _dsu_get(p[v],p)
        return p[v];

def _dsu_unite(a:int, b:int, p:list) -> None:
    a = _dsu_get(a,p)
    b = _dsu_get(b,p)
    if (randint(0,32767)&1):
        a,b = b,a
    if (a!=b):
        p[a] = b
        
def MST(g:list, n:int, m:int) -> list:
    res = []
    cost = 0
    g.sort(key = _keyW)
    p = list(range(n))
    for u,v,w in g:
        if (_dsu_get(u,p) != _dsu_get(v,p)):
            cost += w
            res.append((u,v,w))
            _dsu_unite(u,v,p)
    return res;


'''
-g - массив ребер.
 n - количество вершин.
 m - количество ребер.
-Граф хранить в виде списка ребер, алгоритм работает для НЕОРИЕНТИРОВАННОГО графа.
 Элемент в массиве g вида (i,j,w) означает, что можно попасть из i в j за цену w.
-Функция MST возвращает граф в виде списка ребер являющийся Минимальным Остовным Деревом.
-Нумерация с 0;
(Алгоритм Краскала с системой непересекающихся множеств)
'''