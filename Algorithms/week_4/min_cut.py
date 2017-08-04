import math
import random
import copy

def min_cut(graph):
    mins = []
    for x in range(1,100):
        g = copy.deepcopy(graph)
        # import IPython; IPython.embed()
        while len(g) > 2:
            random.shuffle(g)
            n = g.pop()
            nodes = [i for i in range(len(g)) if g[i][0][0] in n]
            i = random.randint(0,len(nodes)-1)
            node = g[nodes[i]]
            g.remove(node)
            node.reverse()
            n[0].extend(node.pop())
            exclude = copy.deepcopy(n[0])
            exclude.extend(n[1:])
            n.extend([x for x in node if x not in exclude])
            g.append(n)
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
        minimum = len(result)
        mins.append(minimum)       
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