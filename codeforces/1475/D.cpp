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
    { lli n,m;
      cin>>n>>m;
      lli a[n],point=0,temp,sum=0,one_sum=0,two_sum=0;
      for(int i=0;i<n;i++)
      {  cin>>a[i];
         sum+=a[i];
      }
      int b[n];
      for(int i=0;i<n;i++)
         cin>>b[i];
      if(sum<m)
      { cout<<"-1\n";
        continue;  
      }
      vector<lli>  one,two;
      for(int i=0;i<n;i++)
         if(b[i]==1)
           one.push_back(a[i]);
         else if(b[i]==2)
           two.push_back(a[i]);
      sort(one.begin(),one.end(),greater<int>());
      sort(two.begin(),two.end(),greater<int>());
     /* for(int i=0;i<one.size();i++)
        cout<<one[i]<<" ";
      cout<<endl;
      for(int i=0;i<two.size();i++)
        cout<<two[i]<<" ";
      cout<<endl;    */
      vector<lli> pre_one,pre_two;
      std::vector<lli>::iterator itr;
      temp=0;
      for(int i=0;i<one.size();i++)
      {  temp+=one[i];
         pre_one.push_back(temp);
      }
      temp=0;
      for(int i=0;i<two.size();i++)
      {  temp+=two[i];
         pre_two.push_back(temp);
      }     
      one_sum=pre_one[one.size()-1];
      two_sum=pre_two[two.size()-1];
      point=one.size()+2*(two.size());
      /*for(int i=0;i<pre_one.size();i++)
         cout<<pre_one[i]<<" ";
      cout<<endl;
      for(int i=0;i<pre_two.size();i++)
         cout<<pre_two[i]<<" ";
      cout<<endl; */    
      //cout<<one_sum<<" "<<two_sum<<endl;
      if(one.size()==0)
      { for(int i=0;i<pre_two.size();i++)
          if(pre_two[i]>=m)
           { cout<<2*(i+1)<<endl; break;}
        continue;   
      }
      if(two.size()==0)
      { for(int i=0;i<pre_one.size();i++)
          if(pre_one[i]>=m)
           { cout<<i+1<<endl; break;}
        continue; 
      }
      for(int i=0;i<pre_one.size();i++)
      { if(pre_one[i]+two_sum<m)
          continue; 
        else if(pre_one[i]>=m)
        { temp=i+1;
          point=std::min(point,temp);
          break;        
        }
        //cout<<i<<" "<<m-pre_one[i]<<endl;
        itr=std::lower_bound(pre_two.begin(), pre_two.end(), m-pre_one[i]);
        temp=(i+1)+2*(itr-pre_two.begin()+1);
        //cout<<temp<<"#"<<endl;
        point=std::min(point,temp);
      }
      for(int i=0;i<pre_two.size();i++)
      { if(pre_two[i]>=m)
          { temp=(i+1)*2;
            point=std::min(point,temp);
            break;
          }
      }
      cout<<point<<endl;
    }  
    
    return 0;  
}