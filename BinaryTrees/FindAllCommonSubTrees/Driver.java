
public class Driver {

	public static void main(String[] args) {
		BinaryTree bt = new BinaryTree();
		bt.insert("",10);
		bt.insert("R", 5);
		bt.insert("L",5);
		bt.insert("LR", 6);
		bt.insert("LL",15);
		bt.insert("RL",15);
		bt.insert("RR", 6);
		bt.insert("RRL", 1);
		
		bt.insert("RRR", 7);
		bt.insert("LRR", 7);
		bt.insert("LRRL", 8);
		bt.insert("RRRL", 8);
		bt.insert("LRRR", 9);
		bt.insert("LRRRL", 3);
		bt.insert("LRRRLL", 2);
		bt.insert("LRRRLLL", 1);
		
		bt.insert("RRRR", 10);
		bt.insert("RRRRL", 3);
		bt.insert("RRRRLL", 2);
		bt.insert("RRRRLLL", 1);
		
		bt.print();
		bt.allSameBranches();
	}

}
