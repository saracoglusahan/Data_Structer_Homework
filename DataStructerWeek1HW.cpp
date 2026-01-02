#include <stdlib.h>
#include <stdio.h>

static int arrayLenght;

void delete_Element(int *array,int location);
void print_an_Element(int *array,int location);
int* insert_an_Element(int *array,int value);
void print_all_the_List(int *array);
void reverseOfArray(int *array);

int main(){
	

	int location;;
	printf("Arrayinizin uzunlugu ne kadar olacak: ");
	scanf("%d",&arrayLenght);
	
	int *array = (int *) malloc(arrayLenght * sizeof(int));
	
	if (array == NULL)
	{
		printf("Allocation was failed!");
		return 0;
	}
	
	int *c = array;
	int value = 0;
	for (int i = 0; i<arrayLenght;i++)
	{
		printf("Sign the %d. index: ",i);
		scanf("%d",&value);
		*c = value;
		c++;
	}
	
	printf("List was created!");
	
	printf("\n\n");
	
	while (1)
	{
		int operation;
		printf("*****************************\n");
		printf("Array Operations System\n");
		printf("1 - Add value to Array\n");
		printf("2 - Delete value from Array\n");
		printf("3 - Print an Element\n");
		printf("4 - Print the Array\n");
		printf("5 - Reverse of Array\n");
		printf("0 - Exit\n");
		printf("Chose the operation: ");
		scanf("%d",&operation);
		
		switch (operation)
		{
			case 0:
				printf("Closing...");
				return 0;
				break;
			case 1:
				int value;
				printf("What's your value: ");
				scanf("%d",&value);
				array = insert_an_Element(array,value);
				printf("Addition is Succeed!\n");
				break;
			case 2:
				printf("Which location will you delete it (index): ");
				scanf("%d",&location);
				delete_Element(array,location);
				printf("Deleted who given the location by user!\n");
				break;
			case 3:
				printf("Location (index): ");
				scanf("%d",&location);
				print_an_Element(array,location);
				break;
			case 4: 
				print_all_the_List(array);
				break;
			case 5:
				reverseOfArray(array);
				break;
		}
	}
	
	
	
	return 0;
}




void delete_Element(int *array,int location)
{
	if (array == NULL) return;
	
    if (location < 0 || location >= arrayLenght) {
        printf("Invalid index!\n");
        return;
    }
	int *c = array;
	int i = 0;
	for (int l = 0; l < location;l++){c++;}
	
	for (int l = location; l < arrayLenght - 1; l++)
	{
		*c = *(c + 1);
        c++;
	}
	array[arrayLenght - 1] = 0;
	arrayLenght--;
}


void print_an_Element(int *array,int location)
{
	if(array == NULL) return;
	
	if (location < 0 || location >= arrayLenght) {
        printf("Invalid index!\n");
        return;
    }
    
	int *c = array;
	int i = 0;
	while (i < arrayLenght)
	{
		if (i == location){
			printf("Value is: %d\n",*c); 
			return;
		}
		c++;i++;
	}
}

void print_all_the_List(int *array)
{
	int *c = array;
	int i = 0;
	while (i < arrayLenght)
	{
		printf("%d ",*c++);
		i++;
	}
	printf("\n\n");
}


int* insert_an_Element(int *array,int value)
{
	int *array2;
	array2 = (int *) realloc(array,(arrayLenght+1) * sizeof(int));
	
	if (array2 == NULL) {printf("Your list didn't create!"); return array;}
	array = array2;
	
	int* c = array + arrayLenght;
	*c = value;
	arrayLenght++;
	return array;
}

void reverseOfArray(int *array)
{
	if (array == NULL) {
        printf("Array is empty or not allocated!\n");
        return;
    }
    
    if (arrayLenght <= 0) {return;}
    
	int *c = array + (arrayLenght -1); 
	
	for (int i = arrayLenght-1; i >= 0; i--)
	{
		printf("%d ",*c);
		c--;
	}
	printf("\n");
}


