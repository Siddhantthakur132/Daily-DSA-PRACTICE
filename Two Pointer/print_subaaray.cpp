#include<bits/stdc++.h>
using namespace std;

void print_subarray(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      for(int k=j;k<=j;k++)
      {
        cout<<"{"<<arr[k]<<"}";
      }
      cout<<",";
    }
  }
}

int main()
{
  int n;
  int arr[5];
  cout<<"Enter the size of array ";
  cin>>n;

    cout<<"Enter the Element of array ";
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }

    print_subarray(arr,n);
}