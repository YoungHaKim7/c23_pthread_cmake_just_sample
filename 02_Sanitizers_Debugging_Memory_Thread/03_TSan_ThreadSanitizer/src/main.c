#include <pthread.h>
#include <stdio.h>

static int counter = 0; // ❌ shared without synchronization

void* worker(void* arg)
{
    int id = *(int*)arg; // use the parameter
    for (int i = 0; i < 1000000; i++) {
        counter++; // data race
    }
    printf("Thread %d done \n", id);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, worker, &id1);
    pthread_create(&t2, NULL, worker, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter = %d\n", counter);
    return 0;
}
