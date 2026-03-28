#appraoch 
this is a way of inorder tranversal
so you have do give output of inorder but by different way 
space complexity is o(1) in this case 
to do this make a vector ans in which you return answer
and make curr node and point it to root 
while curr != NULLyou have to start a loop
  now you have two options first
  if curr->left == NULL
  push curr in answer 
  answer and curr = curr->right;
  else predeccesor name ka node banno waha ek left fir sirf right lena hai 
  left le lo 
  aur fir while pred-> right != NULL nahi tab tak 
  pred ko pred ->right lete ja00
  agar abb pred ->right null ho gaya hai to crete  a thread 
  pred-> right ko current se 
  and now curr ko mive kar do curr left me 
  else remove the thread how 
  pred->right == NULL and answer me curr-> val dalo 

   
    }
};
