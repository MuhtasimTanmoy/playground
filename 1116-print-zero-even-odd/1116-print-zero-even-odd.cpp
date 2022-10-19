#include<semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t allowEven;
    sem_t allowOdd;
    sem_t allowZero;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&allowEven, 0, 0);
        sem_init(&allowOdd, 0, 0);
        sem_init(&allowZero, 0, 1);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            sem_wait(&allowZero);
            printNumber(0);
            if (i & 1) sem_post(&allowEven);
            else sem_post(&allowOdd);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&allowEven);
            printNumber(i);
            sem_post(&allowZero);
        }
    }

    void odd(function<void(int)> printNumber) {
         for (int i = 1; i <= n; i += 2) {
            sem_wait(&allowOdd);
            printNumber(i);
            sem_post(&allowZero);
        }
    }
};