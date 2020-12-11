#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
#define mod 1000000007
using namespace std;

int main()
{ int n; 
  cin>>n;
  lli arr[n],player1=0,player2=0,winner=0;
  vector<int> p1,p2;
  for(int i=0;i<n;i++)
     cin>>arr[i]; 
  for(int i=0;i<n;i++)
    { if(arr[i]>0)
        { p1.push_back(arr[i]);
          player1+=arr[i];    
        }
      else
        { p2.push_back(arr[i]*(-1));
          player2+=arr[i]*(-1);
        }
    }
  if(player1>player2)
    winner=1;
  else if(player2>player1)
    winner=2;
  else
  { for(int i=0;i<p1.size();i++)
       if(p1[i]!=p2[i])
         { if(p1[i]>p2[i])
             {winner=1;break;}
           else
             {winner=2;break;}
         }
    if(winner==0)
      { if(arr[n-1]>0)
           winner=1;
        else
           winner=2;
      }
  } 
  
  if(winner==1)
    cout<<"first";
  else
    cout<<"second";
  return 0;  
}