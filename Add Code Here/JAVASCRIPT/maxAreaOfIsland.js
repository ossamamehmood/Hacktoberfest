/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let maxArea = 0 // maximum number of box used to make a big island
    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[0].length;j++){
            if(grid[i][j]==1){
                maxArea = Math.max(maxArea,findIsland(grid,i,j))
            }
        }
    }
    return maxArea;
    
};

var findIsland = function(grid,src,col){
    if(src<0 || col<0 || src==grid.length || col==grid[0].length || grid[src][col]==0)
        return 0;
    
    grid[src][col]=0
    let down = findIsland(grid,src+1,col)
    let up = findIsland(grid,src-1,col)
    let right = findIsland(grid,src,col+1)
    let left = findIsland(grid,src,col-1)

    return down+up+right+left+1;

}
