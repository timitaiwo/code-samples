from graph import build_graph, Graph
from graph_traversal import dfs, bfs

if __name__ == "__main__":
    
    number_nodes : int = 5
    preq : list[int] = [(2,0), (0,3), (2, 1), (1, 4), (4, 3)]
    graph : Graph = build_graph(number_nodes, preq)
    start_index = 4

    print(number_nodes, '->', preq, '->', graph)

    print(f"\nCheck if every node can be reached from {start_index}")
    
    print("\nUsing DFS: ")
    DFS : bool = dfs(graph, number_nodes, start_index)
    print(f"All nodes reached? {DFS}")


    print("\nUsing BFS: ")
    print(bfs(graph, number_nodes, start_index))




