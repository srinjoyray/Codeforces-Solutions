#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<ctype.h>
using namespace std;

int main()
{ int n;
  cin>>n;
  int x[n],y[n],z[n],sum1=0,sum2=0,sum3=0;
  for(int i=0;i<n;i++)
  { cin>>x[i]>>y[i]>>z[i];
    sum1+=x[i];
    sum2+=y[i];
    sum3+=z[i];
  }     
  if(sum1==0 && sum2==0 && sum3==0)
    cout<<"YES";
  else
    cout<<"NO\n";
  return 0;  
}