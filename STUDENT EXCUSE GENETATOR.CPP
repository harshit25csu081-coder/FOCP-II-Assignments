#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

string personalize(string text, const string& name) {
    size_t pos = 0;
    while ((pos = text.find("{name}", pos)) != string::npos) {
        text.replace(pos, 6, name);
        pos += name.length();
    }
    return text;
}

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return 0;
    }

    vector<string> excuses = {
        "{name} couldn’t finish because {name}'s laptop crashed.",
        "{name} tried submitting but {name}'s file disappeared.",
        "{name}'s system froze while working.",
        "{name} forgot to save the file.",
        "{name}'s internet stopped working.",
        "{name} accidentally deleted the file.",
        "{name}'s computer restarted suddenly.",
        "{name} faced a power cut.",
        "{name} got logged out suddenly.",
        "{name}'s keyboard stopped working."
    };

    srand(time(0));
    int index = rand() % excuses.size();

    cout << personalize(excuses[index], name) << endl;
    return 0;
}
