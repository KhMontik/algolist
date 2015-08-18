#include <cstdio>

int n,i;
__int64 x1,y1,x0,y0,x2,y2;
__int64 ans,S,K;

int abs(int a)
{
    if (a<0) return -a;
    return a;
}

__int64 fabs(__int64 a)
{    if (a<0) return -a;
    return a;
}
__int64 vect(__int64 x1,__int64 y1,__int64 x2,__int64 y2)
{
    return x1*y2-x2*y1;
}

__int64 Nod(__int64 a,__int64 b)
{
    while (a&&b)
    {
        if (a>b) a%=b; else
        b%=a;
    }
    return a+b;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);

    scanf("%I64d %I64d",&x1,&y1);
    x0=x1;
    y0=y1;
    for (i=2;i<=n;i++){
        scanf("%I64d %I64d",&x2,&y2);
            S+=vect(x1,y1,x2,y2);
            K+=Nod(abs(x2-x1),abs(y2-y1));
        x1=x2;
        y1=y2;
    }
    x2=x0;
    y2=y0;
        S+=(vect(x1,y1,x2,y2));
         K+=Nod(abs(x2-x1),abs(y2-y1));

    S=fabs(S)/2;
    K=K/2;
    ans=S-K+1;
    printf("%I64d",ans);

}