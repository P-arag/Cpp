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
        int total_size = 0;
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

        int get_val(int index) {
            int i = 0;
            Node *next_node = head;

            while (true) {
                if(i == index) {
                    return  next_node->value;
                }
                if (next_node->next_ptr == NULL)
                    break;
                next_node = next_node->next_ptr;
                i++;
            }
            return -1;
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
            total_size++;
        }

        void set_val(int n, int index) {
            int i = 0;
            Node *next_node = head;

            while (true) {
                if(i == index) {                    
                    next_node->value = n;
                }

                if (next_node->next_ptr == NULL)
                    break;
                next_node = next_node->next_ptr;
                i++;
            }
        }

        void insert_front(int n) {
            Node *tmp = new Node;
            tmp->value = n;
            tmp->next_ptr = head;
            head = tmp;
            total_size++;
        }

        void insert(int n, int index) {
            int i = 0;
            Node *next_node = head;

            while (true) {
                if(i == index-1) {                    
                    Node *new_node = new Node;
                    new_node->value = n;
                    new_node->next_ptr = next_node->next_ptr;
                    next_node->next_ptr = new_node;
                }

                if (next_node->next_ptr == NULL)
                    break;
                next_node = next_node->next_ptr;
                i++;
            }
            total_size++;
        }
        void delete_node(int index) {
            int i = 0;
            Node *next_node = head;

            while (true) {
                if(i == index-1) {                    
                    next_node->next_ptr = next_node->next_ptr->next_ptr;
                }

                if (next_node->next_ptr == NULL)
                    break;
                next_node = next_node->next_ptr;
                i++;
            }
            total_size--; 
        }
};

int main()
{
    LinkedList myList;
    myList.add_node(33);
    myList.add_node(44);
    myList.add_node(343);
    myList.add_node(232);
    myList.insert_front(944);
    myList.set_val(56, 1);
    cout << "Element at index 1 <: " << myList.get_val(1) << endl;
    myList.insert(12, 2);
    myList.display();
    myList.delete_node(4);
    cout << "Total Array Size <: " << myList.total_size << endl;
    myList.display();
    return 0;
}
