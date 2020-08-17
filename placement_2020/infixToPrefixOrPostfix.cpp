#include<bits/stdc++.h>
using namespace std;

int checkPrecedence(char c){
	if (c == '^') return 3;
	else if(c=='+'||c=='-')return 1;
	else if(c=='*'||c=='/')return 2;
	else return -1;
}

bool isOperand(char c){
    if (c >='A' && c<='Z') return true;
    else if(c>='a'&&c<='z') return true;
    else if(c>='1'&&c<='9') return true;
    return false;
}

string cvtpostfixToprefix(string str){
  stack<string> stk;
  for(int i=0;i<str.size();i++){
  	if(isOperand(str[i])){
  	  string op(1,str[i]);
      stk.push(op);
  	}
  	else{
      string s1 = stk.top();
      stk.pop();
      string s2 = stk.top();
      stk.pop();
      string postfix = str[i] + s2 + s1  ; //change
      stk.push(postfix);
  	}
  }
  return stk.top();
}
string cvtprefixTopost(string str){
  stack<string> stk;
  for(int i=str.size()-1;i>=0;i--){
  	if(isOperand(str[i])){
  	  string op(1,str[i]);
      stk.push(op);
  	}
  	else{
      string s1 = stk.top();
      stk.pop();
      string s2 = stk.top();
      stk.pop();
      string postfix = s1 + s2 + str[i]  ; //change
      stk.push(postfix);
  	}
  }
  return stk.top();
}

string cvtpostfixToInfix(string str){
  stack<string> stk;
  for(int i=0;i<str.size();i++){
  	if(isOperand(str[i])){
  	  string op(1,str[i]);
      stk.push(op);
  	}
  	else{
      string s1 = stk.top();
      stk.pop();
      string s2 = stk.top();
      stk.pop();
      string postfix ="(" + s2 + str[i] + s1 +")";
      stk.push(postfix);
  	}
  }
  return stk.top();
}

string cvtprefixToInfix(string str){
  stack<string> stk;
  for(int i=str.size()-1;i>=0;i--){
  	if(isOperand(str[i])){
  	  string op(1,str[i]);
      stk.push(op);
  	}
  	else{
      string s1 = stk.top();
      stk.pop();
      string s2 = stk.top();
      stk.pop();
      string prefix ="(" + s1 + str[i] + s2 +")";
      stk.push(prefix);
  	}
  }
  return stk.top();
}

string cvtInfixToPostfix(string str){
	stack<char> stk;
	stk.push('\n');
	string postfix = "";
	for(int i=0;i<str.size();i++){
		if (str[i]=='('){
           stk.push('(');
		}
		else if(str[i]==')'){
           while(stk.top()!='\n'&&stk.top()!='('){
              postfix += stk.top();
              stk.pop();
           }
           if (stk.top()=='(')stk.pop();
		}
		else if (isOperand(str[i])){
           postfix+=str[i];
		}
		else{//check precendence
           while(stk.top()!='\n'
           	&&checkPrecedence(str[i])<=checkPrecedence(stk.top())
           	){
           	postfix+=stk.top();
            stk.pop();
           }
           stk.push(str[i]);
		}
	}
	//pop all element
	while(stk.top()!='\n'){
		postfix+=stk.top();
		stk.pop();
	}
	return postfix;
}


string cvtInfixToPrefix(string str){
 reverse(str.begin(),str.end());
  for (int i = 0; i < str.size(); i++) { 
  
        if (str[i] == '(') { 
            str[i] = ')'; 
            i++; 
        } 
        else if (str[i] == ')') { 
            str[i] = '('; 
            i++; 
        } 
    } 
  
 cout<<endl;
 string postfix = cvtInfixToPostfix(str);
 reverse(postfix.begin(),postfix.end());
 return postfix;
}



int main(){
	string str;
	cin>>str;
    // cout<<"InfixToPostfix:: "<<cvtInfixToPostfix(str)<<endl;
    // cout<<"InfixToPrefix:: "<<cvtInfixToPrefix(str)<<endl;
    // cout<<"PostfixToInfix::"<<cvtpostfixToInfix(str)<<endl;
    // cout<<"PrefixToInfix:: "<<cvtprefixToInfix(str)<<endl;
}