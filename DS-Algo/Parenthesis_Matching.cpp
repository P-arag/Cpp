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

        int pop() {
            if(lastIndex != -1) { 
                arr[lastIndex] = 0;
                lastIndex--;
                return 1;
            }
            return -1;
        }

        T top() {
            return arr[lastIndex];
        }

        T peek(int index) {
            return arr[index];
        }
};

bool match(char a, char b) {
    if(a == '(' && b == ')') {return true;}
    if(a == '{' && b == '}') {return true;}
    if(a == '[' && b == ']') {return true;}
    return false;
}

int main() {
    string str;
    cout << "Please enter an expression <: ";
    cin >> str;
    cout << endl;
    
    Stack<char> myStack(str.length());

    for(int i=0; i<str.length(); i++) {
        char  ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[' ) {
            myStack.push(ch);
        }
        else if(ch==')' || ch == '}' || ch == ']' ) {
            if(match(myStack.top() , ch)) { 
                int isPopped = myStack.pop();
                if(isPopped == -1) {
                    cout << "Malformed Parenthesis Expression!!" << endl;
                    return 0;
                }

            } else {
                cout << "Malformed Parenthesis Expression!!" << endl;
                return 0;
            }
        }
    }
    if(myStack.lastIndex != -1) {
        cout << "Malformed Parenthesis Expression!!" << endl;
    } else   
        cout << "Expression OK!"<< endl;
}

