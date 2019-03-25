#include <iostream>
#include "string"
#include "IO/IOOperations.h"
#include "Actions/Executioner.h"

using namespace std;

char toLowerCase(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
    UserStore userStore;
    PlaylistsStore playlistsStore;

    IOOperations operations(userStore, playlistsStore);

    Executioner executioner(userStore, playlistsStore);

    operations.loadAppInfo();

    string answer;
    string rawAnswer;

    cout << "ChatBot loaded." << endl;

    cout << "Hello I am your personal ChatBot for keeping your playlists." << endl;
    cout << "Can I help you? (Please answer with yes or no)" << endl;
    cin >> rawAnswer;
    answer = rawAnswer;
    std::transform(answer.begin(), answer.end(), answer.begin(), toLowerCase);

    if (answer != "yes")
        return 0;

    cout << "What is your name?" << endl;
    cin >> rawAnswer;
    answer = rawAnswer;
    std::transform(answer.begin(), answer.end(), answer.begin(), toLowerCase);
    string firstName = answer;

    cout << "What is your second name?" << endl;
    cin >> rawAnswer;
    answer = rawAnswer;
    std::transform(answer.begin(), answer.end(), answer.begin(), toLowerCase);
    string secondName = answer;

    cout << "Hello, " << firstName << " " << secondName << endl;

    cout << "How old are you? (Please specify age in a whole number)" << endl;
    cin >> rawAnswer;
    answer = rawAnswer;
    std::transform(answer.begin(), answer.end(), answer.begin(), toLowerCase);
    int age = std::stoi(answer);

    cout << "Thank you for providing me the information so that I can function properly" << endl;

    if (!userStore.containsUser(firstName, secondName, age)) {
        User user(time(nullptr), firstName, secondName, age);
        userStore.addUser(user);

        cout << "Since I am not able to find you in my database your info has been added" << endl;
    }

    User &user = userStore.getUser(userStore.indexOf(firstName, secondName, age));

    string action;
    while (true) {
        cout << "From the menu you can choose which action I should do" << endl << endl;
        cout << "    A) Show me my playlists" << endl;
        cout << "    B) Create new playlist" << endl;
        cout << "    C) Add song to playlist" << endl;
        cout << "    D) Remove song from playlist" << endl;
        cout << "    E) Delete playlist" << endl;
        cout << endl;
        cout << "If you want to safely exit the application write \"STOP\" unless information may be lost" << endl;
        cin >> action;

        std::transform(action.begin(), action.end(), action.begin(), toLowerCase);

        executioner.execute(action, user);

        if (action == "stop") {
            cout << "Saving you information to the database...." << endl;
            operations.saveAppInfo();
            cout << "All saved." << endl;
            return 1;
        }

    }

    // As ID Generator
    // time_t t = time(0);  // t is an integer type
    // std::cout << t << " seconds since 01-Jan-1970\n";
}