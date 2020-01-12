// 优先级队列，按优先级从高向低
#include <stdio.h>
#include <stdlib.h>
#define DATATYPE int

// 优先级队列数据元素
typedef struct element{
	DATATYPE data;
	int priority;
}element;

// 优先级队列
typedef struct PriorityQueue{
	element *unit;

	// 实际元素个数
	int size;
	// 总容量
	int capacity;
}PriorityQueue;

// 向上调整,position表示当前调整开始的位置,范围是 0 ~ size - 1
void adjustUp(PriorityQueue *queue,int position){
	if(queue == NULL || position <= 0)
		return;
	int tempPriority = queue->unit[position].priority;
	DATATYPE tempData = queue->unit[position].data;

	for(int i = (position + 1) / 2 - 1;i >= 0;i = (i + 1) / 2 -1){
		if(queue->unit[i].priority > tempPriority)
			return;
		queue->unit[position].priority = queue->unit[i].priority;
		queue->unit[position].data = queue->unit[i].data;
		position = i;
	}
	queue->unit[position].priority = tempPriority;
	queue->unit[position].data = tempData;
}

// 向下调整,position表示当前调整开始的位置,范围是 0 ~ size - 1
void adjustDown(PriorityQueue *queue,int position,int size){
	if(queue == NULL || position < 0 || position >= size)
		return;
	int tempPriority = queue->unit[position].priority;
	DATATYPE tempData = queue->unit[position].data;
	for(int i = 2 * position + 1;i < size;i = i * 2 + 1){
		if(i + 1 < size && queue->unit[i].priority < queue->unit[i+1].priority)
			i++;
		if(queue->unit[i].priority > tempPriority){
			queue->unit[position].priority = queue->unit[i].priority;
			queue->unit[position].data = queue->unit[i].data;
			position = i;
		}
	}
	queue->unit[position].data = tempData;
	queue->unit[position].priority = tempPriority;

}

// 优先级队列初始化
PriorityQueue* initialize(int size){
	if(size <= 0)
		return NULL;
	PriorityQueue *queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	if(queue == NULL)
		printf("初始化优先级队列错误\n");
	queue->size = 0;
	queue->capacity = size;
	queue->unit = (element*)malloc(sizeof(element) * size);
	if(queue->unit == NULL){
		printf("初始化优先级队列错误\n");
		free(queue);
		return NULL;
	}
	return queue;

}

// 销毁优先级队列
void destroy(PriorityQueue *queue){
	if(queue == NULL)
		return;

	free(queue->unit);
	free(queue);

	queue = NULL;
}

// 插入新元素
int insert(PriorityQueue *queue,int priority,DATATYPE data){

	if(queue == NULL || queue->size == queue->capacity){
		printf("插入失败\n");
		return 0;
	}

	element *ele = (element*)malloc(sizeof(element));
	if(ele == NULL){
		printf("插入失败\n");
		return 0;
	}

	// 插入队列
	++(queue->size);
	queue->unit[queue->size - 1].priority = priority;
	queue->unit[queue->size - 1].data = data;
	// 重新调整为大顶堆
	adjustUp(queue,queue->size - 1);
	return 1;
}

// 获取优先级最高的元素
element* getHighest(PriorityQueue *queue){
	if(queue == NULL || queue->size == 0){
		printf("优先级队列为空\n");
		return NULL;
	}
	return &(queue->unit[0]);
}

// 删除优先级最高的元素
void deleteHighest(PriorityQueue *queue){
	if(queue == NULL || queue->size == 0){
		printf("优先级队列为空\n");
	}

	// 将堆顶元素交换到末尾
	queue->unit[0].priority = queue->unit[queue->size - 1].priority;
	queue->unit[0].data = queue->unit[queue->size - 1].data;
	queue->unit[queue->size - 1].priority = -2147483648;
	queue->unit[queue->size - 1].data = -2147483648;

	// 重新调整前面的元素
	adjustDown(queue,0,--(queue->size));
}

int main(){
	int count;
	printf("优先级队列元素个数:\n");
	scanf("%d",&count);
	if(count <= 0)
		return 0;
	PriorityQueue *queue = initialize(count);
	int tempPriority;
	int tempData;
	for(int i = 0;i < count;i++){
		printf("输入第%d个数据、优先级:\n",i+1);
		scanf("%d %d",&tempData,&tempPriority);
		insert(queue,tempPriority,tempData);
	}

	printf("删除前\n");
	for(int i = 0;i < queue->size ;i++){
		printf("%d %d\n",(queue->unit[i].data),(queue->unit[i].priority));
	}
	deleteHighest(queue);

	printf("删除后\n");
	for(int i = 0;i < queue->size;i++){
		printf("%d %d\n",(queue->unit[i].data),(queue->unit[i].priority));
	}

	return 0;
}




