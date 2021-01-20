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
    { int n;
      cin>>n;
      n*=2;
      lli a[n],sum,temp,flag=0,print;
      vector<lli> v,first,second;
      std::vector<lli>::iterator it; 
      for(int i=0;i<n;i++)
         cin>>a[i];
      sort(a,a+n,greater<int>());
      if(n==2)
       { cout<<"YES\n";
         cout<<a[0]+a[1]<<endl<<a[0]<<" "<<a[1]<<endl;  
         continue;
       }
       
      sum=a[0];     
         
      
      for(int skip=1;skip<n;skip++)
      { v.clear();
        
        for(int i=1;i<n;i++)
         { if(i!=skip)
            {  v.push_back(a[i]);
               //cout<<a[i]<<"@"<<i<<" ";
            }
           
         }
        
       /* for(int i=0;i<v.size();i++) 
           cout<<v[i]<<" ";
        cout<<endl;*/
        
        print=a[skip];  
        first.clear();
        second.clear();
        
       
          
        sum=a[0]; //cout<<sum<<" "<<print<<endl;
        while(v.size()>0) 
        { temp=sum-v[0]; //if(skip==2) cout<<temp<<endl;
          //cout<<temp<<endl;
          flag=0; 
          /*for(int j=1;j<v.size();j++)
           { 
             if(temp==v[j])
              {   sum=v[0];
                  first.push_back(v[0]);
                  second.push_back(v[j]);
                  v.erase(v.begin()+j);
                  v.erase(v.begin());
                  flag=1;
                  break;
              }
           
           } */
           sum=v[0];
           first.push_back(v[0]);
           v.erase(v.begin());
           it = std::find (v.begin(), v.end(), temp);
           if (it != v.end())
           {      
                  
                  second.push_back(*it);
                  v.erase(it);
                  
                  flag=1;
                 
               
           }
           if(flag==0)
             { 
               break;
             }   
         // cout<<v.size()<<endl;     
        }
        if(flag==1)
          { //cout<<skip<<endl; 
            break;
          }
      }    
        if(flag==0)
          cout<<"NO\n";
        else
        { cout<<"YES\n";
          cout<<a[0]+print<<endl;
          cout<<a[0]<<" "<<print<<endl;
          for(int i=0;i<first.size();i++)
          cout<<first[i]<<" "<<second[i]<<endl;
        }
          
    }  
    
    return 0;  
}