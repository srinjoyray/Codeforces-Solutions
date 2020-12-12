#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;
#define pi 3.141592653589793238

int main()
{ int d,sum_time,avg;
  cin>>d>>sum_time;
  avg=sum_time/d;
  int min_time[d],max_time[d],my_time[d],total=0,max_total=0,min_total=0,left;
  for(int i=0;i<d;i++)
    { cin>>min_time[i]>>max_time[i];
      max_total+=max_time[i]; min_total+=min_time[i];     
    }
  if(sum_time>max_total || sum_time<min_total)
    {cout<<"NO";return 0;}
    
  for(int i=0;i<d;i++)
    { if(avg>=min_time[i] && avg<=max_time[i])
         { my_time[i]=avg; total+=avg;}
      else if(avg>max_time[i])
         { my_time[i]=max_time[i]; total+=max_time[i];}
      else
         { my_time[i]=min_time[i]; total+=min_time[i];}
    }
  left=sum_time-total;
  if(left>0)
  {   for(int i=0;i<d;i++)
      {  if(max_time[i]==my_time[i])
          continue;
         int temp;
         temp=max_time[i]-my_time[i];
         temp=std::min(temp,left);
         my_time[i]+=temp;
         left-=temp;
         if(left==0)
            break;
      }
  } 
  else if(left<0)
  { left=-left;
     for(int i=0;i<d;i++)
      { if(min_time[i]==my_time[i])
          continue; 
        int temp;
        temp=my_time[i]-min_time[i];
        temp=std::min(temp,left);
        my_time[i]-=temp;
        left-=temp;
        if(left==0)
           break;
      }
      
  }
  cout<<"YES\n";
  for(int i=0;i<d;i++)
    cout<<my_time[i]<<" ";
  return 0;  
}