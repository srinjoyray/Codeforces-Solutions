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

int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { lli n;
      cin>>n;
      int count=0,flag=0,temp;
      vector<lli> v;
      while(count!=2 )
      { temp=count;
        for(int i=2;i<=sqrt(n);i++)
         {
          if(n%i==0 && find(v.begin(),v.end(),i)==v.end())
           { n/=i;
             count++;
             v.push_back(i); //cout<<"*"<<n;
             break;
             
           }
         
         } 
        if(temp==count) 
           break;
        //cout<<n<<endl;  
      }
      if(count==2 && n>=2 && find(v.begin(),v.end(),n)==v.end())
       { cout<<"YES\n";
         cout<<v[0]<<" "<<v[1]<<" "<<n<<endl;  
       }
      else
       cout<<"NO\n";
      
    }  
    
    return 0;  
}