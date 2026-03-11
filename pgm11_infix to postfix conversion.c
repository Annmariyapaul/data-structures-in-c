//INFIX TO POSTFIX CONVERSION
#include <stdio.h>
#include <string.h>
void push(char item);
char pop();
void convert(char infix[], char postfix[]);
int top = -1;
char stack[20];
void main()
{
int size;
printf("Enter the size of the expression: ");
scanf("%d", &size);

char infix[size + 1], postfix[size + 1];

printf("Enter the infix expression: ");
scanf("%s", infix);

convert(infix, postfix);

printf("Postfix Expression: %s\n", postfix);
}

void push(char item)
{
top++;
stack[top] = item;
}

char pop()
{
char item = stack[top];
top--;
return item;
}

void convert(char infix[], char postfix[])
{
int i = 0;
int j = 0;
char item;
push('(');
strcat(infix, ")");
while (infix[i] != '\0')
{
item = infix[i];
if ((item >= 'A' && item <= 'Z') || (item >= 'a' && item <= 'z') || (item >= '0' && item <= '9'))
{
postfix[j] = item;
j++;
}
else if (item == '(')
{
push(item);
}
else if (item == ')')
{
while (stack[top] != '(')
{
postfix[j] = pop();
j++;
}
pop();
}
else
{
while (stack[top] != '(' && (stack[top] == '*' || stack[top] == '/' || (stack[top] == '+' && (item == '+' || item == '-')) || (stack[top] == '-' && (item == '+' || item == '-'))))
{
postfix[j] = pop();
j++;
}
push(item);
}
i++;
}
postfix[j] = '\0';
}

/*OUTPUT:

Enter the size of the expression: 11
Enter the infix expression: (a+b)*(c-d)
Postfix Expression: ab+cd-*
*/