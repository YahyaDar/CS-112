#include <iostream>
#include <conio.h> // For getch() on line 104

using namespace std;

// Structure to represent each car having basic identifiers e.g points
struct Car {
    int points;
    int position;
    int wins;
};

// Nested struct to set the layout of the race track
struct RacingTrack {
    Car car1;
    Car car2;
    int trackLength;
};

// User defined Function to display the cars inside the track on the console
void displayTrack(const RacingTrack& track1, const RacingTrack track2) {
    // Display the racing track layout
    cout << "|Racing Track:" << endl;
    cout << "|______________________________|" << endl;
    cout << "| c1                 c2        |" << endl;
    cout << "+_____________________________+|" << endl;
    cout << "| Controls:                    |" << endl;
    cout << "| - Car-1: 'a' (left), 'd' (right)|" << endl;
    cout << "| - Car-2: 'j' (left), 'l' (right)|" << endl;
    cout << "| - Quit Press (q)              |" << endl;
    cout << endl;

    // List Car1's position on the track
    cout << "|";
    for (int i = 0; i < track1.trackLength; ++i) {
        if (i == track1.car1.position) {
            cout << 'C1'; // Display Car 1
        } else {
            cout << "[1;31m - [0m"; // Black Space
        }
    }
    cout << "|" << endl;

    // Display Car 2 position on the track
    cout << "|";
    for (int i = 0; i < track2.trackLength; ++i) {
        if (i == track2.car2.position) {
            cout << '2'; // Display Car 2
        } else {
            cout << "[1;34m - [0m"; // Empty space on track
        }
    }
    cout << "|" << endl;

    // Display positions, points, and wins for both cars on the console
    cout << "Car 1 - Position: " << track1.car1.position << ", Points: " << track1.car1.points << endl;
    cout << "Car 2 - Position: " << track2.car2.position << ", Points: " << track2.car2.points << endl;
    cout << "Car 1 - Wins: " << track1.car1.wins << "  " << " Car 2 - Wins: " << track2.car2.wins << endl;
}

// Function to update the cars direction based on user input
void updateGameState(RacingTrack& track1, RacingTrack& track2, char key) {
    // Update Car 1 position
    if (key == 'a' && track1.car1.position > 0) {
        track1.car1.position--;
    } else if (key == 'd' && track1.car1.position < track1.trackLength - 1) {
        track1.car1.position++;
        track1.car1.points++;
    }

    // Update Car 2 position
    if (key == 'j' && track2.car2.position > 0) {
        track2.car2.position--;
    } else if (key == 'l' && track2.car2.position < track2.trackLength - 1) {
        track2.car2.position++;
        track2.car2.points++;
    }
}

int main() {
    RacingTrack track1, track2;
    track1.car1.wins = 0;
    track2.car2.wins = 0;

    // Initialize the racing track
    restart:
    track1.trackLength = 30;
    track2.trackLength = 30;
    track1.car1.position = 0;
    track1.car1.points = 0;
    track2.car2.position = 0;
    track2.car2.points = 0;

    // variables to store keyboard input
    char key;
    char ch;

    // While true loop to keep game running unless user gives keyboard interupt or game is completed
    while (true) {
        // Display the current state of the game.
        displayTrack(track1, track2);

        // Get the keyboard input.
        key = getch(); // getch is  a function in the conio.h library to get user input from keyboard buffer so user does not have to click enter after every move made

        // Keyboard interupt to quit the game if q is pressed
        if (key == 'q' || key='Q') { // here we specifed the program to quit if lowercase 'or' uppercase q is pressed in case CAPSLOCK is enabled on the user's machine
            cout << "Exiting the game." << endl;
            break;
        }

        updateGameState(track1, track2, key);
        system("cls"); // Clear the console screen (This only works in Windows)

        // Check if either car reached the finish line
        if (track1.car1.position == 29) {
            system("clear");
            cout << "Car 1 wins ";
            track1.car1.wins++;
            cout << "If you want to play again press 'y' :";
            cin >> ch;
            if (ch == 'y') {
                goto restart;
            }
        }
        if (track2.car2.position == 29) {
            system("clear");
            cout << "Car 2 wins ";
            track2.car2.wins++;
            cout << "If you want to play again press 'y' :";
            cin >> ch;
            if (ch == 'y') {
                goto restart;
            }
        }
    }

    return 0;
}
