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
    //cin>>t;
    while(t--)
    { int n,m;
      cin>>n>>m;
      int a[n],l,freq[100001]={0},count=0,prefix[n];
      for(int i=0;i<n;i++)
      {  cin>>a[i];
         freq[a[i]]++; 
      }
        
      for(int i=1;i<100001;i++)
         if(freq[i]>0)
           count++;
      //cout<<count<<endl;       
      for(int i=0;i<n;i++)
      { prefix[i]=count;
        freq[a[i]]--;
        if(freq[a[i]]==0)
          count--;
       // cout<<count<<" ";  
      }//cout<<endl;
      /*for(int i=0;i<n;i++)
        cout<<prefix[i]<<" ";
      cout<<endl;    cout<<"#";*/
      while(m--)
      { cin>>l; //cout<<l<<" ";
        cout<<prefix[l-1]<<endl;  
      }
    }  
    
    return 0;  
}