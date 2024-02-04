import java.util.*;
public class imp {
    //public static final zz Scanner input = new Scanner(System.in);
    public static int add( int a, int b)
    {
        return a+b;
    }
    public static void main(String[] args) 
    {
        // Your code here
         Scanner iput = new Scanner(System.in);

         char[] a = new char[2];
         for (int i = 0; i < 2; i++)
         {
             a[i] = iput.nextLine().charAt(0);
         }

         System.out.println(a);
         iput.close();

    }   
}
