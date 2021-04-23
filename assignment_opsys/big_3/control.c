#include "producer_and_consumer.c"
int main(int argc, char *argv[])
{
	para p;
	int time, p_total, c_total;
	if (argc < 3) {

		printf("Missing parameter!\n");
		return 0;
	}
	time = atoi(argv[1]);
	p_total = atoi(argv[2]);
	c_total = atoi(argv[3]);
	int ptr = 0;//初始化结构体
	p.ptr = &ptr;
	p.time = &time;

	pthread_t array_producer[p_total];
	pthread_t array_consumer[c_total];
	//printf("%d %d %d", time, p_total, c_total);
	pthread_mutex_init(&mutex, NULL);//初始化互斥信号量
	sem_init(&empty, 0, BUFFER_SIZE);//初始化同步信号量
	sem_init(&full, 0, 0);//初始化同步信号量

	//创建生产者线程
	for (int i = 0; i < p_total; i++) {

		if (pthread_create(&array_producer[i], NULL, producer,(void *)&p)) {
			printf("Create producer pthread fail\n");
		}
	}

	//创建消费者线程	
	for (int i = 0; i < c_total; i++) {

		if (pthread_create(&array_consumer[i], NULL, consumer, (void *)&p)) {
			printf("Create consumer pthread fail\n");
		}
	}

	sleep(time);
	for (int i = 0; i < p_total; i++) pthread_cancel(array_producer[i]);
	for (int i = 0; i < c_total; i++) pthread_cancel(array_consumer[i]);
	exit(0);
	return 0;
}
