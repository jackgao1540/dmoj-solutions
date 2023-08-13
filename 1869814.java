import java.util.*;
import java.io.*;

public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt(), p[] = new int[N+1], a[] = new int[N+1];
		List<Edge> e = new ArrayList();
		for(int i=1; i<=N; i++) {
			a[i] = readInt(); p[i] = i;
		}
		for(int i=1; i<=M; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			e.add(new Edge(u, v, w));
		}
		Collections.sort(e);
		int ans = -1;
		for(int i=1, j=0; i<=N; i++) {
			while(find_set(i, p) != find_set(a[i], p)) {
				int u = e.get(j).u, v = e.get(j).v, w = e.get(j).w;
				int fu = find_set(u, p), fv = find_set(v, p);
				if(fu != fv) p[fu] = fv; 
				ans = w; j++;
			}
		}
		System.out.println(ans);
	}
	static int find_set(int d, int p[]) {
		if(d != p[d]) p[d] = find_set(p[d], p);
		return p[d];
	}
	static class Edge implements Comparable<Edge> {
		int u, v, w;
		Edge(int u0, int v0, int w0) { u=u0; v=v0; w=w0; }
		public int compareTo(Edge x) { return -Integer.compare(w, x.w); }
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}