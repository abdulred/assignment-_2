#include <iostream>
#include <string>
#include <stack>

using namespace std;





struct MemoryException: public std::exception{
    const char * what () {

        return "Unable to allocate memory for the stack!";
    }
};

struct FullStackException: public std::exception{
    const char * what () {
        return "Stack is full!";
    }
};
struct EmptyStackException: public std::exception{
    const char * what () {
        return "Popping an empty stack!";
    }
};
template<class T>
class calc
{

public:

  string symbolType(char symbols);
  int precValue(char symbol);
  int cmpPrec(char oprStk,char oprlnp);
  int associativity(char opr);
  int topostfix(string infix );
  int evaluate(string postfix);

};
void display(){
    cout<<"hi mom!"<<endl;
}
template <class T>
int calc<T>::symbolType(char symbols){
	if(symbol=='+' || symbol== '-' ||

  symbol== '*' || symbol=='/' || symbol=='^'||

  symbol=='(' || symbol==')')
		return 0;
	else if(symbol >='0' && symbol <= '9')
		return 1;
	else
		return 2;
}

template<class T>
int calc<T>::precValue(char symbol){
    if(symbol == '+'||symbol == '-')
    return 1;

    if(symbol == '*'||symbol == '/')
    return 2;

    if(symbol =='^')
    return 3;

    return 0;
}

template <class T>
int calc<T>::cmpPrec(char oprStk,char oprlnp){
    if(st.empty()) return 1;
    while ()
    {
        /* code */
    }
    
}
template<class T>
  int calc<T>:: associativity(char opr){
    
  }

template<class T>
 int calc<T>::topostfix(string infix ){
 stack<char> st;
    string result;

    for (int i = 0; i < infix.length(); i++) {

        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
          st.push('(');

       else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }


else {//if you scan operator the following will be done.
            while (!st.empty()
                   && precValue(infix[i]) <= precValue(st.top())) {
                if (c == '^' && st.top() != '^')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
    return 0;
}








