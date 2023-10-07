from collections import defaultdict




def preprocess(book, adj, root, par):
    if len(adj[root]) == 1 and adj[root][0] == par:
        book[root] = 1
        return
    
    for child in adj[root]:
        if child != par:
            preprocess(book, adj, child, root)
            book[root] += book[child]



def solve():
    n = int(input())
    adj = defaultdict(lambda: [])
    book = defaultdict(int)
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    preprocess(book, adj, 1, 0)
    q = int(input())
    for _ in range(q):
        x, y = map(int, input().split())
        print(book[x] * book[y])

t = int(input())
for _ in range(t):
    solve()

"""
 1 3
 |
 2 3 - 6 1
 |
 3 2
 /\
 4 5
 1 1

"""