#include <iostream>

using namespace std;

struct Node
{
    int value;
    //Node *prev_ptr;
    Node *next_ptr;
};

class LinkedList
{
private:
    Node *head, *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void display()
    {
        Node *next_node = head;
        cout << "[";
        while (true)
        {
            cout << next_node->value;
            if (next_node->next_ptr == NULL)
                break;
            next_node = next_node->next_ptr;
            cout << ", ";
        }
        cout << "]" << endl;
    }

    void add_node(int n)
    {
        Node *tmp = new Node;
        tmp->value = n;
        tmp->next_ptr = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next_ptr = tmp;
            tail = tmp;
        }
    }
};

int main()
{
    LinkedList myList;
    cout << "asdas" << endl;
    myList.add_node(33);
    myList.add_node(44);
    myList.add_node(343);
    myList.display();
    return 0;
}
