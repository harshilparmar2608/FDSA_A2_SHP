#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node *next;

    Node(int val)
    {
        token = val;
        next = NULL;
    }
};

class PatientQueue
{
private:
    Node *head;

public:
    PatientQueue()
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
            temp = temp->next;

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
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteToken(int token)
    {
        if (head == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        if (head->token == token)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Token " << token << " deleted." << endl;
            return;
        }

        Node *curr = head;
        while (curr->next != NULL && curr->next->token != token)
            curr = curr->next;

        if (curr->next == NULL)
        {
            cout << "Token not found." << endl;
            return;
        }

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;

        cout << "Token " << token << " deleted." << endl;
    }

    void displayForward()
    {
        if (head == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = head;
        cout << "Queue (Front to Back): ";

        while (temp != NULL)
        {
            cout << temp->token << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reversePrint(Node *temp)
    {
        if (temp == NULL)
            return;

        reversePrint(temp->next);
        cout << temp->token << " ";
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue (Back to Front): ";
        reversePrint(head);
        cout << endl;
    }
};

int main()
{
    PatientQueue q;

    int choice, token, pos;

    do
    {
        cout << "\n===== Patient Queue Menu =====\n";
        cout << "1. Insert Critical Patient (Front)\n";
        cout << "2. Insert Routine Patient (End)\n";
        cout << "3. Insert Priority Patient (Position)\n";
        cout << "4. Delete Patient Token\n";
        cout << "5. Display Queue (Front to Back)\n";
        cout << "6. Display Queue (Back to Front)\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter Patient Token: ";
            cin >> token;
            q.insertFront(token);
            break;

        case 2:
            cout << "Enter Patient Token: ";
            cin >> token;
            q.insertEnd(token);
            break;

        case 3:
            cout << "Enter Patient Token: ";
            cin >> token;
            cout << "Enter Position: ";
            cin >> pos;
            q.insertAtPosition(token, pos);
            break;

        case 4:
            cout << "Enter Token to Delete: ";
            cin >> token;
            q.deleteToken(token);
            break;

        case 5:
            q.displayForward();
            break;

        case 6:
            q.displayReverse();
            break;

        case 7:
            cout << "Program Ended." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}