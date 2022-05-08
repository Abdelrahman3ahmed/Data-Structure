/**     Abdelrahman ahmed ragab   **/
/*   Implement stack array based   */
/*   Reverse Task and Balanced Task*/


#include <stdio.h>
#include <stdlib.h>


#define sizeof_array 100

typedef char Data_Type;
 

//Declare struct of the stack
typedef struct stack
{
   int top;
   Data_Type array[sizeof_array];
}Stack;

void Stack_init(Stack *stackptr);
void Push_instack(Data_Type elment , Stack *stackptr );
Data_Type Pop_fromstack(Stack *stackptr );
int stack_isfull(Stack *stackptr );
int stack_isempty(Stack *stackptr );
void Print_StackElements(Stack *stackptr );
int GetStack_size(Stack *stackptr );
Data_Type ReturnStack_Topvalue(Stack *stackptr );
void Reverse_Name(Data_Type * name);
void Balanced_Parences(Data_Type * StrBla);

int main()
{
    //Test Stack
    /*Stack sab;
    Stack_init(&sab);
    Push_instack(5 , &sab);
    Push_instack(12 , &sab);
    Push_instack(4 , &sab);
    printf("Size of stack is \t %d \n" , GetStack_size(&sab));
    Print_StackElements(&sab);
    
    printf("Pop of stack is %d\n" , Pop_fromstack(&sab));
    printf("Pop of stack is %d\n" , Pop_fromstack(&sab));
    printf("Size of stack is %d\n" , GetStack_size(&sab));
    Print_StackElements(&sab);*/
    //Test Reverse Function
    /*char arr[20] = "abdelrahman";
    Reverse_Name(arr);
    int i=0;
    printf("Name : ");
    while (arr[i] != '\0') {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n \n");*/

    //Test Balanced Function
    char par[20] = "{{[[(())]]}}";
    Balanced_Parences(par);
    
    

    return 0;
}
void Stack_init(Stack *stackptr)
{
    stackptr->top = -1;
}
void Push_instack(Data_Type elment , Stack *stackptr )
{
    if(stack_isfull(stackptr))
    {
        printf("Stack is already full \n");
    }
    else
    {
        stackptr->top++;
        stackptr->array[stackptr->top] = elment;
    }
}
Data_Type Pop_fromstack(Stack *stackptr )
{
    if(!stack_isempty)
    {
        printf("Stack is empty  \n");
    }
    else
    {
        stackptr->top--;
        return stackptr->array[stackptr->top+1];
    }
}
int stack_isfull(Stack *stackptr )
{
    return (stackptr->top == (sizeof_array-1));
}
int stack_isempty(Stack *stackptr )
{
    return (stackptr->top == -1);
}

void Print_StackElements(Stack *stackptr )
{
    if(!stack_isempty)
    {
        printf("Stack has no elements to print \n");
    }
    else
    {
        for(int i=stackptr->top ; i>=0 ;i--)
        {
            printf("Stack element number %d is %d\n" , i+1 , stackptr->array[i]);
        }
    }
}
int GetStack_size(Stack *stackptr )
{
    return stackptr->top+1;
}
Data_Type ReturnStack_Topvalue(Stack *stackptr )
{
    return stackptr->array[stackptr->top];
}
void Reverse_Name(Data_Type * name)
{
    Stack Rev_Sta;
    Stack_init(&Rev_Sta);
    int i=0;
    
    while (name[i] != '\0')
    {
        Push_instack(name[i] , &Rev_Sta);
        i++;
    }
    i=0;
    while (!stack_isempty(&Rev_Sta))
    {
        name[i] = Pop_fromstack(&Rev_Sta );
        i++;
    }
    

}
void Balanced_Parences(Data_Type * StrBla)
{
    Stack Rev_Sta;
    Stack_init(&Rev_Sta);
    int i=0 , push_count =0 ,pop_count=0;
    
    while (StrBla[i] != '\0')
    {
        if((StrBla[i] == '(') || (StrBla[i] == '{') || (StrBla[i] == '['))
        {
            Push_instack(StrBla[i] , &Rev_Sta);
            push_count++;

        }
        
        if((StrBla[i] == ')' && ReturnStack_Topvalue(&Rev_Sta) == '(') || 
        (StrBla[i] == '}' && ReturnStack_Topvalue(&Rev_Sta) == '{') ||
        (StrBla[i] == ']' && ReturnStack_Topvalue(&Rev_Sta) == '['))
        {
            Pop_fromstack(&Rev_Sta );
            
        }
        i++;
        
    }
    pop_count = i-push_count;
    if(stack_isempty(&Rev_Sta) && (push_count == pop_count))
    {
        printf("Congratulations It is BALANCED");
    }
    else
    {
        printf("Oops NOT BALANCED");
    }

    
}
