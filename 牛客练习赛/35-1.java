import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		int t;
		BigInteger n;
		Set<BigInteger> st = new HashSet<BigInteger>();
		BigInteger maxi = new BigInteger("4000000000000000000");
		List<String> lk = new LinkedList<String>();
		BigInteger i = new BigInteger("2");
		BigInteger r = new BigInteger("2");

		// generate linkedlist
		while (i.compareTo(maxi) < 0) {
			lk.add(i.toString());
			i = i.multiply(r);
		}
		int len = lk.size();

		// to bigint arraylist
		List<BigInteger> ls = new ArrayList<BigInteger>(len);
		for (String str : lk) {
			ls.add(new BigInteger(str));
		}

		// generate set
		for (int j = 0; j < len - 1; j++) {
			BigInteger bj = ls.get(j);
			st.add(bj.add(bj));
			for (int k = j + 1; k < len; k++) {
				BigInteger bk = bj.add(ls.get(k));
				st.add(bk);
			}
		}

		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		while (t-- != 0) {
			n = in.nextBigInteger();
			// System.out.println(N);
			if (st.contains(n))
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}

}
