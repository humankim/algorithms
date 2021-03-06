import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    public Percolation(int n) throws IllegalArgumentException {              // create n-by-n grid, with all sites blocked
      if(n<=0)

    }
    public    void open(int row, int col) {  // open site (row, col) if it is not open already
    }
    public boolean isOpen(int row, int col) { // is site (row, col) open?
    }
    public boolean isFull(int row, int col) {  // is site (row, col) full?
    }
    public     int numberOfOpenSites() {      // number of open sites
    }
    public boolean percolates() {             // does the system percolate?
    }

    public static void main(String[] arg) {
        System.out.println("Hello Percolation!");
    }
}