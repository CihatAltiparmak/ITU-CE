#include <iostream>
//#include <iomanip>
#include <string.h>
#include <stdlib.h>

using namespace std;

class List {
    struct Node{
        int val;
        struct Node* next;
    };

public:
    List();
    ~List();
    void push(int val);
    void display();
    void pop();

private:
    struct Node *head = new struct Node;
};

List::List()
{
    head -> next = NULL;
}


List::~List()
{
    while (head -> next != NULL) {
        struct Node *tmp = head;
	    head = head -> next;
        delete tmp;
    }
    delete head; 
}

void List::push(int x)
{
    struct Node* default_node = NULL;
    default_node =  head;  

    while (default_node->next != NULL) {
        default_node = default_node->next; 
    }
    
    struct Node* new_node = new struct Node;
    new_node -> val = x;
    
    default_node->next = new_node;
}

void List::pop()
{
    struct Node* default_node = NULL;
    default_node = head;
    if (head->next == NULL)
        return;
    while (default_node -> next -> next != NULL) {
	    default_node = default_node -> next;
    }

    delete default_node -> next;
    default_node -> next = NULL;
}

void List::display()
{
    struct Node* default_node = NULL;
    default_node = head;
    while (default_node -> next != NULL) {
	    default_node = default_node->next;
        cout << default_node->val << " ";
    }
    cout << endl;
}

int main()
{
    List mylist;
    for (int k = 0; k < 100; k++)
        mylist.push(k);
    mylist.display();
    for (int k = 0; k < 90; k++)
        mylist.pop();
    mylist.display();
    return 0;
}
