#include <iostream>

using namespace std;

bool check(int a, int b){

  if (b>a)  return true;
  return false;

}


int main(){

 freopen("input.txt","r",stdin);

 freopen("output.txt","w",stdout);

 int n, mas[100000], a[100000], d[100000];

 cin >> n;

 for (int i=0; i<n; i++)
 cin >> mas[i];


 for (int i=0; i<n; i++) a[i]=0;
 a[0]=1;


 for (int i=0; i<n; i++){

   a[i]=1;
   for (int j=0; j<i; j++){
      if (mas[j]< mas[i]){ //check
       a[i] = max(a[j] + 1, a[i]);
       }

   }

 }

 int res=-1;

 for (int i=0; i<n; i++)  if (res< a[i]) res = a[i];
 cout<<res<<endl;
 
 return 0;
}
