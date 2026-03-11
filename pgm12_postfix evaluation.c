//POSTFIX EVALUATION
#include <stdio.h>
void push(int item);
int pop();
int evaluatePostfix(char postfix[]);
int top = -1;
int stack[20];
void main()
{
int size;
printf("Enter the size of the expression: ");
scanf("%d", &size);

char postfix[size + 1];

printf("Enter the postfix expression: ");
scanf("%s", postfix);

int result = evaluatePostfix(postfix);
printf("Result of Postfix Evaluation: %d\n", result);
}

void push(int item)
{
top++;
stack[top] = item;
}
int pop()
{
int item = stack[top];
top--;
return item;
}
int evaluatePostfix(char postfix[])
{
int i = 0;
char item;
int a, b, val;
while (postfix[i] !='\0')
{
item = postfix[i];
if (item >= '0' && item <= '9')
{
push(item - '0');
}
else
{
a = pop();
b = pop();
if(item=='+')
val=(b+a);
else if(item=='-')
val=(b-a);
else if (item == '*')
val=(b*a);
else if(item=='/')
val=b/a;
push(val);
}
i++;
}
return pop();
}

/*OUTPUT:

Enter the size of the expression: 7
Enter the postfix expression: 23+51-*
Result of Postfix Evaluation: 20
*/