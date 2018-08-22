// Java implementation to find lowest common ancestor of
// n1 and n2 using one traversal of binary tree
// It also handles cases even when n1 and n2 are not there in Tree
 
/* Class containing left and right child of current node and key */

import java.util.ArrayList;
import java.util.List;

class Node{
    int data;
    Node left, right;

    Node(int value){
        data = value;
        left = right = null;
    }
}

public class BT_YesParentPtr_Solution2{
    Node root;
    Node findLCA(int n1, int n2){
        return findLCA(root, n1, n2);
    }
    /* This function returns pointer to LCA of two given
    values n1 and n2. This function assumes that n1 and n2
    are present in Binary Tree */
    Node findLCA(Node node, int n1, int n2)
    {
        // Base case
        if (node == null)
            return null;
 
        // If either n1 or n2 matches with root's key, report
        // the presence by returning root (Note that if a key is
        // ancestor of other, then the ancestor key becomes LCA
        if (node.data == n1 || node.data == n2)
            return node;
 
        // Look for keys in left and right subtrees
        Node left_lca = findLCA(node.left, n1, n2);
        Node right_lca = findLCA(node.right, n1, n2);
 
        // If both of the above calls return Non-NULL, then one key
        // is present in once subtree and other is present in other,
        // So this node is the LCA
        // 두 서브 트리에 그 노드가 있을 때 그러면 그걸 보낸 그 노드가 LCA가 되고
        if (left_lca!=null && right_lca!=null)
            return node;
 
        // Otherwise check if left subtree or right subtree is LCA
        // 만약에 한 서브트리에만 두 노드가 있다면 그 노드의 서브트리들 입장에서 양쪽에 하나씩 있을거니까
        // 그 서브트리의 루트를 리턴하겠지
        return (left_lca != null) ? left_lca : right_lca;
    }

    public static void main(String[] args){
        BT_NoParentPtr_Solution1 tree = new BT_NoParentPtr_Solution1();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);

        System.out.println("LCA(3, 4) is " + tree.findLCA(3, 4));
    }
}