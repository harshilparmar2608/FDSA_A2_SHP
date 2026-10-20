// A group of students are sitting in a circle playing a passing game. A token starts at the first 
// student and is passed around the circle one student at a time. Students can join the circle at any 
// position and leave at any time, and the circle must remain unbroken after every join or leave. 
// Given a sequence of join, leave, and display operations, implement them on both a singly 
// circular and a doubly circular linked list and print the current circle after each operation.
// Describe how your solution ensures the circle stays unbroken after a student leaves. What is 
// the one case where breaking the circle is most likely to happen as a bug, and how did you 
// handle it?

#include <iostream>
#include <string>
using namespace std;

class SinglyCircular {
    struct Node {
        string name;
        Node* next;

        Node(string n) {
            name = n;
            next = nullptr;
        }
    };

    Node* head;

public:
    SinglyCircular() {
        head = nullptr;
    }

    void join(string name, int position) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (position <= 1) {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void leave(string name) {
        if (head == nullptr)
            return;

        if (head->name == name && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        if (head->name == name) {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            Node* temp = head;
            head = head->next;

            last->next = head;  
            delete temp;
            return;
        }

        // Removing any other node
        Node* prev = head;
        Node* curr = head->next;

        while (curr != head) {
            if (curr->name == name) {
                prev->next = curr->next;  
                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Singly Circular: ";

        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to " << head->name << ")\n";
    }
};


class DoublyCircular {
    struct Node {
        string name;
        Node* next;
        Node* prev;

        Node(string n) {
            name = n;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;

public:
    DoublyCircular() {
        head = nullptr;
    }

    void join(string name, int position) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        if (position <= 1) {
            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        Node* curr = head;

        for (int i = 1; i < position && curr->next != head; i++)
            curr = curr->next;

        Node* prevNode = curr->prev;

        newNode->next = curr;
        newNode->prev = prevNode;

        prevNode->next = newNode;
        curr->prev = newNode;
    }

    void leave(string name) {
        if (head == nullptr)
            return;

        Node* curr = head;

        do {
            if (curr->name == name)
                break;

            curr = curr->next;
        } while (curr != head);

        if (curr->name != name)
            return;

        if (curr->next == curr) {
            delete curr;
            head = nullptr;
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if (curr == head)
            head = curr->next;

        delete curr;
    }

    void display() {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Doubly Circular: ";

        do {
            cout << temp->name << " <-> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to " << head->name << ")\n";
    }
};


int main() {

    SinglyCircular S;
    DoublyCircular D;

    int n;

    cout << "Enter number of activites: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
    cout << "Enter activities (join/leave/display): ";

        string operation;
        cin >> operation;

        if (operation == "join") {

            string name;
            int position;
    cout << "Enter name and position : ";

            cin >> name >> position;

            S.join(name, position);
            D.join(name, position);

        }
        else if (operation == "leave") {
    cout << "Enter name who leaved : ";

            string name;
            cin >> name;

            S.leave(name);
            D.leave(name);

        }
        else if (operation == "display") {

            S.display();
            D.display();
        }

        cout << "\nCurrent Circle:\n";
        S.display();
        D.display();

        cout << "-----------------------------\n";
    }

    return 0;
}