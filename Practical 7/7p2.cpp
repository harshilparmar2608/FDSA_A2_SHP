#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;

    q.push("Bhavya");
    cout << "Front: " << q.front() << endl;

    q.push("Reyansh");
    cout << "Front: " << q.front() << endl;

    q.push("Keshav");
    cout << "Front: " << q.front() << endl;

    q.pop();
    cout << "Front: " << q.front() << endl;

    q.pop();
    cout << "Front: " << q.front() << endl;

    return 0;
}
