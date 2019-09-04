package com.company;
import java.util.*;

public class level_order_traversal {
    static class Node
    {
        int data;
        Node left, right;
        Node(int item)
        {
            data = item;
            left = right = null;
        }
    }
      static void levelOrder(Node node) {
          Queue<Node> q = new LinkedList<>();
          q.add(node);

          while (!q.isEmpty()) {
              Node temp = q.poll();

              if (temp.left != null)
                  q.add(temp.left);

              if (temp.right != null)
                  q.add(temp.right);

              System.out.print(temp.data + " ");
          }
      }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        HashMap<Integer, Node> m = new HashMap<Integer, Node> ();
        int n = sc.nextInt();
        Node root=null;
        while (n > 0)
        {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            char lr = sc.next().charAt(0);
                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
            Node parent = m.get(n1);
            if (parent == null)
            {
                parent = new Node(n1);
                m.put(n1, parent);
                    if (root == null)
                        root = parent;
            }
            Node child = new Node(n2);
            if (lr == 'L')
                parent.left = child;
            else
                parent.right = child;

            m.put(n2, child);
                n--;
            }

            level_order_traversal g = new level_order_traversal();
            g.levelOrder(root);
            System.out.println();

    }
}

