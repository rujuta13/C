int getHeight(struct node* root) {
    //if tree empty or only root
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    int lHeight = getHeight(root -> left);
    int rHeight = getHeight(root -> right);
    
    //max height is the height
    if(lHeight >= rHeight)
        return lHeight + 1;
    else 
        return rHeight + 1;
}
