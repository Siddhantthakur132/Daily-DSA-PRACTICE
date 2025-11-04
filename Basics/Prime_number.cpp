#include<iostream>
using namespace std;


int main()
{
  int n;
  cin>>n;

  int cnt=0;

  if(n<2)
  cout<<"not prime";
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
      cnt++;
    }
  }
  if(cnt>2)
    {
      cout<<"not prime";
    }
    else
    cout<<" prime number";
}