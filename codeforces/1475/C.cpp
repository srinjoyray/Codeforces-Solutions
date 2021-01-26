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
    { lli a,b,k;
      cin>>a>>b>>k;
      int A[k],B[k];
      lli freq_a[a+1]={0},freq_b[b+1]={0},total_a,total_b,ans=0,past;
      lli temp_a[a+1]={0},temp_b[b+1]={0};
      for(int i=0;i<k;i++)
      {  cin>>A[i];
         freq_a[A[i]]++; 
      }
      for(int i=0;i<k;i++)
      {  cin>>B[i];
         freq_b[B[i]]++;
      }  
      
      for(int i=0;i<k;i++)
      {//total_a=(k-freq_a[A[i]]);
        //total_b=(k-freq_b[B[i]]);
        
        ans+=k-(freq_a[A[i]]-1+freq_b[B[i]]-1)-1;
        past=(i-(temp_a[A[i]]+temp_b[B[i]]));
        temp_a[A[i]]++;
        temp_b[B[i]]++;
        //cout<<ans<<" ";
        ans-=past;
        //cout<<ans<<endl;
      }
      cout<<ans<<endl;
    }  
    
    return 0;  
}