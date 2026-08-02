#include<iostream>
using namespace std;
int main()
{
    int n, i, find, left;
    cout << "Enter the number of the Cars: ";
    cin >> n;
    int a[n];

    for(i = 0; i < n; i++)
    {
        cout<<"Enter the Number Plate of the Car "<<i+1<<" :";
        cin >> a[i];
        cout<<endl;
    }
    for(  i = 0; i<n ; i++)
    {
        cout<<a[i]<<" ";
        cout<<endl;
    }
            cout<<"Enter the Number Plate of the Car to be find ";
            cin>>find;
            cout<<endl;
cout << "Enter the position from which the guard left off: ";
    cin >> left;
    cout<<endl;


        for(int i=0; i<left; i++)
        {
            if(a[i]==find)
            {
                        cout<<"Guard founded the Car at "<<i+1<<" position";
                        cout<<endl;
                        break;

            }


        }
if(left != n)
{
                            cout<<"Helper Started finding the car from "<<left<<" position";
                            cout<<endl;

}


         for(int i=left; i<n; i++)
        {
            if(a[i]==find)
            {
                        cout<<"Helper founded the Car at "<<i+1<<" position";
                        break;

            }


        }

    cout<<endl;
    return 0;
}
