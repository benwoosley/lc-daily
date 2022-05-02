import math


class Graph:
    def __init__(self, vertex):
        self.V = vertex
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    def search(self, parent, i):
        if parent[i] == i:
            return i
        return self.search(parent, parent[i])

    def apply_union(self, parent, rank, x, y):
        xroot = self.search(parent, x)
        yroot = self.search(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def kruskal(self, size):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < size:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.search(parent, u)
            y = self.search(parent, v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.apply_union(parent, rank, x, y)
        distance = 0
        for u, v, weight in result:
            distance += weight
        print(distance)


def dist(x1, x2, y1, y2):
    return math.sqrt(((x1-x2)**2) + ((y1-y2)**2))


def main():
    n, e, p = [int(x) for x in input().split()]
    trees = {}
    g = Graph(1000)
    for i in range(0, n):
        trees[i] = []
        for x in input().split():
            trees[i].append(float(x))
        for j in range(0, len(trees)-1):
            if i > e-1:
                g.add_edge(
                    i, j, dist(trees[i][0], trees[j][0], trees[i][1], trees[j][1]))
            else:
                g.add_edge(i, j, 0)

    for i in range(0, p):
        num1, num2 = [int(x)-1 for x in input().split()]
        g.add_edge(num1, num2, 0)
    g.kruskal(len(trees)-1)


if __name__ == "__main__":
    main()
