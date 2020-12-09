#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
#define lli long long int 
using namespace std;

int main()
{  int t;
   cin>>t;
   while(t--)
   { lli n,root,flag=0;
     cin>>n;
     if(n==1)
       {cout<<"NO\n";continue;}
     root=sqrt(n);
     if(root*root!=n)
       {cout<<"NO\n";continue;}
     for(int i=2;i*i<=root;i++)
       if(root%i==0)
         {cout<<"NO\n";flag=1;break;}
     if(flag==0)
       cout<<"YES\n";     
       
   }
 return 0;  
}