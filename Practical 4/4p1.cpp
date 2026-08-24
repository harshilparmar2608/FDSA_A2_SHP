#include <iostream>
using namespace std;

class Node
{
public:
    int token;
    Node *next;

    Node(int t)
    {
        token = t;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void insertFront(int token)
    {
        Node *newNode = new Node(token);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int token)
    {
        Node *newNode = new Node(token);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int token, int pos)
    {
        if (pos <= 1 || head == NULL)
        {
            insertFront(token);
            return;
        }

        Node *newNode = new Node(token);
        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList queue;

    int choice;

    while(choice!=3)
    {
        int token, pos;

        cout << "\n1. Critical Patient (Front)" << endl;
        cout << "2. Routine Patient (End)" << endl;
        cout << "3. Priority Patient (Specific Position)" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient token: ";
            cin >> token;
            queue.insertFront(token);
        }
        else if (choice == 2)
        {
            cout << "Enter patient token: ";
            cin >> token;
            queue.insertEnd(token);
        }
        else if (choice == 3)
        {
            cout << "Enter patient token: ";
            cin >> token;
            cout << "Enter position: ";
            cin >> pos;
            queue.insertAtPosition(token, pos);
        }
        else
        {
            cout << "Invalid Choice!" << endl;
            continue;
        }

        cout << "Current Queue: ";
        queue.display();
    }

    return 0;
}