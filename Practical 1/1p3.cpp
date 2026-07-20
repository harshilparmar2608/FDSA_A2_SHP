#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of the words: ";
    cin >> n;
    string a[n];

    for(int i = 0; i < n; i++)
    {
         cout<<"Enter the word "<<i+1<<" :";
        cin >> a[i];
    }
    for(int i = 0; i<n ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
int maxx;
string m;
maxx=a[0].length();
for(int i=0; i<n; i++)
{
    if(maxx<a[i].length())
    {
       m=a[i] ;
    }

}
cout<<"Longest word is : "<<m<<endl;

    return 0;
}
