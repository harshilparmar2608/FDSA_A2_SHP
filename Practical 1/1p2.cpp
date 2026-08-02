#include<iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of the books: ";
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter the IDs of the Book " << i + 1 << " : ";
        cin >> a[i];
    }

    cout << "\nBook IDs: ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < n; i++)
    {
        int seen = 0;
        int count = 0;

        for(int j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                seen = 1;
                break;
            }
        }

        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                count++;
            }
        }

        if(count > 0 && !seen)
        {
            cout << "Repeated Book ID is: " << a[i] << endl;
        }
    }

    return 0;
}
