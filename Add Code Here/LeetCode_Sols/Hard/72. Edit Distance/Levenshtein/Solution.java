class Solution {
    public int minDistance(String word1, String word2) {
        int row = word1.length();
        int col = word2.length();
        int[][] ed = new int[row + 1][col + 1];
        for(int i = 0; i <= row; i++)
            ed[i][0] = i;
        for(int j = 0; j <= col; j++)
            ed[0][j] = j;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    ed[i][j] = ed[i - 1][j - 1];
                } else {
                    int dia = ed[i - 1][j - 1];
                    int hor = ed[i][j - 1];
                    int ver = ed[i - 1][j];
                    if(dia <= hor && dia <= ver)
                        ed[i][j] = dia;
                    else 
                        ed[i][j] = ver < hor ? ver : hor;
                    ed[i][j]++;
                }
            }
        }
        return ed[row][col];
    }
}
