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
bool comp(pair<int,int> &a,pair<int,int> &b)
{ if(a.first==b.first)
    return(a.second<b.second);
  return(a.first<b.first);     
}
int main()
{   int t;
    cin>>t;
    //t=1; 
    while(t--)
    { int n;
      cin>>n;
      int hor=0,vert=0,flag=0,dist_x,dist_y,t1,t2;
      string s;
      vector<pair<int,int>> v;
      for(int i=0;i<n;i++)
        { cin>>t1>>t2;
          v.push_back({t1,t2});
        }
      sort(v.begin(),v.end(),comp);  
    /* for(int i=0;i<n;i++)
       cout<<v[i].first<<" "<<v[i].second<<endl;*/
      for(int i=0;i<n;i++)
      { if(v[i].first<hor) 
          { flag=1;break;}
        if(v[i].second<vert)
          { flag=1;break;}
        dist_x=v[i].first-hor;
        dist_y=v[i].second-vert;
        hor+=dist_x;
        vert+=dist_y;
        for(int i=1;i<=dist_x;i++)
           s.push_back('R');
        for(int i=1;i<=dist_y;i++)
           s.push_back('U');
           
      }
      if(flag==1)
        cout<<"NO\n";
      else
        cout<<"YES\n"<<s<<endl;
         
    }  
    
    return 0;  
}