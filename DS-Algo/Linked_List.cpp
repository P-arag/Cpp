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
        void insert_front(int n) {
            Node *tmp = new Node;
            tmp->value = n;
            tmp->next_ptr = head;
            head = tmp;
        }

        void insert(int n, int index) {
            int i = 0;
            Node *next_node = head;

            while (true) {
                if(i == index) {
                    cout << next_node->value << endl;
                }

                if (next_node->next_ptr == NULL)
                    break;
                next_node = next_node->next_ptr;
                i++;
            }
        }
};

int main()
{
    LinkedList myList;
    myList.add_node(33);
    myList.add_node(44);
    myList.add_node(343);
    myList.insert_front(944);
    cout << myList.get_val(1) << endl;
    myList.insert(12, 2);
    myList.display();
    return 0;
}
