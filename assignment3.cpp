#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void Enqueue(Node** ptrToHead, Node** ptrToTail, int x){
    //Node* trackerArray[2];
    //trackerArray[0] = head;
    //trackerArray[1] = tail;
    //I included these to show my thinking process... I was originally trying to return an array...
    //The idea was to set head and tail to the array but instead pointers to pointers works better
    //I found out quickly that returning more than one value in C++ gets tricky...
    Node* temp = new Node();
    Node* copy = new Node();
    temp ->data = x;
    temp ->next = NULL;
    if(* ptrToHead == NULL && * ptrToTail == NULL){
        * ptrToHead = * ptrToTail = temp; //This points everything to first node
        return;
    }
    copy = * ptrToHead; //This code almost gets ran everytime so not optimal...
    if(* ptrToHead == * ptrToTail){
        copy ->next = temp;
    }
    else{
        copy = *ptrToTail;
        copy ->next = temp;
    }
    * ptrToTail = temp; //tail should now be pointing at newest node
}

int Dequeue(Node** ptrToHead){
    Node* temp = * ptrToHead;
    Node* copy = new Node();
    copy->data = temp ->data;
    copy ->next = temp ->next;
    if(* ptrToHead == NULL){
        cout << "Queue is empty" << endl;
        return copy->data;
    }
    else{
        *ptrToHead = copy ->next;
    }
    free(temp);
    return copy->data; //not sure why returning the value is necessary but I did include it to meet project requirements...
}

int Peek(Node* head){
    Node* temp = head;
    if(temp == NULL){
        cout << "Queue is empty" << endl;
    }
    cout << "The first value in the queue is: " << temp ->data << endl;
    return temp ->data;
}

void Print(Node* head) {
	Node* temp = head;
    cout << "Queue currently is: " << endl;
	while(temp != NULL) {
		cout << temp ->data << " ";
        temp = temp->next;
	}
	cout << "\n";
}

int main(){
    Node * head = NULL;
    Node * tail = NULL;
    Enqueue(&head, &tail, 2);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Enqueue(&head, &tail, 4);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Enqueue(&head, &tail, 6);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Peek(head); //it works but didn't really need it...
    Enqueue(&head, &tail, 8);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Enqueue(&head, &tail, 10);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Dequeue(&head);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Dequeue(&head);
    Print(head);
    cout << "The tail is pointing at: " << tail << " (" << tail->data << ")" << endl;
    cout << "The head is pointing at: " << head << " (" << head->data << ")" << endl;
    Enqueue(&head, &tail, 12);
    Print(head);
    Enqueue(&head, &tail, 14);
    Print(head);
    Peek(head);
}
//I know the print statements are a little overkill but it was just to make sure I didn't mess up the scope and that the pointers were working the way I intended...