#include <iostream>
#include <stack>
#include <string>

using namespace std;
class List {
    int value;
    List* prev;

    List(int value, List* prev)
    {
        this->value = value;
        this->prev = prev;
    }
};



class Robot {
private:
    int ID;
    static int Counter;
    List* learnHistory;
    List* rollbackHistory;
public:
    Robot operator[](){

    }
    int GetID(){
        return this->ID;
    }

    Robot(){
        Counter=0;
        learnHistory= nullptr;
        rollbackHistory= nullptr;
        ID=Counter++;
    }
    ~Robot(){

    }

    Robot(const Robot& Nick)
    {
        this->learnHistory = Nick.learnHistory;
        this->rollbackHistory = Nick.rollbackHistory;
    }

    void learn(int idx, int programm){

    }

    void rollback(int);

    void relearn(int);

    void clone(int);

    void check(int);
};

void DoCommand(string operation, int clonenum, int prognum, Robot* CVS) {

    if (operation == "learn") {
        CVS[clonenum].Learn(prognum);
    }
    else if (operation == "rollback") {
        CVS[clonenum].RollBack();
    }
    else if (operation == "relearn") {
        CVS[clonenum].Relearn();
    }
    else if (operation == "clone") {
        MakeCopy(CVS[clonenum], CVS);
    }
    else if (operation == "check") {
        CVS[clonenum].Check();
    }

}

int main(){
    int Command_size, Programms;
    string IP;

    cin >> Command_size >> Programms;
    Robot Adam;


    for (int i = 0; i < Command_size; ++i) {
        getline(cin, IP);
        DoCommand();
    }

    return  0;
}