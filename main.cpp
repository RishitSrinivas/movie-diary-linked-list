#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>   // atoi
using namespace std;

/*
 Movie Diary Application
 -----------------------
 A menu-driven C++ program that uses a singly linked list to store,
 organize, and persist movie data using file I/O.
*/

// Movie node definition
struct Movie {
    string title;
    int yearViewed;
    int rating;
    Movie* next;
};

// Function prototypes
void printMenu();
void loadMoviesFromFile(Movie*& head, Movie*& tail, int& count);
void saveMoviesToFile(const Movie* head);
void addMovie(Movie*& head, Movie*& tail, int& count);
void removeMovie(Movie*& head, Movie*& tail, int& count);
void displayMovies(const Movie* head);
void updateRating(Movie* head, int count);
void arrangeByTitle(Movie*& head);
void arrangeByYearViewed(Movie*& head);
void arrangeByRating(Movie*& head);

int main() {
    cout << "Welcome to your movie diary!\n\n";

    Movie* movieHead = nullptr;
    Movie* movieTail = nullptr;
    int movieCount = 0;
    char choice;

    loadMoviesFromFile(movieHead, movieTail, movieCount);

    do {
        printMenu();
        cin >> choice;
        choice = tolower(choice);

        switch (choice) {
            case 'a': addMovie(movieHead, movieTail, movieCount); break;
            case 'u': updateRating(movieHead, movieCount); break;
            case 'e': removeMovie(movieHead, movieTail, movieCount); break;
            case 'l': displayMovies(movieHead); break;
            case 't': arrangeByTitle(movieHead); break;
            case 'v': arrangeByYearViewed(movieHead); break;
            case 'r': arrangeByRating(movieHead); break;
            case 'q': cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 'q');

    saveMoviesToFile(movieHead);

    // Free allocated memory
    while (movieHead != nullptr) {
        Movie* temp = movieHead;
        movieHead = movieHead->next;
        delete temp;
    }

    return 0;
}

// Displays menu options
void printMenu() {
    cout << "\nMENU\n"
         << "A Add a movie\n"
         << "U Update a movie rating\n"
         << "E Remove a movie\n"
         << "L List all movies\n"
         << "T Arrange by title\n"
         << "V Arrange by year viewed\n"
         << "R Arrange by rating\n"
         << "Q Quit\n"
         << "...your choice: ";
}

// Loads movies from file into linked list
void loadMoviesFromFile(Movie*& head, Movie*& tail, int& count) {
    ifstream file("movies.txt");
    if (!file) return;

    while (true) {
        Movie* node = new Movie;
        getline(file, node->title);
        if (node->title == "EOF" || file.fail()) {
            delete node;
            break;
        }

        file >> node->yearViewed >> node->rating;
        file.ignore(100, '\n');
        node->next = nullptr;

        if (!head) head = node;
        else tail->next = node;

        tail = node;
        count++;
    }
}

// Saves movies from linked list to file
void saveMoviesToFile(const Movie* head) {
    ofstream file("movies.txt");
    while (head) {
        file << head->title << "\n"
             << head->yearViewed << " "
             << head->rating << "\n";
        head = head->next;
    }
    file << "EOF";
}

// Adds a new movie to the list
void addMovie(Movie*& head, Movie*& tail, int& count) {
    Movie* node = new Movie;
    node->next = nullptr;

    cin.ignore();
    cout << "Movie title: ";
    getline(cin, node->title);

    cout << "Year viewed: ";
    cin >> node->yearViewed;

    cout << "Rating (1-5): ";
    cin >> node->rating;

    if (!head) head = node;
    else tail->next = node;

    tail = node;
    count++;
}

// Removes a movie by position
void removeMovie(Movie*& head, Movie*& tail, int& count) {
    if (!head) return;

    displayMovies(head);
    cout << "Select movie to remove: ";

    int pos;
    cin >> pos;

    if (pos < 1 || pos > count) return;

    Movie* current = head;
    Movie* previous = nullptr;

    for (int i = 1; i < pos; i++) {
        previous = current;
        current = current->next;
    }

    if (previous) previous->next = current->next;
    else head = current->next;

    if (current == tail) tail = previous;

    delete current;
    count--;
}

// Displays all movies
void displayMovies(const Movie* head) {
    int index = 1;
    cout << "\n#  Title                     Year Rating\n";
    cout << "-- ------------------------- ---- ------\n";

    while (head) {
        cout << index++ << "  "
             << head->title << "  "
             << head->yearViewed << "  "
             << head->rating << "\n";
        head = head->next;
    }
}

// Updates movie rating
void updateRating(Movie* head, int count) {
    displayMovies(head);
    cout << "Select movie to update: ";

    int pos;
    cin >> pos;

    if (pos < 1 || pos > count) return;

    for (int i = 1; i < pos; i++)
        head = head->next;

    cout << "New rating (1-5): ";
    cin >> head->rating;
}

// Sorts movies alphabetically by title
void arrangeByTitle(Movie*& head) {
    for (Movie* i = head; i; i = i->next)
        for (Movie* j = i->next; j; j = j->next)
            if (j->title < i->title)
                swap(*i, *j);
}

// Sorts movies by year viewed
void arrangeByYearViewed(Movie*& head) {
    for (Movie* i = head; i; i = i->next)
        for (Movie* j = i->next; j; j = j->next)
            if (j->yearViewed < i->yearViewed)
                swap(*i, *j);
}

// Sorts movies by rating
void arrangeByRating(Movie*& head) {
    for (Movie* i = head; i; i = i->next)
        for (Movie* j = i->next; j; j = j->next)
            if (j->rating < i->rating)
                swap(*i, *j);
}
