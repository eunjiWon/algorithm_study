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

public class BT_NoParentPtr_Solution1{
    Node root;
    private List<Integer> path1 = new ArrayList<>();
    private List<Integer> path2 = new ArrayList<>();
    
    int findLCA(int n1, int n2){
        path1.clear();
        path2.clear();
        return findLCAInternal(root, n1, n2);
    }

    private int findLCAInternal(Node root, int n1, int n2){
        // 아래 둘 중 하나가 false가 나오면 끝남
        if(!findPath(root, n1, path1) || !findPath(root, n2, path2)){
            System.out.println((path1.size() > 0) ? "n1 is present" : "n1 is missing");
            System.out.println((path2.size() > 0) ? "n2 is present" : "n2 is missing");
            return -1;
        }
        int i;
        for(i = 0; i < path1.size() && i < path2.size(); i++){
            System.out.println("path1.get(i) is " + path1.get(i) + " path2.get(i)" + path2.get(i));
            if(!path1.get(i).equals(path2.get(i)))
                break; // 루트에서 바텀으로 가니까 처음엔 값이 같겠지, 두 값이 달라지는 순간에 포문을 빠져나온다
        }
        return path1.get(i - 1); 
    }

    private boolean findPath(Node root, int n, List<Integer> path){
        if (root == null) {
            return false;
        }
        path.add(root.data);
        if (root.data == n) { // 이게 패스 중에 n 이 있나 확인하는거니까 중요한 거였군
            return true;
        }
        //지금은 없더라도 남은 서브트리의 패스 중에 n 이 있을 수 있으니까 탐색한다
        if (root.left != null && findPath(root.left, n, path)) {
            return true;
        }
        if (root.right != null && findPath(root.right, n, path)) {
            return true;
        }
        path.remove(path.size()-1); // 이거 왜 하는지 잘 모르겠다.. 그 패스에 n 이 없으면 오른쪽이나 왼쪽 트리로 가야하니까 위에서 추가한거 삭제해줘야함
        return false;
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