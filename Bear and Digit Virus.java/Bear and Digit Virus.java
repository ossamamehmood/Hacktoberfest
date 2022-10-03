import java.io.OutputStream;

import java.io.IOException;

import java.io.InputStream;

import java.io.OutputStream;

import java.io.PrintWriter;

import java.util.Arrays;

import java.io.BufferedWriter;

import java.io.Writer;

import java.io.OutputStreamWriter;

import java.util.InputMismatchException;

import java.io.IOException;

import java.io.InputStream;



/**

 * Built using CHelper plug-in

 * Actual solution is at the top

 */

public class Main {

    public static void main(String[] args) {

        InputStream inputStream = System.in;

        OutputStream outputStream = System.out;

        InputReader in = new InputReader(inputStream);

        OutputWriter out = new OutputWriter(outputStream);

        AffectedDigits solver = new AffectedDigits();

        int testCount = Integer.parseInt(in.next());

        for (int i = 1; i <= testCount; i++)

            solver.solve(i, in, out);

        out.close();

    }



    static class AffectedDigits {

        public void solve(int testNumber, InputReader in, OutputWriter out) {

            char[] s = in.next().toCharArray();

            int n = s.length;

            int mx = 0;

            for (int i = 0; i < n; i++) mx = Math.max(mx, s[i] - '0');

            int k = mx + 1;

            boolean[] vis = new boolean[n * k];

            int[] queue = new int[n * k];

            int[] dist = new int[n * k];

            Arrays.fill(dist, n * k + 1);

            int front = 0, back = 0;

            for (int i = 0; i < n; i++) {

                int node = i * k + (s[i] - '0');

                queue[back++] = node;

                dist[node] = 0;

                vis[node] = true;

            }

            int[][] cp = new int[n][k];

            int[] cf = new int[n], cb = new int[n];

            for (int i = 0; i < n; i++) cp[i][cb[i]++] = s[i] - '0';

            while (front < back) {

                int cur = queue[front++];

                int pos = cur / k, val = cur % k;

                for (int i = pos - val; i <= pos + val; i++) {

                    if (i < 0 || i >= n) continue;

                    int d = Math.abs(pos - i);

                    int to = i * k + val;

                    if (vis[to]) continue;

                    while (cf[i] + 1 < cb[i] && dist[i * k + cp[i][cf[i] + 1]] <= dist[cur]) cf[i]++;

                    int cval = cp[i][cf[i]];

                    if (cval <= val - d) {

                        vis[to] = true;

                        dist[to] = dist[cur] + 1;

                        queue[back++] = to;

                        cp[i][cb[i]++] = val;

                    }

                }

            }



            int ret = 0;

            for (int i = 0; i < n; i++) {

                ret = Math.max(ret, dist[i * k + mx]);

            }

            out.println(ret);

        }



    }



    static class InputReader {

        private InputStream stream;

        private byte[] buf = new byte[1024];

        private int curChar;

        private int numChars;



        public InputReader(InputStream stream) {

            this.stream = stream;

        }



        public int read() {

            if (this.numChars == -1) {

                throw new InputMismatchException();

            } else {

                if (this.curChar >= this.numChars) {

                    this.curChar = 0;



                    try {

                        this.numChars = this.stream.read(this.buf);

                    } catch (IOException var2) {

                        throw new InputMismatchException();

                    }



                    if (this.numChars <= 0) {

                        return -1;

                    }

                }



                return this.buf[this.curChar++];

            }

        }



        public String next() {

            int c;

            while (isSpaceChar(c = this.read())) {

                ;

            }



            StringBuilder result = new StringBuilder();

            result.appendCodePoint(c);



            while (!isSpaceChar(c = this.read())) {

                result.appendCodePoint(c);

            }



            return result.toString();

        }



        public static boolean isSpaceChar(int c) {

            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;

        }



    }



    static class OutputWriter {

        private final PrintWriter writer;



        public OutputWriter(OutputStream outputStream) {

            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));

        }



        public OutputWriter(Writer writer) {

            this.writer = new PrintWriter(writer);

        }



        public void close() {

            writer.close();

        }



        public void println(int i) {

            writer.println(i);

        }



    }

}

