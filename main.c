#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* sleep_sort(void *arg) {
    unsigned int *arg_ = (unsigned int *) arg;
    sleep(*arg_);
    printf("%u\n", *arg_);
    return NULL;
}

int main(int argc, char *argv[]) {
    /*请输入五个非负整数*/
    const int size = 5;
    pthread_t p[size];
    unsigned int n[size];
    for (int i = 0; i < size; i++) {
        scanf("%u", &n[i]);
    }
    for (int i = 0; i < size; i++) {
        pthread_create(&p[i], NULL, sleep_sort, &n[i]);
    }
    for (int i = 0; i < size; i++) {
        pthread_join(p[i], (void **)NULL);
    }
    return 0;
}