#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--)
    { int n,x,sum=0;
      cin>>n>>x;
      for(int i=1;;i++)
         { if(i==1)
             sum+=2;
           else 
             sum+=x;
           if(sum>=n)
              {cout<<i<<endl;break;}
             
         }
        
    }
    
}