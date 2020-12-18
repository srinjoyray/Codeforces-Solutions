#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000003
#define pi 3.141592653589793238
using namespace std;
 
int main()
{ int n;
  cin>>n;
  int freq[n+1]={0},played[n+1]={0},temp_x,temp_y,pt_1=0,pt_2=0,pos_1=0,pos_2=0,flag=0;
  for(int i=1;i<=n;i++)
    { freq[i]=0;
      played[i]=0;    
    }
  for(int i=1;i<=(n*(n-1)/2)-1;i++)
     { cin>>temp_x>>temp_y;
       freq[temp_x]++;
       played[temp_x]++;played[temp_y]++;
     } 
      
  for(int i=1;i<=n;i++)  
  { 
    if(played[i]==n-2)
      { 
        if(flag==0)
          {pt_1=freq[i];pos_1=i;flag=1;}
        else
          {pt_2=freq[i];pos_2=i;break;}
      } 
  }// cout<<pos_1<<" "<<pt_1<<" "<<pos_2<<" "<<pt_2<<endl;
 
  
  if(pt_1>pt_2)
    {cout<<pos_1<<" "<<pos_2;}
  else if(pt_2>=pt_1)
    {cout<<pos_2<<" "<<pos_1;}
  return 0;  
}