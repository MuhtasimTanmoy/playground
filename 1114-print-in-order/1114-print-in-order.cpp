#include <semaphore.h>

class Foo {

protected:
    sem_t firstJobDone;
    sem_t secondJobDone;

public:

    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first".
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second".
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third".
        printThird();
    }
};