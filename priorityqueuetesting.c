#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int ele)
{
	if(rear==MAX-1)
	{
		printf("QUEUE is full (OVERFLOW)");
	}
	else if((front == -1) && (rear == -1))
	{
		front = rear = 0;
		queue[rear] = ele;
	}
	else
	{
		rear++;
		queue[rear] = ele;
		//sorting the queue in descening order so that highest element will be in front position.
		int i, j, temp;
		for(i=0; i<=rear; i++)
		{
			for(j=0; j<rear; j++)
			{
				if(queue[i]>queue[j])
				{
					temp = queue[i];
					queue[i] = queue[j];
					queue[j] = temp; 
				}
			}
			
		}
	}
}
void dequeue()
{
	if((front == -1) && (rear == -1))
	{
		printf("QUEUE is empty (UNDERFLOW)");
	}
	else if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		printf("ELEMENT DELETED");
		queue[front++];
	}
}
void display()
{
	int i;
	if((front == -1) && (rear == -1))
	{
		printf("QUEUE is empty (UNDERFLOW)");
	}
	else
	{
		printf("QUEUE ELEMENTS:- \n");
		for(i=front;i<=rear;i++)
		{
			printf("%d ", queue[i]);
		}
	}
	
}
void peak()
{
	if((front == -1) && (rear == -1))
	{
		printf("QUEUE is empty (UNDERFLOW)");
	}
	else
	{
		printf("Element at top is %d", queue[front]);
	}
}
int main()
{
	int choice, ele;
	while(1)
	{
	printf("\n___________________________________________________________________\n");
	printf("\n<<<<QUEUE IMPLIMENTATION USING ARRAY>>>>\n");
	printf("Enter\n1 for ENQUEUE\n2 for DEQUEUE\n3 for DISPLAY\n4 for PEAK ELEMENT\n5 for EXIT\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("Enter element to add: ");
			scanf("%d", &ele);
			enqueue(ele);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			peak();
			break;
		case 5:
			exit(1);
			break;
		default:
			printf("INVALID CHOICE");
	}
	}
	return 0;
}
