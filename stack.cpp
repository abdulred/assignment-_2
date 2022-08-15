#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class T>
class calc
{

public:
  int symbolType(char symbols);
  int precValue(char symbol);
  int cmpPrec(char oprStk,char oprlnp);
  int associativity(char opr);
  int topostfix(string infix );
  int evaluate(string postfix);

};
enum {OPARSTK=0,CPAR=5,ADD=10, MULT=15, EXP=20, SIGN = 25, OPARINP=30 };
void display(){
    cout<<"hi mom!"<<endl;
}
template <class T>
int calc<T>::symbolType(char symbol){
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
    return ADD;

    if(symbol == '*'||symbol == '/')
    return MULT;

    if(symbol =='^')
    return EXP;
    if(symbol=='#'||symbol=='~')
    return SIGN;
    if(symbol=='(')
    return OPARSTK;
    if(symbol==')')
    return CPAR;
    if(symbol=='[')
    return OPARINP;

    return 0;
}

template <class T>
int calc<T>::cmpPrec(char oprStk,char oprlnp){
	int sym1,sym2;
	sym1=precValue(oprStk);
	sym2=precValue(oprlnp);
	if(sym1 < sym2)
		return -1;
	else if (sym1==sym2)
		return 0;
	else
		return 1;
    
}
template<class T>
  int calc<T>:: associativity(char opr){
    	if(opr=='^')
		return 0;
	else
		return 1;
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
    cout<< "Your infix expression converted to post fix is:";
    cout << result << endl;
    return 0;
}
template<class T>
int calc<T>::evaluate(string result){

       stack<double> stev;
   for(int i=0;result[i];i++){
    if(isdigit(result[i])){
    stev.push(result[i]);

   }
   else{
    int val1=stev.top();
    stev.pop();
    int val2=stev.top();
    stev.pop();
    switch (result[i])
    {
   	case '+':
         stev.push( val2 + val1); 
         break;
	case '-':
        stev.push(val2 - val1);
              break;
	case '*':
             stev.push( val2 * val1);
              break;
	case '/':
             stev.push(val2/val1); 
             break;
    
    default:
        break;
    }
   }
     double res = stev.top();
    return res;
}

}





