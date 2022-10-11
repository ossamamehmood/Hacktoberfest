class AvlNode {
  public int data;
  public AvlNode left;
  public AvlNode right;
  public AvlNode parent;
  public int height;

  public AvlNode(int data) {
    this.data = data;
    this.left = null;
    this.right = null;
    this.parent = null;
    this.height = 0;
  }
}
public class Ques5 {
	public AvlNode root;

	  public Ques5() {
	    this.root = null;
	  }

	  public static int max(int a, int b) {
	    if(a > b)
	      return a;
	    return b;
	  }

	  public int height(AvlNode h) {
	    if(h == null)
	      return -1;
	    return h.height;
	  }

	  public AvlNode minimum(AvlNode x) {
	    while(x.left != null)
	      x = x.left;
	    return x;
	  }

	  public void lRotate(AvlNode x) {
	    AvlNode y = x.right;
	    x.right = y.left;
	    if(y.left != null) {
	      y.left.parent = x;
	    }
	    y.parent = x.parent;
	    if(x.parent == null) { 
	      this.root = y;
	    }
	    else if(x == x.parent.left) {
	      x.parent.left = y;
	    }
	    else { 
	      x.parent.right = y;
	    }
	    y.left = x;
	    x.parent = y;

	    x.height = 1 + max(height(x.left), height(x.right));
	    y.height = 1 + max(height(y.left), height(y.right));
	  }

	  public void rRotate(AvlNode x) {
	    AvlNode y = x.left;
	    x.left = y.right;
	    if(y.right != null) {
	      y.right.parent = x;
	    }
	    y.parent = x.parent;
	    if(x.parent == null) { 
	      this.root = y;
	    }
	    else if(x == x.parent.right) { 
	      x.parent.right = y;
	    }
	    else {
	      x.parent.left = y;
	    }
	    y.right = x;
	    x.parent = y;

	    x.height = 1 + max(height(x.left), height(x.right));
	    y.height = 1 + max(height(y.left), height(y.right));
	  }

	  public int balFactor(AvlNode f) {
	    if(f == null)
	      return 0;
	    return(height(f.left) - height(f.right));
	  }

	  public void insert(AvlNode n) {
	    AvlNode y = null;
	    AvlNode temp = this.root;
	    while(temp != null) {
	      y = temp;
	      if(n.data < temp.data)
	        temp = temp.left;
	      else
	        temp = temp.right;
	    }
	    n.parent = y;

	    if(y == null) 
	      this.root = n;
	    else if(n.data < y.data)
	      y.left = n;
	    else
	      y.right = n;

	    AvlNode z = n;

	    while(y != null) {
	      y.height = 1 + max(height(y.left), height(y.right));


	      AvlNode x = y.parent;

	      if(balFactor(x) <= -2 || balFactor(x) >= 2) {
	        if(y == x.left) {
	          if(z == x.left.left) 
	            rRotate(x);

	          else if(z == x.left.right) {
	            lRotate(y);
	            rRotate(x);
	          }
	        }
	        else if(y == x.right) {
	          if(z == x.right.right) 
	            lRotate(x);

	          else if(z == x.right.left) {
	            rRotate(y);
	            lRotate(x);
	          }
	        }
	        break;
	      }
	      y = y.parent;
	      z = z.parent;
	    }
	  }

	  public void transplant(AvlNode u, AvlNode v) {
	    if(u.parent == null) 
	      this.root = v;
	    else if(u == u.parent.left)
	      u.parent.left = v;
	    else 
	      u.parent.right = v;

	    if(v != null)
	      v.parent = u.parent;
	  }

	  public void avlDeleteFixup(AvlNode n) {
	    AvlNode p = n;

	    while(p != null) {
	      p.height = 1 + max(height(p.left), height(p.right));

	      if(balFactor(p) <= -2 || balFactor(p) >= 2) { 
	        AvlNode x, y, z;
	        x = p;

	       
	        if(x.left.height > x.right.height)
	          y = x.left;
	        else
	          y = x.right;

	        
	        if(y.left.height > y.right.height) {
	          z = y.left;
	        }
	        else if(y.left.height < y.right.height) {
	          z = y.right;
	        }
	        else {
	          if(y == x.left)
	            z = y.left;
	          else
	            z = y.right;
	        }

	        if(y == x.left) {
	          if(z == x.left.left)
	            rRotate(x);

	          else if(z == x.left.right) {
	            lRotate(y);
	            rRotate(x);
	          }
	        }
	        else if(y == x.right) {
	          if(z == x.right.right)
	            lRotate(x);

	          else if(z == x.right.left) {
	            rRotate(y);
	            lRotate(x);
	          }
	        }
	      }
	      p = p.parent;
	    }
	  }

	  public void delete(AvlNode z) {
	    if(z.left == null) {
	      transplant(z, z.right);
	      if(z.right != null)
	        avlDeleteFixup(z.right);
	    }
	    else if(z.right == null) {
	      transplant(z, z.left);
	      if(z.left != null)
	        avlDeleteFixup(z.left);
	    }
	    else {
	      AvlNode y = minimum(z.right);
	      if(y.parent != z) {
	        transplant(y, y.right);
	        y.right = z.right;
	        y.right.parent = y;
	      }
	      transplant(z, y);
	      y.left = z.left;
	      y.left.parent = y;
	      if(y != null)
	        avlDeleteFixup(y);
	    }
	  }

	  public void inorder(AvlNode n) {
	    if(n != null) {
	      inorder(n.left);
	      System.out.println(n.data);
	      inorder(n.right);
	    }
	  }

	  public static void main(String[] args) {
	    Ques5 n = new Ques5();

	    AvlNode a, b, c, d, e, f, g, h, i, j, k, l, m;
	    a = new AvlNode(9);
	    b = new AvlNode(18);
	    c = new AvlNode(24);
	    d = new AvlNode(95);
	    e = new AvlNode(89);
	    f = new AvlNode(37);
	    g = new AvlNode(41);
	    h = new AvlNode(58);
	    i = new AvlNode(63);
	    j = new AvlNode(75);
	    k = new AvlNode(143);
	    l = new AvlNode(107);
	    m = new AvlNode(116);

	    n.insert(a);
	    n.insert(b);
	    n.insert(c);
	    n.insert(d);
	    n.insert(e);
	    n.insert(f);
	    n.insert(g);
	    n.insert(h);
	    n.insert(i);
	    n.insert(j);
	    n.insert(k);
	    n.insert(l);
	    n.insert(m);

	    n.delete(f);
	    n.delete(l);

	    n.inorder(n.root);
	  }

}