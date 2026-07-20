#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the numer of the items: ";
    cin >> n;
    int a[n];
    cout<<"Enter the value of the items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = n; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter number of hours: "<<endl;
    int h;
    cin>>h;
int t;
for(int k=0; k<h;k++)
{
    t=a[0];
for(int i=0; i<n-1; i++)
{
   a[i]=a[i+1];
}
a[n-1]=t;
}

for(int i = 0; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
