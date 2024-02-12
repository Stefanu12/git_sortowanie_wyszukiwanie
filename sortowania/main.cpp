#include <iostream>
#include <ctime>
#include <chrono>
#include "search.hpp"
using namespace std;
using namespace chrono;


void losuj_tablice(int t[], int size) {
    srand(time(nullptr)); // Inicjalizacja generatora liczb losowych

    for (int i = 0; i < size; ++i) {
        t[i] = rand() % 9000 + 1000; // Losowanie liczby z zakresu 1000-9999
    }
}

int main() {
    const int size = 10; // Rozmiar tablicy
    int tablica[size]; // Deklaracja tablicy

    cout << "Tablica przed sortowaniem:" << endl;
    losuj_tablice(tablica, size); // Losowanie wartości
    for (int i = 0; i < size; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl << endl;

    // Rozpoczęcie liczenia czasu
    auto start = steady_clock::now();

    cout << "Sortowanie bąbelkowe:" << endl;
    sortowanie_babelkowe(tablica, size);
    auto end_bubble = steady_clock::now();
    duration<double> elapsed_seconds_bubble = end_bubble - start;
    cout << "Czas sortowania: " << elapsed_seconds_bubble.count() << " s" << endl;
    for (int i = 0; i < size; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl << endl;

    cout << "Sortowanie przez wstrząsanie:" << endl;
    losuj_tablice(tablica, size); // Przywrócenie losowej tablicy
    sortowanie_przez_wstrzasanie(tablica, size);
    auto end_shaker = steady_clock::now();
    duration<double> elapsed_seconds_shaker = end_shaker - end_bubble;
    cout << "Czas sortowania: " << elapsed_seconds_shaker.count() << " s" << endl;
    for (int i = 0; i < size; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl << endl;

    cout << "Sortowanie przez scalanie:" << endl;
    losuj_tablice(tablica, size); // Przywrócenie losowej tablicy
    sortowanie_przez_scalanie(tablica, size);
    auto end_merge = steady_clock::now();
    duration<double> elapsed_seconds_merge = end_merge - end_shaker;
    cout << "Czas sortowania: " << elapsed_seconds_merge.count() << " s" << endl;
    for (int i = 0; i < size; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl << endl;

    cout << "Sortowanie szybkie:" << endl;
    losuj_tablice(tablica, size); // Przywrócenie losowej tablicy
    sortowanie_szybkie(tablica, size);
    auto end_quick = steady_clock::now();
    duration<double> elapsed_seconds_quick = end_quick - end_merge;
    cout << "Czas sortowania: " << elapsed_seconds_quick.count() << " s" << endl;
    for (int i = 0; i < size; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl << endl;

    cout << "Sortowanie przez wstawianie:" << endl;
    losuj_tablice(tablica, size); // Przywrócenie losowej tablicy
    sortowanie_przez_wstawianie(tablica, size, nullptr);
    auto end_insertion = steady_clock::now();
    duration<double> elapsed_seconds_insertion = end_insertion - end_quick;
    cout << "Czas sortowania: " << elapsed_seconds_insertion.count() << " s" << endl;
    for (int i = 0; i < size; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    // Zakończenie liczenia czasu
    auto end = steady_clock::now();
    duration<double> elapsed_total_seconds = end - start;

    // Wyświetlenie czasu trwania sortowania
    cout << endl << "Całkowity czas sortowania: " << elapsed_total_seconds.count() << " s" << endl;

    return 0;
}