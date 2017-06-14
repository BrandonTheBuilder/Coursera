import math

def karatsuba_multiply(x,y):
    try:
        x = str(x)
        y = str(y)
        if(len(x) > len(y)):
            nx = len(x)
            ny = len(y)
            dn = nx - ny
            y = '0'*dn + str(y)
        elif(len(y) > len(x)):
            nx = len(x)
            ny = len(y)
            dn = ny - nx
            x = '0'*dn + str(x)
        n = len(x)
        if (n ==1):
            return int(x) * int(y)
        m = n/2 + n%2
        a = x[:n-m]
        b = x[n-m:]
        c = y[:n-m]
        d = y[n-m:]
        ac = karatsuba_multiply(a,c)
        bd = karatsuba_multiply(b,d)
        ad_bc = karatsuba_multiply(str_add(a,b),str_add(c,d)) - int(bd) - int(ac)
        ans = int(10**(2*m)) * int(ac) + int(10**m) * ad_bc + int(bd)
        if(x == 'A31415926535897932384626433832795'):
            import IPython; IPython.embed()
    except Exception as e:
        import IPython; IPython.embed()
    return ans

def str_add(a,b):
    return int(a) + int(b)

def test_karatsuba(a, b):
    ans = karatsuba_multiply(a,b)
    print ans
    print a * b
    print ans == a*b

def run_tests():
    test_karatsuba(1,1)
    test_karatsuba(12,21)
    test_karatsuba(0,7)
    test_karatsuba(12345,6789)
    test_karatsuba(12,123)
    test_karatsuba(12345678, 87654321)
    test_karatsuba(123456, 654321)
    test_karatsuba(9876543210, 123)
    test_karatsuba(5678, 1234)
    test_karatsuba(999,999)
    test_karatsuba(9999,9999)
    test_karatsuba(5,0)
    test_karatsuba(25,05)
    test_karatsuba(3141592653589793, 2718281828459045)
    test_karatsuba(31415926535897932384626433832795, 27182818284590452353602874713526)

if __name__ == "__main__":
    # stest_karatsuba()
    one = 3141592653589793238462643383279502884197169399375105820974944592
    two = 2718281828459045235360287471352662497757247093699959574966967627
    #run_tests()
    test_karatsuba(3141592653589793, 2718281828459045)
    test_karatsuba(one,two)
