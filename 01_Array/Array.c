#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int capacity;
    int lastIndex;
    int *ptr;
};

void createArray(struct Array *);
void append(struct Array *);
void insert(struct Array *);
void getItem(struct Array *);
void isEmpty(struct Array *);
void isFull(struct Array *);
void del(struct Array *);
void edit(struct Array *);
void count(struct Array *);
void getCapacity(struct Array *);
void showData(struct Array*);
void destroyArray(struct Array *);

int main(){
    struct Array arr;
    while(1){
        printf("\n1.Create Array\n");
        printf("2.Append an Element\n");
        printf("3.Insert an Element\n");
        printf("4.Get Element\n");
        printf("5.Check Empty\n");
        printf("6.Check Full\n");
        printf("7.Delete an Element\n");
        printf("8.Edit an Element\n");
        printf("9.Count number of element\n");
        printf("10.Get Capacity\n");
        printf("11.ShowData\n");
        printf("12.End the Program\n");
        printf("------------------\n");
        int choice;
        printf("\nEnter your Choice\t");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                createArray(&arr);
                break;
            case 2:
                append(&arr);
                break;
            case 3:
                insert(&arr);
                break;
            case 4:
                getItem(&arr);
                break;
            case 5:
                isEmpty(&arr);
                break;
            case 6:
                isFull(&arr);
                break;
            case 7:
                del(&arr);
                break;
            case 8:
                edit(&arr);
                break;
            case 9:
                count(&arr);
                break;
            case 10:
                getCapacity(&arr);
                break;
            case 11:
                showData(&arr);
                break;
            case 12: 
                destroyArray(&arr);
                break;
            default:
                printf("--INVALID CHOICE--\n");

        }
        if(choice==12)
         break;
    }
    return 0;
}

//Creating an array
void createArray(struct Array *arr){
    int cap;
    printf("Ente the Capacity of an Array\t");
    scanf("%d",&cap);
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=(int*)malloc(cap*(sizeof(int)));   
    printf("-----ARRAY CREATED SUCCESSFULLY------\n");
}

//appending an elemnt
void append(struct Array *arr){
    int ele;
    printf("Enter an Element\t");
    scanf("%d",&ele);
    if(arr->lastIndex+1<arr->capacity){
        arr->lastIndex++;
        arr->ptr[arr->lastIndex]=ele;
        printf("---------APPEND DONE------ \n");
    }
    else{
        printf("Overflow: Array is already full");
    }
}

//inserting an element
void insert(struct Array *arr){
    if(arr->lastIndex<arr->capacity-1){
        int ind;
        int element;
        printf("Enter the index\t");
        scanf("%d",&ind);
        printf("Enter the element\t");
            scanf("%d",&element);
        if(ind>=arr->capacity || ind<0){
            printf("---INDEX IS OUT OF BOUND---");
        }
        else if(ind>arr->lastIndex){
           arr->lastIndex++;
           arr->ptr[arr->lastIndex]=element;
        }
        else{
            int temp=arr->lastIndex;
            arr->lastIndex++;
            while(temp>=ind){
                arr->ptr[temp+1]=arr->ptr[temp];
                temp--;
            }
            arr->ptr[ind]=element;
            printf("---INSERTED SUCCESSFULLY---\n");
        }
    }
    else{
        printf("-- ARRAY IS FULL: CAN'T BE INSERTED--\n");
    }
    
    
}

//getting an element
void getItem(struct Array *arr){
    int index;
    printf("Enter Index\t");
    scanf("%d",&index);
    if(index<0 || index>arr->lastIndex){
        printf("---INVALID INDEX---\n");
    }
    else{
        printf("Element at %d index is %d",index,arr->ptr[index]);
    }
}

void isEmpty(struct Array *arr){
    if(arr->lastIndex==-1){
        printf("--ARRAY IS EMPTY---\n");
    }
    else
        printf("--ARRAY IS NOT EMPTY---\n");
}
void isFull(struct Array *arr){
    if(arr->lastIndex==arr->capacity-1)
        printf("--ARRAY IS FULL---\n");
    else
        printf("--ARRAY IS NOT FULL--\n");
}

void del(struct Array *arr){
    int index;
    printf("Enter the index\t");
    scanf("%d",&index);
    if(index<0 || index>arr->lastIndex){
        printf("--INVALID INDEX--\n");
    }
    else{
        while(index<arr->lastIndex){
            arr->ptr[index]=arr->ptr[index+1];
        }
        arr->lastIndex--;
        printf("---DELETED SUCCESSFULLY---\n");
    }
}

void edit(struct Array *arr){
    int index,elem;
    printf("Enter index\t");
    scanf("%d",&index);
    if(index<0 || index>arr->lastIndex){
        printf("---ENTER VALID INDEX----\n");
        edit(arr);
    }
    else{
        printf("Enter Element\t");
        scanf("%d",&elem);
        arr->ptr[index]=elem;
        printf("--EDITED SUCCESSFUL--\n");
        return ;
    }

}

void count(struct Array *arr){
    printf("--THE NUMBER OF ELEMENTS = %d",arr->lastIndex+1);
}

void getCapacity(struct Array *arr){
    printf("--THE CAPACITY OF THE ARRAY = %d",arr->capacity);
}

void destroyArray(struct Array *arr){
    free(arr->ptr);
    arr->ptr=NULL;
    arr->capacity=0;
    arr->lastIndex=-1;
}
//showing data
void showData(struct Array *arr){
    if(arr->lastIndex==-1){
        printf("---EMPTY ARRAY---\n");
    }
    else{
        for(int i=0;i<=arr->lastIndex;i++){
        printf("%d  ",arr->ptr[i]);
       }
    }
    printf("\n-----ARRAY PRINTED SUCCESSFULY------\n");
   
}
