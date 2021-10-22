//
// Created by Ceyda Dereci on 16.05.2021.
//

#include "StrangeCalculator.h"

string infix2prefix(const string exp) {
    int l = exp.size();
    string temp = exp;
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < l; i++) {
        if (exp[i] == '(') {
            temp[i] = ')';
            i++;
        }
        else if (exp[i] == ')') {
            temp[i] = '(';
            i++;
        }
    }
    string prefix = infixToPostfix(temp);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

double evaluatePrefix(const string exp) {
    StrangeCalculator s;

    for (int j = exp.size() - 1; j >= 0; j--) {
        if (isdigit(exp[j]))
            s.push(exp[j] - '0');

        else {
            double o1 = s.top();
            s.pop();
            double o2 = s.top();
            s.pop();
            switch (exp[j]) {
                case '+':
                    s.push(o1 + o2);
                    break;
                case '-':
                    s.push(o1 - o2);
                    break;
                case '*':
                    s.push(o1 * o2);
                    break;
                case '/':
                    s.push(o1 / o2);
                    break;
            }
        }
    }
    return s.top();
}

bool isBalancedInfix(const string exp) {
    StrangeCalculator s;
    for(int i =0;i<exp.length();i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(s.isEmpty() || !arePair(s.top(),exp[i]))
                return false;
            else
                s.pop();
        }
    }
    return s.isEmpty() ? true:false;
}

void evaluateInputPrefixExpression() {
    //ask the user for an infix input
    string infix;
    int count = 0;
    cout << "Enter an infix input: " << endl;
    getline(cin,infix);
    //remove the possible spaces in the input
    for (int i = 0; infix[i]; i++) {
        if (infix[i] != ' ')
            infix[count++] = infix[i];
    }
    infix[count] = '\0';
    //check isBalancedInfix
    if(!isBalancedInfix(infix)){
        cout << "Infix is not balanced!";
    }
    else {
        // convert infix2prefix
        infix = infix2prefix(infix);
        // evaluatePrefix
        evaluatePrefix(infix);
    }
}

string infixToPostfix(string infix)
{
    StrangeCalculator s;
    infix = '(' + infix + ')';
    int l = infix.size();
    string output;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        else if (infix[i] == '(')
            s.push('(');
        else if (infix[i] == ')') {
            while (s.top() != '(') {
                output += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            if (isOperator(s.top()))
            {

                while (getPriority(infix[i]) < getPriority(s.top()))
                {
                    output += s.top();
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }
    return output;
}

int getPriority(char C){
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    return 0;
}

bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}

StrangeCalculator::StrangeCalculator(): topPtr(NULL){
}

bool arePair(char opening,char closing){
    if(opening == '(' && closing == ')')
        return true;
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;
    return false;
}

StrangeCalculator::StrangeCalculator(const StrangeCalculator &aStrangeCalculator) {
    if (aStrangeCalculator.topPtr == NULL)
        topPtr = NULL;  // original stack is empty
    else {
        // copy first node
        topPtr = new StackNode;
        topPtr->item = aStrangeCalculator.topPtr->item;
        // copy rest of stack
        StackNode *newPtr = topPtr;
        for (StackNode *origPtr = aStrangeCalculator.topPtr->next; origPtr != NULL; origPtr = origPtr->next){
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}

StrangeCalculator::~StrangeCalculator() {
    while (!isEmpty())
        pop();
}

bool StrangeCalculator::isEmpty() const {
    return topPtr == NULL;
}

bool StrangeCalculator::push(char newItem) {
    StackNode *newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;
}

bool StrangeCalculator::pop() {
    if (isEmpty())
        return false;
    else{
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}

bool StrangeCalculator::pop(char &stackTop) {
    if (isEmpty())
        return false;
        // not empty; retrieve and delete top
    else{
        stackTop = topPtr->item;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        // return deleted node to system
        temp->next = NULL;  // safeguard
        delete temp;
        return true;
    }
}

bool StrangeCalculator::getTop(char &stackTop) const {
    if (isEmpty())
        return false;
        // stack is not empty; retrieve top
    else {
        stackTop = topPtr->item;
        return true;
    }
}

char StrangeCalculator::top() {
    return topPtr->item;
}


