#include<iostream>
#include<stack>
using namespace std;


//Function to return precdence order
int precedence(char c){
    if(c=='^')
        return 3;
    else if(c=='/' || c=='*')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    return -1;
}

void infnixToPostfix(string s){
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++){
        char c=s[i];
        
        //case-1: if scanned character(c) is operand then store it to the ans string
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'))
            ans+=c;

        //case-2: if scanned operator is '(' then push it into stack
        else if(c=='(')
            st.push(c);

        //case-3: If scanned operator is ')' then 
        //pop all the character from the stack untill the top character is not '('
        //and add to the result
        else if(c==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }

        //case-4: If scanned character is operator: then
        //repeadtly pop the character from the stack and add to the result untill
        //precendec of top operator from the stack is greater.
        else{
            while(!st.empty() && (precedence(c)<=precedence(st.top()))){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    //pop all the remaning elements from the stack and it to the result
    //untill the result is found
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    //Printing the postfix result
    cout<<"Postfix Expression is : "<<ans;

}

int main(){
    string str="A+B*(C-D)+E";
    infnixToPostfix(str);
    return 0;
}