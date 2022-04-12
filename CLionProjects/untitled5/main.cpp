#include <iostream>
#include <vector>
#include <stdio.h>
#include <list>
#include <iterator>
#include <ctime>

using namespace std;

void task1(const char* fileName) {
    FILE *f1;
    FILE *f2;
    f1 = fopen(fileName, "r");
    f2 = fopen("result", "w");
    fseek(f1, 0, SEEK_END);
    int begin = ftell(f1);
    int check=1;
    fseek(f1, 0, SEEK_SET);
    char *buffer = new char[begin];
    char *needed = new char[begin];
    char* foroutput=new char[begin];
    int *number = new int[begin];
    size_t result = fread(buffer, 1, begin, f1);
    for (int i = 0; i < begin; i++) {
        int count = 0;
        for (int j = 0; j < begin; j++) {
            if (buffer[i] == buffer[j]) {
                needed[i] = buffer[i];
                count++;
            }
        }
        number[i] = count;
        count = 0;
    }
    for (int i = 0; i < begin; i++) {
        for(int j=0;j<begin;j++) {
            if (needed[i] == foroutput[j]) {
                check++;
            }
        }
            if(check<2){
                foroutput[i]=needed[i];
                fprintf(f2, "%c\t%d\n", needed[i], number[i]);
            }
            check=1;
    }
    fclose(f1);
    fclose(f2);
}
void task2(int number){
    FILE  *f1;
    f1=fopen("task_2","w");
    char binform[32];
    for (int i = 0; i < 32; i++) {
   binform[i] = ((number & (1 << i)) >> i) + 0x30;
        fprintf(f1,"%c", binform[i]);
        cout<<binform[i];
}
    fclose(f1);
}
vector<float> average(float *ar, int M, int N){ //M-row, N-column
    vector<float> avr;
    for(int i=0;i<M;i++){
       float  temp=0;
        for(int j=0;j<N;j++){
            temp+=ar[i*N+j]/(float)N;
        }
        avr.push_back(temp);
    }
    return avr;
}
void task5(float *ar, int M, int N){
    vector<float>avr= average(ar, M,N);
for(int i=0;i<M;i++){
    cout<<avr[i]<<endl;
}
}
void task3(char* line){
    char temp[32];
   int binTemp[32];
    int count=0;
    for(int i=0;i<32;i++){
        binTemp[i]=0;
    }
    char* numTemp=new char[4];
    for(int i=0,i1=0;i<159;i=i+5,i1++) {

        for (int j = 0; j < 4; j++) {
            numTemp[j] = line[i + j];

        }
        if (numTemp[0]=='0' && numTemp[1]=='x' && numTemp[2]=='3' && numTemp[3]=='0') {

            binTemp[i1] = 0;
        }
        if (numTemp[0]=='0' && numTemp[1]=='x' && numTemp[2]=='3' && numTemp[3]=='1') {

            binTemp[i1] = 1;
        }
        if(numTemp[0]!='0'){
        }
    }

    for(int i=0;i<32;i=i+4){
        int binNum=8*binTemp[i+3]+4*binTemp[i+2]+2*binTemp[i+1]+1*binTemp[i];
        switch (binNum) {
            case 0:{
                temp[count]='0';
            }break;
            case 1:{
                temp[count]='1';
            }break;
            case 2:{
                temp[count]='2';
            }break;
            case 3:{
                temp[count]='3';
            }break;
            case 4:{
                temp[count]='4';
            }break;
            case 5:{
                temp[count]='5';
            }break;
            case 6:{
                temp[count]='6';
            }break;
            case 7:{
                temp[count]='7';
            }break;
            case 8:{
                temp[count]='8';
            }break;
            case 9:{
                temp[count]='9';
            }break;
            case 10:{
                temp[count]='A';
            }break;
            case 11:{
                temp[count]='B';
            }break;
            case 12:{
                temp[count]='C';
            }break;
            case 13:{
                temp[count]='D';
            }break;
            case 14:{
                temp[count]='E';
            }break;
            case 15:{
                temp[count]='F';
            }break;
        }
count++;
    }
temp[8]='x';
    temp[9]='0';
for(int i=9;i>=0;i--){

    cout<<temp[i];
}
}
struct Node
{
    Node* prev;
    Node* next;
    const char* surname;
Node(const char* str){
this->surname=str;
};
};
class LinkedList
{
private:
    Node *Head;
    Node *Tail;
    Node *d;
    unsigned int length = 0;
public:
    LinkedList();
    ~LinkedList();
    void pushBack(const char* str);
    void showList();
    void writeToFile(const char* fileName);
    void insertTo(int index, const char* str);
};
LinkedList::LinkedList()
{
    Head = Tail = nullptr;
}
LinkedList::~LinkedList()
{
    delete Head;
    delete d;
    delete Tail;
}
void LinkedList::insertTo(int index, const char *str) {
    if(index>length+1 || index<1){
        cout<<"Alert, the index was entered incorrectly"<<endl;
    }
    else {
        if(index==1){
            Node *temp = new Node(str);
            Node *tempHead = Head;
            tempHead->prev=temp;
            temp->next=tempHead;
            temp->prev= nullptr;
            Head=temp;
        }
        else {
            if(index==length+1){
                Node *temp = new Node(str);
                Node *tempTail = Tail;
                tempTail->next=temp;
                temp->next= nullptr;
                temp->prev=tempTail;
                Tail=temp;
            }
            else {
                Node *temp = new Node(str);
                Node *tempHead = Head;
                for (int i = 1; i < index - 1; i++) {
                    tempHead = tempHead->next;
                }
                temp->next = tempHead->next;
                tempHead->next->prev = temp;
                tempHead->next = temp;
                temp->prev = tempHead;
                length++;
            }
        }
    }
}
void LinkedList::pushBack(const char* str)
{
    Node *temp = new Node(str);
    if (!Head) {
        Head = temp;
        Tail = temp;
        Head->prev= nullptr;
        Head->next=nullptr;
        Tail->prev= nullptr;
        Tail->next=nullptr;
    }
    else {
        if(Head->surname==Tail->surname){
            temp->next = nullptr;
            temp->prev = Head;
            Tail = temp;
            Head->next=Tail;
        }else {
            temp->next = nullptr;
            temp->prev = Tail;
            Tail->next=temp;
            Tail = temp;
        }
    }
    length++;

}
void LinkedList::showList()
{
    if (Head != nullptr)
    {
        Node* temp = Head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
        delete[] temp;
    }
    else
    {
        cout << "Empty" << endl;
    }
}
void LinkedList::writeToFile(const char* fileName)
{
    FILE *f1;
    f1 = fopen(fileName, "w");
    Node* tempHead = Head;
    while (tempHead != nullptr)
    {
        fprintf(f1, "%s\n", tempHead->surname);
        tempHead = tempHead->next;
    }

    fclose(f1);
    delete[] tempHead;
}
int main() {
   char fileName[1000]={"test.txt"};
    cout<<"Task 1.\n";
    task1(fileName);
    cout<<"The result was written to the <<result>> file\n";
    cout<<"Task 2.\n";
    int number=123;
   task2(number);
    cout<<"\nThe result was written to the <<task_2>> file\n";
    cout<<"Task 3.\n";
    char line[160]={"0x31 0x31 0x31 0x31 0x30 0x30 0x30 0x30 0x31 0x31 0x31 0x31"};
    task3(line);
    cout<<"\nTask 5.\n";
    int M=5;
    int N=3;
float array[M][N];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array[i][j] = rand() % 50;
        }
    }
    cout<<"The original matrix:\n";
    for(int i=0;i<M;i++) {
        for (int j = 0; j < N; j++) {
            cout << array[i][j]<< "\t";
        }
        cout<<"\n";
    }
    cout<<"Average row values:\n";
    task5(*array,M,N);
    cout<<"Task 6,7.\n";
cout<<"Student Chepik was added to the list for the 3rd position\n";
LinkedList lst;
lst.pushBack("Ivanov");
lst.pushBack("Petrov");
lst.pushBack("Ryazanov");
lst.pushBack("Pozhalostin");
lst.showList();
lst.insertTo(3,"Chepik");
lst.showList();
lst.pushBack("Gagarin");
lst.showList();
lst.writeToFile("task_6");
cout<<"The result was written to the <<task_6>> file\n";
    return 0;
}
