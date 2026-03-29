#appraoch 
1. we can do any of trversal but question demand constant space complexity which is not
2. possible by them so we will use morrise traversal
3. for that we start a loop till curr != NULL
4. and now the second step is if curr -> left exist create predecesssro and mark it curr left
5. and after one left just minve right till pred-> right not became null
6. if it became null make pred ->right point to curr->right
7. and curr->right to curr left and curr left to NULL

8. at last after if curr = curr->right and this is it 
