import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class BinaryTree {
	
	public Node root;
	private HashMap<Integer,Pair> hm = new HashMap<Integer, Pair>();
	private ArrayList<ArrayList<Integer>> sol = new ArrayList<ArrayList<Integer>>();
	BinaryTree()
	{
		root = null;
	}	
	
	public void allSameBranches()
	{
		hm.clear();
		sol.clear();
		walkLRR(root,0);
		for(int i=0;i<sol.size();i++)
			System.out.println(sol.get(i));
	}
	
	
    public void print()
	{
		print("",true,root);
	}
    
    public void insert(String s, int v)
	{
		if(root==null)
			root = new Node(v);
		else
			insert(s, root,v);
	}
    
	private void insert(String s, Node t, int v)
	{
		if(s.charAt(0)=='L')
		{
			if(t.left!=null)
				insert(s.substring(1, s.length()),t.left,v);
			else if(t.left==null && s.length()<=1)
				t.left = new Node(v);
			else if(s.length()>=1)
				System.out.println("ERROR: left index out of bounds. Invalid placement for tree node.");
		}
		else if(s.charAt(0)=='R')
		{
			if(t.right!=null)
				insert(s.substring(1, s.length()),t.right,v);
			else if(t.right==null && s.length()<=1)
				t.right = new Node(v);
			else if(s.length()>=1)
				System.out.println("ERROR: right index out of bounds. Invalid placement for tree node.");
		}
	}
	
	private void checkBranch(Node a, Node b, ArrayList<Integer> temp)
	{
		if(a.left==null && a.right == null && b.left == null && b.right == null && a.value == b.value)
		{
			temp.add(a.value);
			sol.add((ArrayList<Integer>) temp.clone());
			temp.remove(temp.size()-1);
		}
		else if(a.value == b.value)
		{
			temp.add(a.value);
			if(a.left!=null && b.left!=null)
				checkBranch(a.left,b.left,temp);
			if(a.right!=null && b.right!=null)
				checkBranch(a.right,b.right,temp);
	
		}
	}
	
	private void walkLRR(Node t, int h)
	{
		if(hm.get(t.value)!= null)
			if(hm.get(t.value).second == h)
				checkBranch(hm.get(t.value).first, t, new ArrayList<Integer>());
		
		hm.put(t.value,new Pair(t,h));
		
		
		if(t.left!=null)
			walkLRR(t.left,h);
		
		if(t.right!=null)
			walkLRR(t.right,h);
	}

    private void print(String prefix, boolean isTail, Node t) {
        System.out.println(prefix + (isTail ? "|____" : " |--- ") + t.value);
        if(t.left!=null)
            print(prefix + (isTail ? "    " : " |   "), false,t.left);
        if(t.right!=null)
            print(prefix + (isTail ? "    " : " |   "), false,t.right);
        if (t.left== null) 
        	return;
        if(t.right == null)
        	return;
    }
	
	
}
