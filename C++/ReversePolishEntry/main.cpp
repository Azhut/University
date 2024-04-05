#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int INTpror(char c){
    int p;
    switch (c)
    {
    case '(':
        p = 4;
    case ')':
        p = 4;
    case '+':
    case '-':
        p = 3;
        break;
    case '*':
    case '/':
        p = 2;
        break;
    case '^':
        p = 1;
        break;
    default:
        break;
    }
    return p;
}

int pror(char c){
    switch (c)
    {
        case '(':
        case ')':
            return 0;
        case '|':
            return 1;
        case '&':
            return 2;
        case '!':
            return 3;
    }
}

string INTPolish(string UserString){
    Stack stk;
    cout << "Enter your ... " << endl;
    string PostFixStr;

    for (int i = 0; i < UserString.length(); i++) {

        if (isdigit(UserString[i])) {
            PostFixStr += UserString[i];
            continue;
        }

        if (stk.isEmpty()) {
            stk.push(UserString[i]);
            continue;
        }

        if (UserString[i] == '(') {
            stk.push(UserString[i]);
            continue;
        }

        if (UserString[i] == ')') {
            while (stk.peek() != '(') {
                PostFixStr += stk.pop();
            }
            stk.pop();
            continue;
        }

        while ((pror(UserString[i]) >= pror(stk.peek()))) {
            PostFixStr += stk.pop();
        }
        stk.push(UserString[i]);
    }

    while(!stk.isEmpty()) {
        PostFixStr += stk.pop();
    }

    return PostFixStr;
}

void Polish(string& UserString){
    Stack stk;
    string Ans=" ";

    for (char ch: UserString) {

        if (stk.isEmpty() || ch == '(') {
            stk.push(ch);
            continue;
        }

        if (isdigit(ch)) {
            Ans += ch;
            continue;
        }


        if (ch == ')') {
            while (!stk.isEmpty()) {
                ch = stk.pop();
                if(ch == '(') break;
                Ans += ch;
            }
            continue;
        }

        while (!stk.isEmpty() && (pror(stk.peek()) >= pror(ch))) {
            Ans += stk.pop();
        }
        stk.push(ch);
    }

    while(!stk.isEmpty()) {
        Ans += stk.pop();
    }

    UserString= Ans;
}

void Convertation(string& UserString){
    string temp = " ";
    char prev = ' ';
    int raw_len = UserString.length();
    char ch;
    for(int i = 0; i < raw_len; i++) {
        ch = UserString[i];

        if (('A' <= ch) && (ch <= 'Z')) {
            if (('A' <= prev) && (prev <= 'Z')) {
                switch (prev) {
                    case 'T':
                        temp.append("1");
                        i += 2;
                        break;
                    case 'F':
                        temp.append("0");
                        i += 3;
                        break;
                    case 'A':
                        temp.append("&");
                        i++;
                        break;
                    case 'O':
                        temp.append("|");
                        break;
                    case 'N':
                        temp.append("!");
                        i++;
                        break;
                    default:
                        cout << "error" << endl;
                        exit(1);
                }
                prev = ' ';
                continue;
            } else prev = ch;
        } else {
            if (('A' <= prev) && (prev <= 'Z')) temp.push_back(prev);
            if (ch != ' ') temp.push_back(ch);
        }
        prev = ch;
    }
    UserString= temp;
}


int main(){
    string UserStr;
    getline(cin, UserStr);

    Convertation(UserStr);
    cout << UserStr;

    Polish(UserStr);
    cout << UserStr << endl;

    return 0;
}


