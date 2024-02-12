#include <iostream>
#include <cmath>
#include <chrono>
#include "search.hpp"
using namespace std;
using namespace chrono;

int main() {
    const int size = 10;
    int arr[size] = {1167, 1588, 2472, 3780, 6681, 8352, 8761, 9029, 9403, 9891};
    int key = 2472;

    // Rozpoczęcie liczenia czasu
    auto start = steady_clock::now();

    int index = liniowe_wyszukiwanie(arr, size, key);
    auto end = steady_clock::now(); // Koniec czasu dla wyszukiwania liniowego
    duration<double> elapsed_seconds = end - start;
    if (index != -1) {
        cout << "Liniowe wyszukiwanie: Znaleziono klucz " << key << " pod indeksem " << index << endl
             << "Czas wykonania: " << elapsed_seconds.count() << " s" << endl;
    } else {
        cout << "Liniowe wyszukiwanie: Klucz " << key << " nie został znaleziony. Czas wykonania: " 
             << elapsed_seconds.count() << " s" << endl;
    }

    start = steady_clock::now();
    index = liniowe_wyszukiwanie_z_wartownikiem(arr, size, key);
    end = steady_clock::now(); // Koniec czasu dla wyszukiwania liniowego z wartownikiem
    elapsed_seconds = end - start;
    if (index != -1) {
        cout << "Liniowe wyszukiwanie z wartownikiem: Znaleziono klucz " << key << " pod indeksem " << index << endl 
             << "Czas wykonania: " << elapsed_seconds.count() << " s" << endl;
    } else {
        cout << "Liniowe wyszukiwanie z wartownikiem: Klucz " << key << " nie został znaleziony. Czas wykonania: " 
             << elapsed_seconds.count() << " s" << endl;
    }

    start = steady_clock::now();
    index = wyszukiwanie_skokowe(arr, size, key);
    end = steady_clock::now(); // Koniec czasu dla wyszukiwania skokowego
    elapsed_seconds = end - start;
    if (index != -1) {
        cout << "Wyszukiwanie skokowe: Znaleziono klucz " << key << " pod indeksem " << index << endl
             << "Czas wykonania: " << elapsed_seconds.count() << " s" << endl;
    } else {
        cout << "Wyszukiwanie skokowe: Klucz " << key << " nie został znaleziony. Czas wykonania: " 
             << elapsed_seconds.count() << " s" << endl;
    }

    start = steady_clock::now();
    index = wyszukiwanie_binarne(arr, size, key);
    end = steady_clock::now(); // Koniec czasu dla wyszukiwania binarnego
    elapsed_seconds = end - start;
    if (index != -1) {
        cout << "Wyszukiwanie binarne: Znaleziono klucz " << key << " pod indeksem " << index << endl
             << "Czas wykonania: " << elapsed_seconds.count() << " s" << endl;
    } else {
        cout << "Wyszukiwanie binarne: Klucz " << key << " nie został znaleziony. Czas wykonania: " 
             << elapsed_seconds.count() << " s" << endl;
    }

    start = steady_clock::now();
    index = wyszukiwanie_interpolacyjne(arr, size, key);
    end = steady_clock::now(); // Koniec czasu dla wyszukiwania interpolacyjnego
    elapsed_seconds = end - start;
    if (index != -1) {
        cout << "Wyszukiwanie interpolacyjne: Znaleziono klucz " << key << " pod indeksem " << index << endl
             << "Czas wykonania: " << elapsed_seconds.count() << " s" << endl;
    } else {
        cout << "Wyszukiwanie interpolacyjne: Klucz " << key << " nie został znaleziony. Czas wykonania: " 
             << elapsed_seconds.count() << " s" << endl;
    }

    // Zakończenie liczenia czasu
    end = steady_clock::now();
    duration<double> elapsed_total_seconds = end - start;

    // Wyświetlenie czasu trwania wyszukiwania
    cout << endl << "Całkowity czas wyszukiwania: " << elapsed_total_seconds.count() << " s" << endl;

    return 0;
}