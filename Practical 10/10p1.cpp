#include <iostream>
using namespace std;

int main() {
    int slots[10];
    int n, reg;

    for (int i = 0; i < 10; i++)
        slots[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> reg;

        int slot = reg % 10;
        int count = 0;

        while (slots[slot] != -1 && count < 10) {
            slot = (slot + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full!\n";
        } else {
            slots[slot] = reg;
            cout << "Vehicle " << reg
                 << " parked in slot " << slot << endl;
        }
    }

    cout << "\nFinal Parking Lot:\n";
    for (int i = 0; i < 10; i++) {
        if (slots[i] == -1)
            cout << "Slot " << i << ": Empty\n";
        else
            cout << "Slot " << i << ": "
                 << slots[i] << endl;
    }

    return 0;
}
