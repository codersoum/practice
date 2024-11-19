import java.util.List;

public class Quicksort 
{
	 public static int[][] construct2DArray(int[] original, int m, int n) 
	    {
	      int[][] ans=new int[m][n];
	      int k=0;
	      if(m*n==original.length)
	      {
	         for(int i=0;i<m;i++)
	         {
	          for(int j=0;j<n;j++)
	          {
	           ans[i][j]=original[k++];
	          }
	         }
	      }
	       return ans;
	    }
	 public static void main(String[] args)
	 {
		int m=2;
		int n=2;
		int [] original= {1,2,3,4};
		int[][] res=construct2DArray(original, m, n);
		System.out.println(res);
	 }
}
