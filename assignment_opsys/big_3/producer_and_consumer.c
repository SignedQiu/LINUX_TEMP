#include "buffer.c"

buffer_item buffer[BUFFER_SIZE];//创建缓冲区

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *p)
{
	buffer_item rand_temp;

	para *tmp;
	tmp = (para*)p;

	int *t = tmp->time;
	int *ptr = tmp->ptr;
	int rand_time;

	while (1) {

		rand_time = rand();
		sleep(rand_time % (*t));
		rand_temp = rand();
		printf("Producer produced %d\n", rand_temp);
	
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);

		if (insert_item(rand_temp, buffer, ptr))
			printf("report error condition\n");
		else
			printf("Producer put %d into buffer\n", rand_temp);

		pthread_mutex_unlock(&mutex);
		sem_post(&full);

		printf("producer ptr=%d\n", *ptr);
	}

}

void *consumer(void *p)
{
	buffer_item rand_temp;
	
	para *tmp;
	tmp = (para*)p;
	int *t = tmp->time;
	int *ptr = tmp->ptr;
	int rand_time;

	while (1) {

		rand_time = rand();
		sleep(rand_time % (*t));

		sem_wait(&full);
		pthread_mutex_lock(&mutex);

		if (remove_item(&rand_temp, buffer, ptr))
			printf("report error condition\n");
		else
			printf("Consumer consumed %d\n", rand_temp);

		pthread_mutex_unlock(&mutex);
		sem_post(&empty);

		printf("consumer ptr=%d\n", *ptr);
	}
}
