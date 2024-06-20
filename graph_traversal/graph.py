# The graph data structure is an array of lists
type Graph = list[list[int]]

def build_graph(n : int, preq : list[tuple]) -> Graph:
    '''
    Build a list of nodes where each node holds a list of it's dependencies
    '''
    nodes : Graph = [[] for num in range(n)]

    for pre in preq:
        actual_course = pre[1]
        preq_course = pre[0]

        course_node = nodes[actual_course]
        course_node.append(preq_course)
    
    # print(n, '->', preq, '->', nodes)
    return nodes
