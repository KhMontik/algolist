#include <iostream>

using namespace std;

int main()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);

 int t=4, i, j, a[17], w[27], s=0, k[12], q[50];

 for (i=0; i<=48; i++)q[i]=11;
 for (i=0; i<12; i++)
 {
  cin >> a[i];
  w[i]=a[i]; 
  s+=a[i];
  k[i]=0;
 }
      
  int s1=0;




            

 for (i=0; i<11; i++)
 {
  for (j=i+1; j<12; j++)if (w[i]>w[j]) swap (w[i],w[j]);
 }

     
        int Q=15; 
 for (int o=0; o<12; o++)
 {
  for (int p=0; p<12; p++)
  {              
   // if (Q==w[o])p++;
    if (w[o]==a[p] && p!=Q)
   {
         Q=p;
        if (p==0)
        {
         for (int u=4; u<15; u++)if (q[u]==11)q[u]=a[p];
        }
        if (p==1)
        {
         for (int u=15; u<24; u++)if (q[u]==11)q[u]=a[p];
        }
        if (p==2)
        {
         for (int u=24; u<33; u++)if (q[u]==11)q[u]=a[p];
        }
        if (p==3)
        {
         for (int u=33; u<44; u++)if (q[u]==11)q[u]=a[p];
        }
        if (p==4)
        {
         if (q[33]==11)q[33]=a[p];
         if (q[34]==11)q[34]=a[p];
         if (q[24]==11)q[24]=a[p];
         if (q[25]==11)q[25]=a[p];
         if (q[16]==11)q[16]=a[p];
         if (q[17]==11)q[17]=a[p];
         if (q[7]==11)q[7]=a[p];
         if (q[8]==11)q[8]=a[p];
         if (q[1]==11)q[1]=a[p];
         if (q[2]==11)q[2]=a[p];
         if (q[0]==11)q[0]=a[p];
        }
        if (p==5)
        {
         if (q[36]==11)q[36]=a[p];
         if (q[35]==11)q[35]=a[p];
         if (q[26]==11)q[26]=a[p];
         if (q[27]==11)q[27]=a[p];
         if (q[18]==11)q[18]=a[p];
         if (q[19]==11)q[19]=a[p];
         if (q[10]==11)q[10]=a[p];
         if (q[9]==11)q[9]=a[p];
         if (q[3]==11)q[3]=a[p];
        }
        if (p==6)
        {
         if (q[44]==11)q[44]=a[p];
         if (q[37]==11)q[37]=a[p];
         if (q[38]==11)q[38]=a[p];
         if (q[28]==11)q[28]=a[p];
         if (q[29]==11)q[29]=a[p];
         if (q[20]==11)q[20]=a[p];
         if (q[21]==11)q[21]=a[p];
         if (q[11]==11)q[11]=a[p];
         if (q[12]==11)q[12]=a[p];
        }
        if (p==7)
        {
         if (q[47]==11)q[47]=a[p];
         if (q[46]==11)q[46]=a[p];
         if (q[45]==11)q[45]=a[p];
         if (q[39]==11)q[39]=a[p];
         if (q[40]==11)q[40]=a[p];
         if (q[30]==11)q[30]=a[p];
         if (q[31]==11)q[31]=a[p];
         if (q[22]==11)q[22]=a[p];
         if (q[23]==11)q[23]=a[p];
         if (q[13]==11)q[13]=a[p];
         if (q[14]==11)q[14]=a[p];
        }
        if (p==8)
        {
         if (q[47]==11)q[47]=a[p];
         if (q[45]==11)q[45]=a[p];
         if (q[44]==11)q[44]=a[p];
         if (q[37]==11)q[37]=a[p];
         if (q[36]==11)q[36]=a[p];
         if (q[26]==11)q[26]=a[p];
         if (q[25]==11)q[25]=a[p];
         if (q[16]==11)q[16]=a[p];
         if (q[15]==11)q[15]=a[p];
         if (q[5]==11)q[5]=a[p];
         if (q[4]==11)q[4]=a[p];
        }
        if (p==9)
        {
         if (q[46]==11)q[46]=a[p];
         if (q[39]==11)q[39]=a[p];
         if (q[38]==11)q[38]=a[p];
         if (q[28]==11)q[28]=a[p];
         if (q[27]==11)q[27]=a[p];
         if (q[18]==11)q[18]=a[p];
         if (q[17]==11)q[17]=a[p];
         if (q[7]==11)q[7]=a[p];
         if (q[6]==11)q[6]=a[p];
        }
        if (p==10)
        {
         if (q[41]==11)q[41]=a[p];
         if (q[40]==11)q[40]=a[p];
         if (q[30]==11)q[30]=a[p];
         if (q[29]==11)q[29]=a[p];
         if (q[20]==11)q[20]=a[p];
         if (q[19]==11)q[19]=a[p];
         if (q[9]==11)q[9]=a[p];
         if (q[8]==11)q[8]=a[p];
         if (q[1]==11)q[1]=a[p];
        }
        if (p==11)
        {
         if (q[43]==11)q[43]=a[p];
         if (q[42]==11)q[42]=a[p];
         if (q[32]==11)q[32]=a[p];
         if (q[31]==11)q[31]=a[p];
         if (q[22]==11)q[22]=a[p];
         if (q[21]==11)q[21]=a[p];
         if (q[11]==11)q[11]=a[p];
         if (q[10]==11)q[10]=a[p];
         if (q[3]==11)q[3]=a[p];
         if (q[2]==11)q[2]=a[p];
         if (q[0]==11)q[0]=a[p];
        }
   }
  }
 }  
       
for (int i=0; i<48; i++) s1+=q[i];
 for (i=0; i<8; i++)
 {
  for (j=(i/4+1)*4; j<12; j++)
  {
   if (a[i]==a[j])
   {
    a[j]=-1;
    k[a[i]]++;
   }
  }
 }

 for (i=0; i<12; i++)
 {
  s-=(i*k[i]);
 }
 cout << s << " " << s1;
 s=0;


         
 return 0;
}
