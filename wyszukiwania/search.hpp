#ifndef SEARCH_HPP
#define SEARCH_HPP

// Deklaracje funkcji wyszukiwania

int liniowe_wyszukiwanie(int *t, int size, int key);
int liniowe_wyszukiwanie_z_wartownikiem(int t[], int size, int key);
int wyszukiwanie_skokowe(int t[], int size, int key);
int wyszukiwanie_binarne(int t[], int size, int key);
int wyszukiwanie_interpolacyjne(int t[], int size, int key);

#endif