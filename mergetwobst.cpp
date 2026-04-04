void convertIntoSortedDLL(TreeNOde<int> *root, TreeNode<int>* & head){
  //base case 
if(root==NULL){
return NULL;
}
convertIntoSortedDLL(root->right, head);
root->right = head;
if(head != NULL){
head ->left = root;
}
head = root;
convertIntoSortedDLL(root->left, head);
}
TreeNode<int> mergeLinkList(TreeNode<int> *head1, TreeNode<int> *head2){
  TreeNode<int> *head = NULL:
  TreeNode<int> *tail = NULL;
while(head !!= NULL && head2 != NULL){
if(head->data < head2->data){
if(head == NULL){
  head = head1;
  tail= head1;
  head1 = head1->right;
}
else{
  tail->right = head1;
  head1->left = tail;
  tail = head1;
  head1 = head1->right;
  
}
}
else{
if(head==NULL){
  head = head2;
  tail = head2;
  head1= head2->right;
}
else{
tail->right = head2;
head2->left = tail;
tail= head2;
head2 = head2->right;
}
}
}
while(head!=NULL){
tail->right = head1;
head1->left= tail;
tail= head1;
head1= head1->right;
}
while(head2!=NULL){
tail->right = head2;
head2->left = tail;
tail= head2;
head2 = head2->right;
}
return head;
}
int countNodes(TreeNOde<int> *head){
  int cnt = 0;
TreeNod<int> *temp = head;
while(temp!= NULL){
cnt++;
temp = temp->right;
}
return cnt;
}
TreeNOde<int> * sortedLLToBST(TreeNode<int> * &head, int n){
  //basecase 
  if(n<=0 || root == NULL)
{
return NULL;
}
  TreeNode<int> *root = head;
  root->left = left;
  head - head ->next;
  root->right = sorted::ToBST(head, n-n/2-1);
  return root;
}

}
TreeNode<int> mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2){
  TreeNode<int> *head= NULL;
  TreeNode<int> *tail = NULL;
  while(head1 != NULL && head2 !=NULL){
    if(head1->data< head2->data){
      ifhead== NULL){
        head= head1;
        tail= head1;
        head1= head1->right;
      }
      else{
        tail->right = head1;
        head1->left =tail;
        tail = head1;
        head1= head1->right;
      }
    }

    
}
TreeeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
//step1 convert bst into sorted Bll in-place
  TreeNode<int> *head1 = NULL;
convertIntoSortedDLL(root1, head1);
head1->left = NULL;
TreeNide<int> *head2 = NULL;
convertIntoSortedDLL(root2, head2);
head1->left= NULL;
//step2 :merge sorted linked list
TreeNdoe<int> *head = mergeLinkList(head1,head2);
//step3: convert sLL into bst
return sortedLLToBST(head, countNodes(head));


  
