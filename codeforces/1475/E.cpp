#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;
lli fact[1001];
lli power(lli a,lli n)
{ lli res=1;
  while(n)
  { if(n%2==0)
    { a=(a*a)%mod;
      n/=2;    
    }
    else
    { res=(res*a)%mod;
      n--;
    }  
  }
  return res;
}

lli comb(lli n, lli r) 
{ lli denom;
  denom=(fact[r]*fact[n-r])%mod;
  denom=power(denom,mod-2);
  return (fact[n]*denom)%mod;
} 
int main()
{   int t;
    cin>>t;
    //t=1; 
    fact[0]=1; fact[1]=1;
    for(int i=2;i<1001;i++)
       fact[i]=(fact[i-1]*i)%mod;
    while(t--)
    { lli n,k;
      cin>>n>>k;
      lli a[n],req=1,total,ans;
      for(int i=0;i<n;i++)
         cin>>a[i];
      sort(a,a+n,greater<int>());
      int pos=k-2;
      while(a[pos]==a[k-1] && pos>=0)
        { req++; pos--;}
      pos=k;
      total=req;
      while(pos<n && a[pos]==a[k-1])
        { total++;pos++;}
      ans=comb(total,req);      
      cout<<ans<<endl;
    }  
    
    return 0;  
}