node * buildfromlevelorder(node * &root){
queue<node*> q;


cout << "enter data for root" << endl;
int data;
cin >> data;
q.push (root);
q.push(root);

while(!q.empty()){
node * temp = q.front();
q.pop();

cout << "enter left node for: " << root->data << endl;
int leftdata;
cin<< leftData;

if(leftData != -1){
temp-> left = new node(leftData);
q.push(temp->left);
}

cout << "enter right node for: " << root->data << endl;
int rightdata;
cin<< leftData;

if(rightData != -1){
temp-> right = new node(rightData);
q.push(temp->left);

}
}
