#include<iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int cnt = 0;
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
   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);

}

int main(){
    int n;
    cin>>n;
    auto start = high_resolution_clock::now();
    complexRec(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "No. of operations: "<<cnt<<endl;
    cout << "Depth: "<<floor(log2(n))<<endl;
    cout << "Execution time: "<<duration.count();
    return 0;
}    