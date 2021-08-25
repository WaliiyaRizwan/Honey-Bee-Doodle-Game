#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int status = 0;
void *print_child(void *arg)
{
    printf("child thread\n");

}

int main()
{
    pthread_t child;
    for (int i=0; i<11; i++){
    pthread_create(&child, NULL, &print_child, NULL);
     }

    printf("parent thread\n");
    status++;
    if (pthread_join(child, NULL))
    {
      printf("ERROR");
        exit(1);
    }

    return 0;
}
