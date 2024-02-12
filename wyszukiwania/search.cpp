#include "search.hpp"
#include <cmath> 
using namespace std;

int liniowe_wyszukiwanie(int t[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (t[i] == key) {
            return i;
        }
    }
    return -1;
}


int liniowe_wyszukiwanie_z_wartownikiem(int *t, int size, int key) {
    int i = 0;
    t[size] = key;
    while (t[i] != key) {
        ++i;
    }
    if (i < size) {
        return i;
    } else {
        return -1;
    }
}

int wyszukiwanie_skokowe(int t[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;
    while (t[min(step, size) - 1] < key) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    while (t[prev] < key) {
        ++prev;
        if (prev == std::min(step, size)) {
            return -1;
        }
    }
    if (t[prev] == key) {
        return prev;
    }
    return -1;
}

int wyszukiwanie_binarne(int t[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (t[mid] == key) {
            return mid;
        }
        if (t[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int wyszukiwanie_interpolacyjne(int t[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right && key >= t[left] && key <= t[right]) {
        int pos = left + ((key - t[left]) * (right - left) / (t[right] - t[left]));
        if (t[pos] == key) {
            return pos;
        }
        if (t[pos] < key) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}