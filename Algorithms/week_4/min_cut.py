import math
import random
import copy
# The random contraction algorithm chooses random nodes in the graph to combine
# and then removes all self references to the nodes. The final number of vertices
# between the two nodes is refered to as the minimum cut. min_cut uses the random 
# contraction algorithm which has a low probabability of sucess a number of times
# dependant on the size of the graph which provides a high expected value of 
# returning the correct solution. 
def min_cut(graph):
    mins = []
    for x in range(1,100):
        # get a copy of the graph to use in this iteration
        g = copy.deepcopy(graph)
        # import IPython; IPython.embed()
        # iterate until only two super nodes remain
        while len(g) > 2:
            # shuffle the graph in order to select a random node
            random.shuffle(g)
            # remove the node from the graph
            n = g.pop()
            # get a list of indices of nodes in the graph that are with vertices 
            # to the chosen node
            nodes = [i for i in range(len(g)) if g[i][0][0] in n]
            # select a random vertice
            i = random.randint(0,len(nodes)-1)
            # get the node on the head of the vertex
            node = g[nodes[i]]
            # remove that node from the graph
            g.remove(node)
            # get the node out of the adjaceny list
            #  and attach it to the list of nodes in the super node
            node.reverse()
            n[0].extend(node.pop())
            # build a list of nodes that vertices would make a self reference to
            # in the super node
            exclude = copy.deepcopy(n[0])
            exclude.extend(n[1:])
            # extend the super nodes vertices with the vertices that would not 
            # cause self references
            n.extend([x for x in node if x not in exclude])
            # reattach the super node to the graph
            g.append(n)
        # remove any self references from the original list of vertices  
        for item in g:
            to_remove = []
            for val in item[1:]:
                if val in item[0]:
                    to_remove.append(val)
            for i in to_remove:
                item.remove(i)
        print g
        print '\n'
        result = g[0][1:]
        result.extend(g[1][1:])
        # count the number of vertices and add it to the list of found min_cuts
        minimum = len(result)
        mins.append(minimum)       
    # return the lowest min_cut found
    print(min(mins))
    return min(mins)

def test_min_cut():
    g = [[[1], 2, 5, 2, 4],[[2], 1, 1, 4, 3, 5, 3],[[3], 2, 2, 5, 5, 4, 5, 5],[[4], 2, 3, 1],[[5], 1, 2, 3, 3, 3, 3]]
    expected = 3
    cut = min_cut(g)
    print expected == cut

def main():
    test_min_cut()


if __name__ == '__main__':
    main()