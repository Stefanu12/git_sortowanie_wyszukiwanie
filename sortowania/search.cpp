#include "search.hpp"


void sortowanie_babelkowe(int t[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (t[j] > t[j + 1]) {
                int temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

void sortowanie_przez_wstrzasanie(int t[], int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (t[i] > t[i + 1]) {
                int temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (t[i] > t[i + 1]) {
                int temp = t[i];
                t[i] = t[i + 1];
                t[i + 1] = temp;
                swapped = true;
            }
        }

        ++start;
    }
}

void sortowanie_przez_scalanie(int t[], int size) {
    if (size <= 1) return;

    int mid = size / 2;
    int* left = new int[mid];
    int* right = new int[size - mid];

    for (int i = 0; i < mid; ++i) {
        left[i] = t[i];
    }
    for (int i = mid; i < size; ++i) {
        right[i - mid] = t[i];
    }

    sortowanie_przez_scalanie(left, mid);
    sortowanie_przez_scalanie(right, size - mid);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < (size - mid)) {
        if (left[i] <= right[j]) {
            t[k++] = left[i++];
        } else {
            t[k++] = right[j++];
        }
    }
    while (i < mid) {
        t[k++] = left[i++];
    }
    while (j < (size - mid)) {
        t[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void sortowanie_szybkie(int t[], int size) {
    if (size <= 1) return;

    int pivot = t[size / 2];
    int i = 0, j = size - 1;

    while (i <= j) {
        while (t[i] < pivot) ++i;
        while (t[j] > pivot) --j;

        if (i <= j) {
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
            ++i;
            --j;
        }
    }

    if (j > 0) sortowanie_szybkie(t, j + 1);
    if (i < size) sortowanie_szybkie(t + i, size - i);
}

void sortowanie_przez_wstawianie(int t[], int size, int t_out[]) {
    for (int i = 1; i < size; ++i) {
        int key = t[i];
        int j = i - 1;

        while (j >= 0 && t[j] > key) {
            t[j + 1] = t[j];
            --j;
        }
        t[j + 1] = key;
    }
}