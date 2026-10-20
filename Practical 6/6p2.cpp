#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
    string* pages;
    int top;
    int capacity;

public:
    BrowserHistory() {
        capacity = 2;
        pages = new string[capacity];
        top = -1;
    }

    void visit(string page) {
        if (top + 1 == capacity) {
            capacity *= 2;
            string* newPages = new string[capacity];

            for (int i = 0; i <= top; i++)
                newPages[i] = pages[i];

            delete[] pages;
            pages = newPages;
        }

        pages[++top] = page;
        cout << "Current page: " << pages[top] << endl;
    }

    void back() {
        if (top <= 0) {
            cout << "No previous page" << endl;
            return;
        }

        top--;
        cout << "Current page: " << pages[top] << endl;
    }

    ~BrowserHistory() {
        delete[] pages;
    }
};

int main() {
    BrowserHistory history;

    history.visit("Google");
    history.visit("YouTube");
    history.visit("GitHub");

    history.back();
    history.back();
    history.back();

    return 0;
}
