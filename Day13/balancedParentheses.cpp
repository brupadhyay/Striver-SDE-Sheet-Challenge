#include <stack>
#include <iostream>
using namespace std;

bool isValidParenthesis(string s)
{
    stack<char> st;
    for(char c: s){
        if(c == '{' || c == '[' || c == '('){
            st.push(c);
        } else {
            if(st.empty()) return false;

            char top = st.top();
            bool flag = false;
            if(top == '{' && c == '}' || top == '[' && c == ']' ||
            top == '(' && c == ')'){
                st.pop();
                flag = true;
            }
            if(flag == false) return false;

        }
    }
    return st.empty();
}

int main(){
    cout << "string is ";
    isValidParenthesis("{{{}[]()}}") ? cout << "balanced" : cout << "not balanced"<< endl;
    cout << "\nstring is ";
    isValidParenthesis("{)}}") ? cout << "balanced" : cout << "not balanced"<< endl;

    return 0;
}