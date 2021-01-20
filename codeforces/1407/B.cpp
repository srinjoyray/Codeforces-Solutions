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
int gcd(int a,int b)
{ if(b==0)
    return a;
  return gcd(b,a%b);    
}
 
int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { int n,temp,pos,max;
      cin>>n;
      vector<int> a,b;
      for(int i=0;i<n;i++)
        {  cin>>temp;
           a.push_back(temp);
        }
      sort(a.begin(),a.end(),greater<int>());
    
      b.push_back(a[0]);
      a.erase(a.begin());
      int hcf=b[0];
      while(a.size())
      { max=gcd(hcf,a[0]);
        pos=0;
        for(int i=1;i<a.size();i++)
        { temp=gcd(a[i],hcf);
          if(max<temp)
           {max=temp; pos=i;}
        }
        b.push_back(a[pos]);
        a.erase(a.begin()+pos);
        hcf=max;
      }
      for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
      cout<<endl;    
    }  
    
    return 0;  
}