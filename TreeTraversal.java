class Node{
    int key;
    Node left, right;

    public Node(int item){
        key = item;
        left = right = null;
    }
}
class TreeTraversal{
    // Node of Binary Tree
    Node root;

    TreeTraversal(){
        root = null; // is this intializing right?
    }
}