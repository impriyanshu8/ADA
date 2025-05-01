Analysis and Design of Algorithms
Index
1. Quicksort
Sorts an array using a pivot element.

Elements left of the pivot are smaller; elements right are larger.

The pivot is placed at its correct position as in the fully sorted array.

Uses recursion to sort the left and right sub-arrays.

2. Iterative Quicksort
Non-recursive implementation of Quicksort.

Reduces stack usage by manually maintaining a stack for subarray indices.

3. Peak Finding Algorithms (1D & 2D)
🔹 1D Peak Finding:
Finds an element greater than or equal to its neighbors.

Implemented using a binary search-based approach.

🔹 2D Peak Finding:
Similar binary search idea applied in 2D.

Efficiently locates a peak in a matrix.

4. Magic Square (Odd Size)
Constructs a square matrix where the sum of each row, column, and diagonal is equal.

Follows a specific pattern: numbers are placed diagonally upward-left; if blocked, go down one row.

5. Cosine Similarity
Measures similarity between two text documents.

Each document is treated as a word-frequency vector.

Cosine of the angle between these vectors indicates similarity.

6. Fractional Knapsack
Maximizes profit by selecting items with fractional parts allowed.

Items are sorted by profit, weight, and profit-to-weight ratio.

Greedily selects items in descending order of value.

7. Job Scheduling
Schedule jobs to maximize the number completed.

Uses strategies like FCFS (First-Come, First-Serve), SJF (Shortest Job First), and sorting by finish time.

SJF has higher time complexity due to job availability checks.

8. Matrix Multiplication
🔹 Conventional Method:
Uses the standard divide and conquer approach to multiply matrices.

🔹 Strassen’s Algorithm:
Improves on the naive O(n³) method.

Reduces complexity to approximately O(n^2.81) using matrix partitioning.

9. Convex Hull (Polygon Hull)
🔹 QuickHull:
Divide-and-conquer approach similar to Quicksort.

Divides the point set into triangles and recursively finds the convex hull.

Involves checking which points lie inside or outside triangles.

10. Kruskal’s Algorithm
Greedy algorithm for finding Minimum Spanning Tree (MST).

Sorts edges by weight and adds them, avoiding cycles via Union-Find.

Time Complexity:
Sorting edges: O(E log E)
Union-Find: O(E log V)
Overall: O(E log V)

11. Prim’s Algorithm
Greedy MST algorithm.

Starts with a vertex and adds the smallest connecting edge.

Uses a priority queue for optimization.

Time Complexity:

Adjacency matrix: O(V²)

Priority queue (heap): O(E log V) for sparse graphs

12. Dijkstra’s Algorithm
Finds the shortest path from a single source to all nodes in a weighted graph.

Time Complexity:

Adjacency matrix: O(V²)

Priority queue: O((V + E) log V)

13. All Pairs Shortest Path
Finds shortest paths between all node pairs.

Supports negative weights (Floyd-Warshall, Johnson’s Algorithm).

Works with both directed and undirected graphs.

14. Multistage Graph Algorithm
Solves shortest path problems in layered graphs.

Useful for staged decision-making like scheduling or routing.

Uses dynamic programming to compute optimal paths through stages.

15. Longest Common Subsequence (LCS)
Finds the longest sequence common to two sequences (not necessarily contiguous).

Uses dynamic programming to build LCS length and recover the sequence.

16. N-Queens Problem
Place N queens on an N×N chessboard such that:

No two queens share a row, column, or diagonal.

Solved using backtracking by placing queens row by row and backtracking on conflicts.

17. M-Coloring Problem
Color a graph’s vertices using at most M colors so that no two adjacent vertices share a color.

Solved using backtracking:

Try assigning each color from 1 to M.

Check if it’s safe before assigning.

If unsafe, backtrack.

18. Hamiltonian Cycle
A cycle that visits every vertex exactly once and returns to the start.

Solved via backtracking:

Start at a vertex and recursively build the cycle.

Ensure the current vertex is connected and unvisited.

Check if the last vertex connects to the start.

19. Sum of Subsets
Find all subsets of a set whose sum equals a target value.

Solved using backtracking:

Include or exclude each element.

Track the current sum.

Record valid subsets.

Prune paths where sum exceeds the target.

