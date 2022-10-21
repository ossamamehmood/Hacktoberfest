public class MazeAllDirections {
    public static void main(String args[]){
        boolean[][] arr={
            {true,true,true},
            {true,true,true},
            {true,true,true}
        };
        recurse(arr,0,0,"");
    }
    static void recurse(boolean[][] maze,int r,int c,String p){
        if (r==2 && c==2){
            System.out.println(p);
            return ;
        }
        if (!maze[r][c]){
            return;

        }
        maze[r][c]=false;
        
        if (r<2){
            recurse(maze, r+1, c,p+"D");
        }
        if (c<2){
            recurse(maze, r, c+1,p+"R");
        }
        if (r>0){
            recurse(maze, r-1, c,p+"U");
        }
        if (c>0){
            recurse(maze, r, c-1,p+"L");
        }

        maze[r][c]=true;

    }
    
}