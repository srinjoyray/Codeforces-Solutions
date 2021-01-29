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
{   int t=1;
    cin>>t;
    while(t--)
    { lli n,flag=0;
      cin>>n;
      n*=2;
      lli d[n],sum=1,temp,curr=1;
      vector<lli> v;
      for(int i=0;i<n;i++)
         cin>>d[i];
      sort(d,d+n);
      for(int i=0;i<n;i+=2)
        if(d[i]==d[i+1] && d[i]%2==0 && d[i]!=0)
          v.push_back(d[i]);
        else
         { cout<<"NO\n"; flag=1; break;}
      if(flag==1)
        continue;
      n/=2;
      sort(v.begin(),v.end());
      
     /* for(int i=0;i<n;i++)
         cout<<v[i]<<" ";
      cout<<endl;*/ 
      
      for(int i=1;i<n;i++)
      {  if(v[i]==v[i-1] || ((v[i]-v[i-1])/2)%i!=0)
          { flag=1;  break;}      
      }   
      if(flag==1)
       { cout<<"NO\n"; continue;} //cout<<"@";
      //cout<<curr<<" ";
      for(int i=1;i<n;i++)
      { temp=(v[i]-v[i-1])/2;
        curr+=(temp/i);
        sum+=curr;
        //cout<<curr<<" ";
      } //cout<<sum<<endl; cout<<(v[0]/2)-sum<<" "<<n<<endl;
      if(((v[0]/2)-sum)%n==0 && sum<=(v[0]/2))
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }  
    
    return 0;  
}