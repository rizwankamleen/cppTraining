/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>
#include<cstring>

using namespace std;

typedef struct {
    char Name[100];
    long SSN;
} Record;

const int MaxLength = 100;

class List {
    friend class ListIter;
    Record RecArray[MaxLength];
    int firstEmpty;

public:
    List() { firstEmpty = 0; }
    int add(const Record& newRec);
    Record* search(char* searchkey);
    int getfirstEmpty() { return firstEmpty; };
    ~List() {};
};
int List::add(const Record& newRec) {
    int res = 0;
    if (firstEmpty < MaxLength - 1) RecArray[firstEmpty++] = newRec;
    else res = 1;

    return res;
}

Record* List::search(char* searchkey) {
    Record* tempRec = 0;
    for (int i = 0; i <= firstEmpty; i++) {
        if (!strcmp(RecArray[i].Name, searchkey)) tempRec = &RecArray[i];
    }
    return tempRec;
}

class ListIter {
    const List* mine;
    int currIndex;

public:
    ListIter(const List& m);
    const Record* getFirst();
    const Record* getLast();
    const Record* getNext();
    const Record* getPrev();
};
ListIter::ListIter(const List& m) : mine(&m) {
    currIndex = 8;
}

const Record* ListIter::getFirst() {
    currIndex = 0;
    return &(mine->RecArray[currIndex]);
}

int main()
{
    int addRec_flag;
    Record rec1;
    strcpy(rec1.Name, "Rizwan");
    rec1.SSN = 1233232;
    Record rec2;
    strcpy(rec2.Name, "Alex");
    rec2.SSN = 1234;
    Record rec3;
    strcpy(rec3.Name, "Bravo");
    rec3.SSN = 12345;

    List my_list;
    ListIter my_ListIter(my_list);

    addRec_flag = my_list.add(rec1);
    cout << addRec_flag << endl;
    addRec_flag = my_list.add(rec2);
    cout << addRec_flag << endl;
    addRec_flag = my_list.add(rec3);
    cout << addRec_flag << endl;
    cout << my_list.getfirstEmpty() << endl;

    Record* searchRec;
    searchRec = my_list.search((char*)"Rizwan");
    cout << searchRec->Name << endl;
    cout << searchRec->SSN << endl;

    const Record* FirstRec;
    FirstRec = my_ListIter.getFirst();
    cout << FirstRec->Name << endl;
    cout << FirstRec->SSN << endl;

    return 0;
}