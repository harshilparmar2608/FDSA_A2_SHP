#include <iostream>
using namespace std;

class Queue {
    int a[5], front = 0, rear = -1, count = 0;

public:
    void join(int x) {
        if (count == 5)
            cout << "Queue Full\n";
        else {
            rear = (rear + 1) % 5;
            a[rear] = x;
            count++;
            cout << "Front: " << a[front] << endl;
        }
    }

    void serve() {
        if (count == 0)
            cout << "Queue Empty\n";
        else {
            front = (front + 1) % 5;
            count--;
            if (count)
                cout << "Front: " << a[front] << endl;
            else
                cout << "Queue Empty\n";
        }
    }
};

int main() {
    Queue q;

    q.join(10);
    q.join(20);
    q.join(30);
    q.serve();
    q.serve();
    q.join(40);

    return 0;
}
