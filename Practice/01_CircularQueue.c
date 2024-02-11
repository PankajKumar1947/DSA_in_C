#include<stdio.h>
int choice=0;
int n;
int queue[100];
int rear=-1,front=-1;

//Function Declarations:
void Push();
void Pop();
void getBack();
void getFront();
int isEmpty();
int isFull();

int main(){
    printf("Enter the number of elements in the Queue ");   
    scanf("%d",&n);  
    printf("*********Queue operations using array*********");  
  
    printf("\n----------------------------------------------\n");  
    while(1)  
    {  
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Back\n4.Front\n5.Empty\n6.Full\n7.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                Push();  
                break;  
            }  
            case 2:  
            {  
                Pop();  
                break;  
            }  
            case 3:  
            {  
                getBack();  
                break;  
            }  
            case 4:
            {
                getFront();
                break;
            }
            case 5:
            {
                if(isEmpty())
                    printf("QUEUE IS EMPTY\n");
                else
                    printf("QUEUE IS NOT EMPTY\n");
                break;
            }
            case 6:
            {
                if(isFull())
                    printf("QUEUE IS FULL\n");
                else
                    printf("QUEUE IS NOT FULL\n");
                    break;
            }
            case 7:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
        if(choice==7){
            printf("\n------------------ Exited ! ----------------------");
            break;
        }
    }  
    return 0;
}

void Push(){

    int data;
    printf("Enter a data to be inserted\n");
    scanf("%d",&data);

    if(n<=0)
        printf("INVALID SIZE OF QUEUE\n");
    else if(isFull())
        printf("QUEUE IS ALREADY FULL\n");

    else if(rear==-1)//queue is empty
    {
        rear=front=0;
        queue[rear]=data;
    }
    else if(rear==n-1)// if queue is empty that the concept of circular queue
    {
        rear=0;
        queue[rear]=data;
    } 
    else{
        rear++;
        queue[rear]=data;
    }
}

void Pop(){
    if(isEmpty())
        printf("QUEUE IS EMPTY\n");
    else if(rear==front){
        rear=front=-1;
    }
    else if(front==n-1)//if element to be deleted is at last index.
        front=0;
    else
        front++;
}

void getBack(){
    if(isEmpty()){
        printf("ARRAY IS EMPTY\n");
    }
    else{
        printf("The REAR or BACK element is %d\n",queue[rear]);
    }
}

void getFront(){
    if(isEmpty())
        printf("ARRAY IS EMPTY\n");
    else
        printf("The FRONT element is %d\n",queue[front]);
}

int isEmpty(){
    if(rear==-1)
        return 1;
    return 0;
}

int isFull(){
    if(rear==n-1)
        return 1;
    else
        return 0;
}