#include <iostream>
using namespace std;
typedef struct Node* node;

struct Node{
    int data;
    Node* next;
};
node makenode(int x){
    node tmp= new Node();
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
bool empty(node a){
    return a==NULL;
}
int Size(node a){
    int cnt=0;
    while(a){
        a=a->next;
        ++cnt;
    }
    return cnt;
}
void insertFirst(node &a, int x){
    node tmp=makenode(x);
    if(a==NULL){
        a=tmp;
    }
    else{
        tmp->next=a;
        a=tmp;
    }
}
void insertAny(node &a, int x, int pos){
    node tmp=makenode(x);
    int n=Size(a);
    if(pos<=0 || pos>n+1){
        cout<<"INVALID/n"; return;}
    else if(pos==1){
        insertFirst(a,x); return;}
    node p=a;
    for(int i=1; i<pos-1; i++){
        p=p->next;
    }
    tmp->next=p->next;
    p->next=tmp;
}
void deleteFirst(node &a){
    if(a==NULL) return;
    a=a->next;
}
void deleteAny(node &a, int pos){
    if(pos<=0|| pos>Size(a)) return;
    node bef=NULL, aft=a;
    for( int i=1; i<pos; i++){
        bef=aft;
        aft=aft->next;
    }
    if(bef==NULL){
        a=a->next;}
    else{
        bef->next=aft->next;
    }
}
void out(node a){
	cout << "--------------------------------\n";
	while(a != NULL){
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
	cout << "--------------------------------\n";
}
int main(){
    int a=2;
    node head=makenode(a);
    int x; cin>>x;
    int p=2;
    insertAny(head,x,p);
    deleteAny(head,1);
    out(head);
    return 0;
}
