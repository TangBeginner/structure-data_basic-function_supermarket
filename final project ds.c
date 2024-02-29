#include <stdio.h>
#include <stdlib.h>

struct order{ 		//struct with typedef order
	int no;
	char name[20];
	float price;
	int date;
	int amount;
	
};

typedef struct order order;

struct data{		//struct with typedef data
	order id;
	struct data*next;
};

typedef struct data data;

data*begin=NULL,*tail,*temp;

int no;

void insertOrder();
void deleteOrder(int key);
void traverse();
void searchOrder();
void swap(data*a,data*b);
void bubblesort(struct data*begin);


int main()
{
    int choice;		//declare variable choice
    int num;		//declare variable num
    order record;	
    
    while(1)   		//while loop function
    {
    	printf("*******************");
		printf("\n|1. Store ORDER   |\n");    		 //insert function
	    printf("|2. Remove ORDER  |\n" );            //deleted function
	    printf("|3. Search ORDER  |\n" );            //searching function
	    printf("|4. Update LIST   |\n"  );           //sorting function
	    printf("|5. Display ORDER |\n");             //traverse function
	    printf("|6. Exit          |\n");
	    printf("*******************");
	    printf("\nPlease choose :" );
	    scanf("%d",&choice);						
	    
	    
        switch(choice){  				//switch function that used to execute the the statements with matched case
        case 1: 
        	printf("\nxxxxxxxxxxxxxxxxxxxxxxx\n");
        	printf("\tOrder \n");
        	printf("xxxxxxxxxxxxxxxxxxxxxxx\n");
            insertOrder();				//function call
            break;
        case 2:
        	printf("What order do you want to delete??\n");
			scanf("%d",&num);
            deleteOrder(num);			//function call insert
            break;
        case 3:
            searchOrder();				//function call search
            break;
        case 4:
            bubblesort(begin);			//function call sort
            break;
        case 5:
            traverse();					//function call traverse
            break;
        case 6:
            printf("Exiting");
        	return 0;
            break;

        default:							//which define the element other than integer between 1-6
            printf("Wrong choice, Please enter correct choice from 1 to 6 in the menu\n");
    }
    
}
}


//insert function
void insertOrder(){ 	
		struct data*temp=NULL;	//a pointer variable of data which equal to NULL
		temp=(struct data*)malloc(sizeof(struct data));	//allocated new memory
		order record;			//initialize record with struct with typedef order
		
		printf("\nOrder ID: ");
		scanf("%d",&record.no);
		printf("\n Name: ");
		scanf("%s",&record.name);
		printf("\n Amount:");
		scanf("%d",&record.amount);
		printf("\n Total price: RM ");
		scanf("%f",&record.price);
		printf("\n Date(Month):");
		scanf("\n%d",&record.date);
		
		temp->id=record;	//define the node inserted which is the data from struct 
		temp->next=begin;	//the next node insert will be the begin node again
		begin=temp;			
}

//delete function
void deleteOrder(int key)
{
	struct data *curr =begin;
	struct data *temp = curr->next;
	struct data *del;


	while(curr != NULL && temp->id.no != key){	
		
		if(curr->id.no == key)		//when temporary node is equal to the key which is insert by user
		{
		begin=begin ->next;		//the begin will be the next element
		printf("\n--Order is deleted successfully--\n");
		return;
		}
		
		curr=curr->next;
		temp = temp->next;
    }
    
    	if(temp->id.no == key){		//when temporary node is equal to the key which is insert by user
    	del=temp;					//the temporary node will be stated as the deleted element
    	curr->next=temp->next;		
   		free(del);					//delete the temporary node which maked as del
    	printf("\n--Order is deleted successfully--\n");
	}
}	





//search function
void searchOrder()
{
	order record;
	struct data *newPtr;
	
	int key;	//declare variable key which is the element insert by the user
	int y=0;	//declare varibale y and initialize it with 0
	newPtr=begin;
	printf("\nPlease enter the order id:");
	scanf("%d",&key);
	
	while(newPtr!=NULL)		//while loop the newPtr is not NULL(at the end)
	{
		if(key==newPtr->id.no)	//when the order id is same as key which is insert by the user
		{
			printf("\n\t --Order is found--\n");
			printf("\n\t --Record at order %d--\n",y);
			printf("Order %d: \n",no);
			printf("Oder ID: %d\n",newPtr->id.no);
			printf("Name: %s \n",newPtr->id.name);
			printf("Total price:RM %f \n",newPtr->id.price);
			printf("Date: %d \n",newPtr->id.date);
			printf("Amount: %d \n",newPtr->id.amount);
			break;
		}
		else
		{
			newPtr=newPtr->next; //newPtr will move from one node to other node 
			y++;	//y= index of element increase 
		}
	}
	
	if(newPtr==NULL) //when the newPtr is equal to NULL(at the end)
	{
		printf("\nThere are no order.\n");
	}
}





//bubble sort function
void bubblesort(struct data *begin)
{
	int swapped;	//declare variable swapped 
    struct data *currPtr;	
    struct data *tempPtr = NULL;
  
    // Checking for empty list 
    if (begin == NULL)
    {
    	printf("\nThere are no order\n");
        return;
	}
	
    printf("\nThe order is sort\n");
    do
    {
        swapped = 0;
        currPtr = begin;
  
        while (currPtr->next != tempPtr)	//while loop and the currPtr->nest is not equa to tempPtr
        {
            if(currPtr->id.no >currPtr->next->id.no)	//when the currPtr > currPtr->next
            { 
                swap(currPtr, currPtr->next);	//both element swap
                swapped = 1;
            }
            currPtr = currPtr->next; 	//the sequence for the next node
        }
        tempPtr = currPtr;
    }
    while (swapped);
	
}

//traverse function
void traverse()
{
	struct data*ptr;
	int no=0;		//declare the variable of no and initialize it with 0
		if(begin==NULL)		//when there is no node 
		{
		printf("\nThere are no order\n");
		}
		
		else
		{
			ptr=begin;		//the node is equal to begin
			printf("\n-------------------------------------------\n");
			while(ptr!=NULL)			//when there are node inside 
				{
					printf("\nOrder ID: %d\n",ptr->id.no);
					printf("Name: %s \n",ptr->id.name);
					printf("Total price: RM %.2f \n",ptr->id.price);
					printf("Date (month): %d \n",ptr->id.date);
					printf("Amount: %d \n",ptr->id.amount);
					printf("\n-------------------------------------------\n");
					ptr=ptr->next;		//continue running
					no++;	//the number will continue increase
				}
		}
}

// function to swap data of two nodes a and b
void swap(data *a, data *b)
{
    order temp = a->id;
    a->id = b->id;
    b->id = temp;
}
