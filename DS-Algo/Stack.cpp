#include<iostream>

using namespace std;

template <typename T>
class Stack {
    private:
        T *arr;
    public:
        int total_size;
        int lastIndex = -1;

        Stack(int s) {
            total_size = s;
            arr = new T(total_size);
        }

        void display() {
            cout << "[";
            for(int i=0; i <= lastIndex; i++) {
                cout << arr[i];
                if(i != lastIndex)
                    cout << ", ";
            }
            cout << "]" << endl;
        }

        void push(T value) {
            arr[lastIndex+1] = value;
            lastIndex++;
        }

        void pop() {
            arr[lastIndex] = 0;
            lastIndex--;
        }

        T top() {
            return arr[lastIndex];
        }
    
        T peek(int index) {
            return arr[index];
        }
};

int main() {
    Stack<int> myStack(100);
    myStack.push(12);
    myStack.push(235);
    myStack.push(234);
    myStack.push(455);
    myStack.push(3);
    myStack.pop();
    myStack.display();
}
