#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int rem,ans=0;
  while(n)
  {
    rem=n%10;
    ans+=rem;
    n/=10;
  }
  cout<<ans;
}
