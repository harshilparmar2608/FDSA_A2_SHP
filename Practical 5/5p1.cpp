#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    
    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        display();
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        display();
    }

    void insertAfter(string specificSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != specificSong) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found!" << endl;
        } else {
            Node* newNode = new Node(newSong);

            newNode->prev = temp;
            newNode->next = temp->next;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            } else {
                tail = newNode;
            }

            temp->next = newNode;
        }

        display();
    }

     void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
        } else {
            Node* temp = head;

            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }

            delete temp;
        }

        display();
    }

    void countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Number of songs: " << count << endl;
    }

    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        if (head == NULL) {
            cout << "Empty";
        }

        while (temp != NULL) {
            cout << temp->song;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Playlist p;

    int choice;
    string song, specificSong;

    do {
        cout << "\n--- MUSIC PLAYLIST ---" << endl;
        cout << "1. Add song at beginning" << endl;
        cout << "2. Add song at end" << endl;
        cout << "3. Insert song after a specific song" << endl;
        cout << "4. Remove first song" << endl;
        cout << "5. Count songs" << endl;
        cout << "6. Display playlist" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter song name: ";
            cin >> song;
            p.addBeginning(song);
            break;

        case 2:
            cout << "Enter song name: ";
            cin >> song;
            p.addEnd(song);
            break;

        case 3:
            cout << "Enter song after which to insert: ";
            cin >> specificSong;

            cout << "Enter new song name: ";
            cin >> song;

            p.insertAfter(specificSong, song);
            break;

        case 4:
            cout << "Removing first song..." << endl;
            p.removeFirst();
            break;

        case 5:
            p.countSongs();
            break;

        case 6:
            p.display();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}