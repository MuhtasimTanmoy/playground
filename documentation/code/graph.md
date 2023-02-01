- Graph Representation
    - Adjacency List
    - Matrix
    - Edge List

# Graph
- If a graph with `n` node has no cycle, it must have `n-1` edges.

### DFS
- In DFS each edge visited twice
- Edge : N - 1

### BFS
- In DFS each edge visited once
- Shortest Path
    - Bellman Ford 
        - Go for edge
        - No cycle with negative edge, if present it can detect
        - Algo provided for `Edge List Graph Representation`, relaxing `n-1` times
        - Negative cycle can be detected by relaxing n times
        - For all vertices, for add edges, relax
    - Dijkstra
        - go for graph
        - Negative egdes weight wont work
        - Algo provided for `Adjacency List Graph Representation`
        - Priority queue used
        - Like BFS
    - Floyed Warshall
        - `Matrix Graph Representation`
        - `O(n^3)`
        - Dont use infinity as weight max, Use a biggger number instead
    - a*
    - BFS no weight

- Single source shortest path
    - Topologically sort and process relax [https://github.com/williamfiset/algorithms](https://github.com/williamfiset/algorithms)

- Good Problem
    - https://leetcode.com/problems/cheapest-flights-within-k-stops/solution

- Longest path on graph
    - Just multiply `-1` to all edge values

- Tree
    - n nodes, `n - 1` edges

- [Disjoint Set](https://leetcode.com/explore/featured/card/graph/618/disjoint-set)
    - Union Find
        - `quick find` vs `quick union`
        - In `quick find` the parent is root node, in `quick union` the parent node is parent node
        - `quick union` based optimization rank based, the taller tree gets to be the root
        - Path compression to optimize quick find
    - Problem
        - Naive approach to assign parent would need relaxing

- [Graph Algorithm](https://youtu.be/tWVWeAqZ0WU)
    - DAG
    - Bi-Paratite
    - Complete Graph

- Negative Cycle
- Strongly Connected Component

tsp
help karp
branch bound

bridge/ cut edge
articulation point/ cut vertex

MST Prim Kruskal
Network flow
Ford Fulkerson
Edmond Carp
Dinic

- Topological Sort
    - Cant have cycle
    - Only directed acyclic graph
    - How to detect cycle?
        - Tarjan's strongly connected component
        - Every tree has topological ordering
        - Just keep picking from below


 
## Lazy Dijkstra single source shortest path
- Searching for a elem in priority queue takes linear time `(e+V)logV`
- Indexed priority queue
    - Does the searching in `O(1)`
- thereby decrease key is supported

D ary heap
D = E / V
O( E * log (D) V)

Fibonacci Heap
    - Dont use unless very large graph

`O(E + VlogV)`

RMQ
Sparse
Square root decomposition

recursive descent parser or with the shunting-yard algorithm
rope
set unordered_set multiset unordered multiset

All pair shortest path 
Negative cycle detect in diagonal
Negative edge possible

Path Reconstruction 
    -  `dist[i][j] > dist[i][k] + dist[k][j]`

- Dijkstra vs Prim
    - Dijkstra source to all node shortest path greedy
    - No negative edge if neg then bellman
    - In Dijkstra full path value is minimized 
    - In prim only the cut is minimized
    - A cut is the connecting point between two distinct set

`Dijkstra's Algorithm` at every step greedily selects the next edge that is closest to some source vertex s. It does this until s is connected to every other vertex in the graph. Clearly, the predecessor subgraph that is produced is a spanning tree of G, but is the sum of edge weights minimized?

`Prim's Algorithm`, which is known to produce a minimum spanning tree, is highly similar to Dijkstra's Algorithm, but at each stage it greedily selects the next edge that is closest to any vertex currently in the working MST at that stage. Let's use this observation to produce a counterexample.

- Kruskal
- Splay Tree

Floyds cycle detection

- `BST` mode find
    - Get inorder traverse to get all elements
    - get max of those
    - get elements with those max val

- [Graph](https://www.youtube.com/watch?v=iKCnz0k4C5c&list=PLWtSipmftM8qbtfj2WkoQ7Z9ZrhCl6rPz)
    - DFS
    - Graph Walking

- [Flow and Matching](https://youtu.be/EOl4BzGozBs?list=PLWtSipmftM8qbtfj2WkoQ7Z9ZrhCl6rPz)
    - Elmond Karp
        - Vertex * Edge ^ 2
    - Dinik
        - Vertex ^ 2 * Edge

### Disjoint Set
- `Union Find` to detect cycle in undirected graph
- Detect if two node connected

### Dijkstra vs BFS

```c++
dijsktra(s):
dist[s] = 0;
while (some vertices are unmarked) {
    v = unmarked vertex with 
    smallest dist;
    Mark v; // v leaves “table”
    for (each w adj to v) 
        dist[w] = min[ dist[w], dist[v] + c(v,w) ];
}
// v = unmarked vertex with 
//     smallest dist to intermediate;
```

- Breadth-first search is just Dijkstra's algorithm with all edge weights equal to 1.
- In bfs there is repeateation, also queue has same elements
- Dijkstra's algorithm is conceptually `breadth-first search` that respects edge costs.
- The process for exploring the graph is structurally the same in both cases.
- Dijkstra's uses a priority queue data structure to keep track of the frontier of un visited nodes. Breadth-first search uses a regular queue data structure. Operations on a priority queue are O(log n). Operations on a regular queue are O(1). The use of a regular queue in BFS is made possible by all edge weights being 1 which makes the regular queue effectively behave as a priority queue.

[Resource](https://stackoverflow.com/questions/25449781/what-is-difference-between-bfs-and-dijkstras-algorithms-when-looking-for-shorte)

## Morris Inorder Traversal
- Space complexity reduced



- Trie
- Hash
    - Open addressing
    - Quadratic addressing
    - Linear probing
    - Double hashing
    - Chaining