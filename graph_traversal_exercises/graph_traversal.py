from graph import Graph

def dfs(graph: Graph, number_nodes : int, start_index : int, visited = list()):
    '''
    - Recursively go through the graph using dfs
    - Print the value of each node
    - Check if every node can be reached from that point 
    '''

    # Include checks to see if start_index is valid
    if number_nodes < 0 or start_index >= number_nodes:
        return False

    if start_index not in visited:
        visited.append(start_index)

    print(visited)

    for node_index in range(start_index, start_index+number_nodes):
        node_index = node_index % number_nodes 

        if node_index not in visited:
            dfs(graph, number_nodes, node_index, visited)
    
    return True if len(visited) == number_nodes else False


def bfs(graph: Graph, number_nodes : int, start_index : int, visited = set()):
    '''
    - Recursively go through the graph using bfs
    - Print the value of each node
    - Check if every node can be reached from that point 
    '''

    # Include checks to see if start_index is valid

    return True if len(visited) == number_nodes else False

