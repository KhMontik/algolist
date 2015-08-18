#include<iostream>
#include<math.h>
#define e 1e-10
using namespace std;
int main()
{
freopen("postcard.in","r",stdin);
freopen("postcard.out","w",stdout);
double ho,hk,wo,wk,cab,caf,bae,fc,ac,ge;
cin>>ho>>wo>>hk>>wk;
if(hk>wk)
{
swap(hk,wk);
}
if(ho>wo)
{
swap(ho,wo);
}
if(ho>hk)
{
cout<<"Impossible";
return 0;
}
if(ho<=hk && wo<=wk)
{
cout<<"Possible";
return 0;
}
ac=sqrt(pow(ho,2)+pow(wo,2));
fc=sqrt(pow(ac,2)-pow(hk,2));
cab=atan2(ho,wo);
caf=atan2(fc,hk);
bae=M_PI/2-(cab+caf);
ge=ho*sin(bae)+wo*cos(bae);
if(ge<=wk+e)
{
cout<<"Possible";
}
else
{
cout<<"Impossible";
}
return 0;
}