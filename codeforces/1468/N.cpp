#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   lli c1,c2,c3,a1,a2,a3,a4,a5,left1,left2,left3;
        cin>>c1>>c2>>c3;
        cin>>a1>>a2>>a3>>a4>>a5;
        if(a1<=c1 && a2<=c2 && a3<=c3 && (a1+a2+a3+a4+a5)<=(c1+c2+c3))
        {   left1=c1-a1;
            left2=c2-a2;
            left3=c3-a3;
            if(a4>left3+left1 || a5>left3+left2)
                cout<<"NO\n";
            else      
                cout<<"YES\n";
        }   
        else
        {
            cout<<"NO\n";
        }
    }    
    return 0;
}