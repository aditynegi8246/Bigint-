#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};struct node *temp,*temp1,*temp2,*head,*head1,*head2,*tail,*tail1,*tail2,*newnode;
long int big(long int n1,long int n2);
long int subbig(long int n1,long int n2);
long int addbig(long int n1,long int n2);
long int multiply(long int n1,long int n2);
int main()
{
    long int n1,n2;
    printf("Enter the long integer 1:");
    scanf("%ld",&n1);
    printf("Enter the long integer 2:");
    scanf("%ld",&n2);
    long int sum=addbig(n1,n2);
    printf("Sum of both big integers are:%ld\n",sum);
    long int sub=subbig(n1,n2);
    printf("Difference of both big integers are:%ld\n",sub);
    long int product=multiply(n1,n2);
    printf("Product of both big integers are:%ld\n",product);
}
long int big(long int n1,long int n2)
{
    head1=(struct node *)malloc(sizeof(struct node));
    temp1=head1;
    while(n1 != 0)
    {
        temp1->data= n1%10;
        n1=n1/10;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp1->next=newnode;
        newnode->prev=temp1;
        temp1=temp1->next;
    }
    tail1=temp1;
    temp1=head1;
    head2=(struct node *)malloc(sizeof(struct node));
    temp2=head2;
    while(n2 != 0)
    {
        temp2->data= n2%10;
        n2=n2/10;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp2->next=newnode;
        newnode->prev=temp2;
        temp2=temp2->next;
    }
    tail2=temp2;
    temp2=head2;
}
long int addbig(long int n1,long int n2)
{
    big(n1,n2);
    temp1=head1;
    temp2=head2;
    head=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int carry=0;
    while(temp1 != NULL && temp2 != NULL)
    {
        int sum=(temp1->data) + (temp2->data) + carry;
        temp->data=sum%10;
        carry=sum/10;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1 != NULL)
    {
        temp->data=temp1->data +carry;
        carry=carry/10;
        temp1 = temp1->next;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
    while(temp2 != NULL)
    {
        temp->data=temp2->data +carry;
        carry=carry/10;
        temp2 = temp2->next;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
    tail=temp;
    temp=head;
    long int sum=0;
    long int dig=1;
    while(temp != NULL)
    {
        sum=sum + (temp->data * dig);
        temp=temp->next;
        dig=dig*10;
    }
    return sum;
}
long int subbig(long int n1,long int n2)
{
    if(n2>n1)
    big(n2,n1);
    else
    big(n1,n2);
    temp1=head1;
    temp2=head2;
    int borrow = 0;
    head=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp1 != NULL || temp2 != NULL)
    {
        int x,y;
        if(temp1 != NULL)
        {
            x=temp1->data;
        }
        else
        x=0;
        if(temp2 != NULL)
        {
            y=temp2->data;
        }
        else 
        y=0;
        int sub;
        sub= x - y - borrow;
        if(sub<0)
        {
            sub+=10;
            borrow=1;
        }
        else 
        {
            borrow=0;
        }
        temp->data=sub;
        newnode=(struct node *)malloc(sizeof(struct node));
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
        temp1=temp1->next;
        if(temp2)
        temp2=temp2->next;
    }
    tail=temp;
    temp = head;
    long int sub=0;
    long int dig=1;
    while(temp != NULL)
    {
        sub=sub+(temp->data*dig);
        dig=dig*10;
        temp=temp->next;
    }
    return sub;
} 
long int multiply(long int n1,long int n2)
{
    if(n1<n2)
    {
        big(n2,n1);
    }
    else
    {
        big(n1,n2);
    }
    head=(struct node *)malloc(sizeof(struct node));
    temp=head;
    struct node *last;
    last = temp;
    temp1=head1;
    temp2=head2;
    int sum=0;
    while(temp2 != NULL)
    {
        int carry = 0;
        while(temp1 != NULL)
        {
            sum=(temp2->data * temp1->data) + carry;
            sum=sum+temp->data;
            temp->data=sum%10;
            carry=sum/10;
            if(temp->next == NULL)
            {
                newnode=(struct node *)malloc(sizeof(struct node));
                temp->next=newnode;
                newnode->prev=temp;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
        temp->data=carry;
        temp1=head1;
        temp=last->next;
        temp2=temp2->next;
        last=temp;
    }
    temp=head;
    long int dig=1;
    long int product=0;
    while(temp!=NULL)
    {
        product=product+(temp->data *dig);
        dig=dig*10;
        temp=temp->next;
    }
    return product;
}
