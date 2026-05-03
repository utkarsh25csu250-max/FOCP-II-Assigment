#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit when the file mysteriously disappeared.",
        "{name}'s dog ate the USB drive this time.",
        "{name} accidentally saved the homework in a parallel universe."
    };

    int index = rand() % excuses.size();
    string excuse = excuses[index];

    size_t pos = excuse.find("{name}");
    if (pos != string::npos)
        excuse.replace(pos, 6, name);

    cout << "\nExcuse: " << excuse << endl;
    return 0;
}