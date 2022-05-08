/**     Abdelrahman ahmed ragab   **/
/*   Implement stack Linked based   */

#include <stdio.h>
#include <stdlib.h>

typedef char Data_Type;

typedef struct stackNode
{
    Data_Type Data;
    struct stackNode * Nextptr;

}StackNode;

typedef struct stack
{
    StackNode * Top;
    int SizeOfStack;
}Stack;

void Stack_init(Stack *stackptr);
void Push_instack(Data_Type elment , Stack *stackptr );
void Pop_fromstack(Stack *stackptr , Data_Type *Poped_value);
int stack_isfull(Stack *stackptr );
int stack_isempty(Stack *stackptr );
void Print_StackElements(Stack *stackptr );
void GetStack_size(Stack *stackptr ,int *Size_value);
void ReturnStack_Topvalue(Stack *stackptr ,Data_Type *Returned_Topvalue);
void Clearto_Stack(Stack *stackptr );



int main()
{
    Stack sab;
    Stack_init(&sab);
    Push_instack(5 , &sab);
    Push_instack(12 , &sab);
    Push_instack(4 , &sab);
    int tmp;
    GetStack_size(&sab , &tmp);
    printf("Size of stack is \t %d \n" , tmp);
    Print_StackElements(&sab);
    tmp;
    Pop_fromstack(&sab , &tmp);
    printf("Pop of stack is %d\n" , tmp);
    Pop_fromstack(&sab , &tmp);
    printf("Pop of stack is %d\n" ,tmp);
    GetStack_size(&sab , &tmp);
    printf("Size of stack is %d\n" , tmp);
    Print_StackElements(&sab);
    Clearto_Stack(&sab);
    GetStack_size(&sab , &tmp);
    printf("Size of stack is %d\n" , tmp);
    Print_StackElements(&sab);
    
    return 0;
}

void Stack_init(Stack *stackptr)
{
    stackptr->Top = NULL;
    stackptr->SizeOfStack = 0;
}
void Push_instack(Data_Type elment , Stack *stackptr )
{
    StackNode *ptr = (StackNode *)malloc(sizeof(StackNode));
    ptr->Data = elment;
    ptr->Nextptr = stackptr->Top;
    stackptr->Top = ptr;
    stackptr->SizeOfStack++;

}
void Pop_fromstack(Stack *stackptr , Data_Type *Poped_value)
{
    
    
    if(!stack_isempty(stackptr ))
    {
        StackNode *popptr = (StackNode *)malloc(sizeof(StackNode));
        *Poped_value = stackptr->Top->Data;
        popptr->Nextptr = stackptr->Top;
        stackptr->Top = stackptr->Top->Nextptr;
        free(popptr);
        stackptr->SizeOfStack--;
    }
    else
    {
        printf("Stack is empty");
    }
 


}
int stack_isfull(Stack *stackptr )
{
    return 0;
}
int stack_isempty(Stack *stackptr )
{
    return (stackptr->Top == NULL);
}
void Print_StackElements(Stack *stackptr )
{
    StackNode *New_top;
    New_top = stackptr->Top;

        
    if(!stack_isempty(stackptr ))
    {
        for(int i=0 ;New_top != NULL ;  i++)
        {
            printf("Stack element number %d is %d\n" , i+1 , New_top->Data);
            New_top = New_top->Nextptr;
        }
       
        
    }
    else
    {
        printf("Stack has no elements to print \n");
    }
    

}
void GetStack_size(Stack *stackptr ,int *Size_value)
{
    *Size_value = stackptr->SizeOfStack;
}
void ReturnStack_Topvalue(Stack *stackptr ,Data_Type *Returned_Topvalue)
{
    *Returned_Topvalue = stackptr->Top->Data;
}
void Clearto_Stack(Stack *stackptr )
{
    if(!stack_isempty(stackptr ))
    {
        
        while (stackptr->Top != NULL)
        {
            StackNode *popptr = (StackNode *)malloc(sizeof(StackNode));
            popptr->Nextptr = stackptr->Top;
            stackptr->Top = stackptr->Top->Nextptr;
            free(popptr);
            stackptr->SizeOfStack--;
        }
        
        
    }
    else
    {
        printf("Stack is empty");
    }
}
