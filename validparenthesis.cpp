#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool valid(string &s){
    stack<char> stck;
    unordered_map<char, char> umap = {
        {'}','{'},
        {']','['},
        {')','('}
    };

    for(char c:s){
        if(c=='{' || c=='[' || c=='('){
            stck.push(c);
        }
        else{
            if(stck.empty())
            {
                return false;
            }
        char topelement = stck.top();
        if(umap.at(c)!=topelement){
            return false;
        }
        stck.pop();
    }
        
    }
    return stck.empty();
}
int main()
{
string str;
cin >> str;
bool validp = valid(str);
cout <<boolalpha<<validp << endl;
}