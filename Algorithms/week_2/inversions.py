def count_inversions(input_array):
    n = len(input_array)
    if n == 1:
        return 0

    m = n/2 + n%2
    a = input_array[:m]
    b = input_array[m:]

    x = count_inversions(a)
    y = count_inversions(b)
    print "n = {}".format(n)
    print "input {}".format(input_array)
    print "Found {} invs in {}, and {} invs in {}".format(x,a,y,b)
    z = count_split_inversions(a,b)
    print "With {} split inversions".format(z)
    return x + y + z

def count_split_inversions(a,b):
    a.reverse()
    b.reverse()
    i = len(a)
    j = len(b)
    # print "a: {} b: {}".format(a,b)
    x = a.pop()
    y = b.pop()
    inversions = 0
    while(i>0):
        # print "in the loop a: {} b: {}".format(a,b)
        # print "a has length {} and b has length {}".format(len(a), len(b))
        # print "x = {}, y={}".format(x,y)
        if x > y:
            # print "x: " + str(x) + " y: " + str(y) + " inversions found: " + str(len(a) + 1)
            inversions += i
            # print "Adding {} inversions".format(i)
            if len(b) == 0:
                break;
            y = b.pop()
            j -= 1
        elif y > x:
            # print "x: " + str(x) + " y: " + str(y) + " No Inversions found"
            if len(a) == 0:
                break
            x = a.pop()
            i -= 1

    # print "Found {} split inversions".format(inversions)
    return inversions


def test_count_inversions():
    a = [1, 3, 5, 2, 4, 6]
    a_ans = 3
    print a
    print a_ans == count_inversions(a)
    b = [1, 20, 6, 4, 5]
    b_ans = 5
    print b
    print b_ans == count_inversions(b)
    c = [5, 2, 10, 8, 1, 9, 4, 3, 6, 7]
    c_ans = 22
    print c
    print c_ans == count_inversions(c)
    d = [3, 1, 6, 5, 2, 4]
    d_ans = 7
    print d
    print d_ans == count_inversions(d)


def test_specific():
    # d = [3, 1, 6, 5, 2, 4]
    d = [5, 2, 10, 8, 1, 9, 4, 3, 6, 7]
    d = [9,]
    # d_ans = 7
    d_ans = 22
    print(count_inversions(d))
    # print d
    # print d_ans == count_inversions(d)

def test_count_split_inversions():
    a = [9, 4, 3]
    b = [6, 7]
    invs = count_split_inversions(a,b)
    print invs

if __name__ == '__main__':
    # test_count_split_inversions()
    # test_count_inversions()
    test_specific()
