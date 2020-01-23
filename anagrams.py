def giveSign(s, i, j):
    return (s[i:j+1].count("a"),s[i:j+1].count("b"),s[i:j+1].count("c"),s[i:j+1].count("d"),s[i:j+1].count("e"),s[i:j+1].count("f"),s[i:j+1].count("g"),s[i:j+1].count("h"),s[i:j+1].count("i"),s[i:j+1].count("j"),s[i:j+1].count("k"),s[i:j+1].count("l"),s[i:j+1].count("m"),s[i:j+1].count("n"),s[i:j+1].count("o"),s[i:j+1].count("p"),s[i:j+1].count("q"), s[i:j+1].count("r"),s[i:j+1].count("s"),s[i:j+1].count("t"),s[i:j+1].count("u"),s[i:j+1].count("v"),s[i:j+1].count("w"),s[i:j+1].count("x"),s[i:j+1].count("y"),s[i:j+1].count("z"))
    
for _ in range(int(input())):
    map = dict()
    s = input()
    for i in range(len(s)):
        for j in range(i,len(s)):
            #print(i,j)
            sign = giveSign(s,i,j)
            if map.get(sign) == None:
                map[sign] = 1
            else:
                map[sign] += 1
    ans = 0
    #print(map)
    for key in map:
        n = map[key]
        ans += n*(n-1)//2
    print(ans) 