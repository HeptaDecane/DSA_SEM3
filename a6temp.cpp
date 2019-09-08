///*
// * C++ Program To Implement Stack using Linked List
// */
//#include<iostream>
//#include<cstdlib>
//using namespace std;
// 
///*
// * Node Declaration
// */
//struct node
//{
//    int info;
//    struct node *link;    
//}*top;
// 
///*
// * Class Declaration
// */
//class stack_list
//{
//    public:
//        node *push(node *, int);
//        node *pop(node *);
//        void traverse(node *);
//        stack_list()
//        {
//            top = NULL;
//        }               
//};
// 
///*
// * Main: Contains Menu
// */
//int main()
//{
//    int choice, item;
//    stack_list sl;
//    while (1)
//    {
//        cout<<"\n-------------"<<endl;
//        cout<<"Operations on Stack"<<endl;
//        cout<<"\n-------------"<<endl;
//        cout<<"1.Push Element into the Stack"<<endl;
//        cout<<"2.Pop Element from the Stack"<<endl;
//        cout<<"3.Traverse the Stack"<<endl;
//        cout<<"4.Quit"<<endl;
//        cout<<"Enter your Choice: ";
//        cin>>choice;
//        switch(choice)
//        {
//        case 1:
//            cout<<"Enter value to be pushed into the stack: ";
//            cin>>item;
//            top = sl.push(top, item);
//            break;
//        case 2:
//            top = sl.pop(top);
//            break;
//        case 3:
//            sl.traverse(top);
//            break;
//        case 4:
//            exit(1);
//            break;
//        default:
//            cout<<"Wrong Choice"<<endl;
//        }
//    }
//    return 0;
//}
// 
///*
// * Push Element into the Stack
// */
//node *stack_list::push(node *top, int item)
//{
//    node *tmp;
//    tmp = new (struct node);
//    tmp->info = item;
//    tmp->link = top;
//    top = tmp;
//    return top;
//}
// 
///*
// * Pop Element from the Stack
// */
//node *stack_list::pop(node *top)
//{
//    node *tmp;
//    if (top == NULL)
//        cout<<"Stack is Empty"<<endl;
//    else
//    {       
//        tmp = top;
//        cout<<"Element Popped: "<<tmp->info<<endl;
//        top = top->link;
//        delete(tmp);
//    }
//    return top;
//}
// 
///*
// * Traversing the Stack
// */
//void stack_list::traverse(node *top)
//{       
//    node *ptr;
//    ptr = top;
//    if (top == NULL)
//        cout<<"Stack is empty"<<endl;
//    else
//    {
//        cout<<"Stack elements :"<<endl;
//        while (ptr != NULL)
//        {
//            cout<<ptr->info<<endl;
//            ptr = ptr->link;
//        }
//    }







//============================================================================
// Name        : wellformness.cpp
// Author      : Nitin Shivale
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define size 10

class stackexp
{
    int top;
    char stk[size];
public:
    stackexp()
    {
     top=-1;
    }
    void push(char);
    char pop();
    int isfull();
    int isempty();
};

void stackexp::push(char x)
{
    top=top+1;
    stk[top]=x;
}

char stackexp::pop()
{
    char s;
    s=stk[top];
    top=top-1;
    return s;
}

int stackexp::isfull()
{
    if(top==size)
        return 1;
    else
        return 0;
}

int stackexp::isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int main()
{
    stackexp s1;
    char exp[20],ch;
    int i=0;
    cout << "\n\t!!Well Formness of Parenthesis..!!!!" << endl; // prints !!!Hello World!!!
    cout<<"\nEnter the expression to check whether it is in well form or not :  ";
    cin>>exp;
    if((exp[0]==')')||(exp[0]==']')||(exp[0]=='}'))
    {
        cout<<"\n Invalid Expression.....\n";
        return 0;
    }
    else
    {
        while(exp[i]!='\0')
        {
            ch=exp[i];
            switch(ch)
            {
            case '(':s1.push(ch);break;
            case '[':s1.push(ch);break;
            case '{':s1.push(ch);break;
            case ')':s1.pop();break;
            case ']':s1.pop();break;
            case '}':s1.pop();break;
            }
            i=i+1;
        }
    }
    if(s1.isempty())
    {
        cout<<"\nExpression is well parenthesis...\n";
    }
    else
    {
        cout<<"\nSorry !!! Invalid Expression or not in well parenthesized....\n";
    }
    return 0;
}
