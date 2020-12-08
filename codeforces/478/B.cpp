#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;
 
long long comb(long long n)
{ return (n*(n-1))/2;
}
 
 
int main()
{ long long m,n,max_k,min_k,temp;
  cin>>n>>m;
  temp=n-(m-1);
  max_k=comb(temp);
  temp=n/m;
  if(n%m==0)
    min_k=m*comb(temp);
  else
    min_k=((n%m)*comb(temp+1))+((m-(n%m))*comb(temp));
  cout<<min_k<<" "<<max_k;    
  return 0;  
}