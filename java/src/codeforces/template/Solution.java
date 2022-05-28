package codeforces.template;
import  java.util.* ;
import java.io.* ;


public class Solution {
    public static void main(String[] args) {
        FastScanner fs = new FastScanner() ;
        int  n = fs.nextInt();
//        while(t-- != 0) Solve() ;
        System.out.println(n % 2 ==  0 ? "YES" : "NO");
        return ;
    }
    static void Solve(){

    }
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {}
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }

}
