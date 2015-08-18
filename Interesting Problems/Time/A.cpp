#include <iostream>

using namespace std;

int main()
{
 freopen ("input.txt", "r", stdin);
 freopen ("output.txt", "w", stdout);

 long long a=0, h1, h2, m1, m2, res=0;

 cin >> h1 >> m1;
 cin >> h2 >> m2;
 while (h1 != h2 || m1 != m2) 
 {
  m1++; 			
   if (m1 == 60)
   {
    h1++; 
    h1 = h1 % 24;
    m1 = 0;
     if (h1%12 == 0)
     {
      res+=12; 
     }
      else res+=(h1 % 12);
   }
   if (m1 == 30) 
       { 
        a++;
       }
 }
     
   cout << res+a;


 return 0;
}
