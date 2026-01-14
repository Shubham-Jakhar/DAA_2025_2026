#include<iostream>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int dep =0;
void complexRec(int n) {


   if (n <= 2) {
       return;
   }
    cnt++;

   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           cnt++;
       }
       p >>= 1;
       cnt++;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       cnt++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }
   cnt++;


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
   dep++;

}

int main(){
    complexRec(16);
    cout<<cnt<<endl;
    cout<<dep;
    return 0;
}    