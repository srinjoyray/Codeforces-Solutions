#include<iostream>
#include<string.h>
using namespace std;
int main()
{ int n;
  cin>>n;
  while(n--)
  { int len;
    char word[101];
    cin>>word;
    len=strlen(word);
    if(len>10)
      cout<<word[0]<<len-2<<word[len-1];
    else
      cout<<word;
    cout<<endl;  
  }
    
}