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
    //cin>>t;
    t=1; 
    while(t--)
    { string s;
      cin>>s;
      int freq[26]={0},count=0;
      for(int i=0;i<s.size();i++)
         freq[s[i]-'a']++;
      for(int i=0;i<26;i++)
         if(freq[i]>0)
           count++;
      if(count%2==0)
        cout<<"CHAT WITH HER!";
      else
        cout<<"IGNORE HIM!";
    }  
    
    return 0;  
}