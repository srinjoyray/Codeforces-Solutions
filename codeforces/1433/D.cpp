#include <bits/stdc++.h>
#define lli long long int 
#define mod 1000000007
#define pi 3.141592653589793238
using namespace std;

int main()
{   int t=1;
    cin>>t;
    while(t--)
    { int n,pos1,pos2;
      cin>>n;
      lli a[n];
      vector<lli> v1,v2;
      bool yes=false;
      for(int i=0;i<n;i++)
         cin>>a[i];
      for(int i=0;i<n-1;i++)
        if(a[i]!=a[i+1])
        {  yes=true; break;}
      if(!yes)
      { cout<<"NO\n";
        continue;
      }
      cout<<"YES\n";
      for(int i=0,j;i<n;i++)
      { j=i+1;
        while(a[j]==a[i] && j<n) 
          j++;
        pos1=i;
        pos2=j;
        break;
      } //cout<<pos1<<"#"<<pos2<<endl;
      for(int i=0;i<n;i++)
      { if(i==pos1 || i==pos2)
          continue;
        if(a[pos1]!=a[i])
          v1.push_back(i+1);
        else
          v2.push_back(i+1);
      }
      pos1++; pos2++;
      cout<<pos1<<" "<<pos2<<endl;
      for(int i=0;i<v1.size();i++)
         cout<<pos1<<" "<<v1[i]<<endl;
      for(int i=0;i<v2.size();i++)
         cout<<pos2<<" "<<v2[i]<<endl;
    }  
    
    return 0;  
}