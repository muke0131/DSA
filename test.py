T=int(input())
for i in range(T):
    L,N=map(int,input().split())
    count=0;
    for i in range(N):
        D,C=input().split();
        d=int(D);
        if(C=='c'):
            d+=(L-int(D));
            if(d>=L):
                count+=1;
        else:
            d-=(L-int(D));
    print(count)          