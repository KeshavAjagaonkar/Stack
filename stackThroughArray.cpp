#include<iostream>
#include<vector>

using namespace std;

class Stack{
    int size;
    int *arr;
    int top;
    public:
        Stack(){
            size = 10;
            top = -1;
            arr = new int[size];
        }
        void show(){
           if(top==-1){
               cout << "stack is empty" << endl;
               return;
           }
           for (int i = 0; i <= top;i++){
               cout << arr[i] << " ";

           }
           cout << endl;
        }
        void push(int val){
            if(top>=size-1){
                cout << "stack is overflow";
                return;
            }
            top++;
            arr[top] = val;
            cout << val << " is stored" << endl;
        }
        void pop(){
            if(top==-1){
                cout << "stack is underflow";
                return;
            }
            int popped_value = arr[top];
            top--;
            cout << popped_value << "is the popped value"<<endl;
        }
        void peek(){
            if(top!=-1){
                cout << arr[top];
            }
            else{
                cout << "Stack is empty" << endl;
            }
        }
};

int main(){
    Stack s;
    s.peek();
    s.push(10);
    s.push(100);
    s.push(110);
    s.push(120);
    s.push(110);
    s.show();
    s.pop();
    s.show();
}