#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to replace {name} with actual user input
string personalize(string roast, string name) {
    size_t pos = roast.find("{name}");
    if (pos != string::npos) {
        roast.replace(pos, 6, name);
    }
    return roast;
}

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    // Roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name}'s debugging style is staring at the screen until the bug leaves.",
        "{name}'s code runs so slowly that dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name}'s code has more errors than a broken calculator.",
        "{name} types so slow, even autocorrect gave up.",
        "{name}'s logic is like WiFi — weak and unstable.",
        "Even AI refuses to fix {name}'s code."
    };

    // Seed random generator
    srand(time(0));

    int index = rand() % roasts.size();

    string finalRoast = personalize(roasts[index], name);

    cout << "\n🔥 Roast Generator 🔥" << endl;
    cout << finalRoast << endl;

    return 0;
}
