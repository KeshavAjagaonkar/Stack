#include<iostream>

using namespace std;

class Queue{
    int size;
    int currentsize;
    int start;
    int end;
    int *arr;
    public:
        Queue(){
            size = 10;
            currentsize = 0;
            start = -1;
            end = -1;
            arr = new int[size];
        }
        void push(int x){
            if(currentsize==size){
                cout << "Queue overflow , can't push ont to stack" << endl;
                return;
            }
            if(currentsize==0){
                start = 0;
                end = 0;
            }
            else{
                end = (end + 1)%size;
                arr[end] = x;
                currentsize += 1;
            }
        }

        int pop(){
            if(currentsize==0){
                cout << "Queue is empty"<<endl;
                return 0;
            }
            int el = arr[start];
            if(currentsize==1){
                start = end = -1;
            }
            else{
                start = (start + 1) % size;
            }
            currentsize -= 1;
            return el;
        }
        void show(){
            for (int i = start; (start%size)<=(end%size); i++){
                cout << arr[i]<<" ";
            }
        }
        
};

int main(){
    Queue q;
    q.pop();
    q.push(10);
    q.push(100);
    q.push(1202);
    q.push(110);
    q.show();
}