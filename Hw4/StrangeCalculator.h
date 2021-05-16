//
// Created by Ceyda Dereci on 16.05.2021.
//

#ifndef HW4_STRANGECALCULATOR_H
#define HW4_STRANGECALCULATOR_H
#include <string>
#include <iostream>
using namespace std;

string infix2prefix( const string exp );
double evaluatePrefix( const string exp );
bool isBalancedInfix( const string exp );
void evaluateInputPrefixExpression( );
string infixToPostfix(string infix);
int getPriority(char C);
bool isOperator(char c);

class StrangeCalculator {
    public:
        StrangeCalculator();
        StrangeCalculator(const StrangeCalculator& aStrangeCalculator);
        ~StrangeCalculator();
        bool isEmpty() const;
        bool push(char newItem);
        bool pop();
        bool pop(char& stackTop);
        bool getTop(char& stackTop) const;
        char top();
    private:
        struct StackNode {
            char item;
            StackNode *next;
    };
    StackNode *topPtr;
};


#endif //HW4_STRANGECALCULATOR_H
