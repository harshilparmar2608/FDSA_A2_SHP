#include <iostream>
using namespace std;

int iterativeSearch(int a[], int n, int find)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (a[mid] == find)
            return mid;

        else if (find < a[mid])
            end = mid - 1;

        else
            start = mid + 1;
    }

    return -1;
}

int recursiveSearch(int a[], int start, int end, int find)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (a[mid] == find)
        return mid;

    else if (find < a[mid])
        return recursiveSearch(a, start, mid - 1, find);

    else
        return recursiveSearch(a, mid + 1, end, find);
}

int main()
{
    int n, find;

    cout << "Enter number of book: ";
    cin >> n;

    int a[n];

    cout << "Enter book code in sorted manner:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target book code: ";
    cin >> find;

    int p1 = iterativeSearch(a, n, find);

    if (p1 != -1)
        cout << "\nIterative Binary Search found at position " << p1 + 1 << endl;
    else
        cout << "\Book code not found." << endl;

    int p2 = recursiveSearch(a, 0, n - 1, find);

    if (p2 != -1)
        cout << "Recursive Binary Search found at position " << p2 + 1 << endl;
    else
        cout << "Book code not found." << endl;

    return 0;
}
