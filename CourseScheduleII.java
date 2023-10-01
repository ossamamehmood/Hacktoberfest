class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {

        List<List<Integer>> graph = new ArrayList<>();

        for(int i=0; i<numCourses; i++){
            graph.add(new ArrayList<>());
        }

        int indegree [] = new int[numCourses];

        for(int prerequisite[] : prerequisites){
            int courseA = prerequisite[0];
            int courseB = prerequisite[1];

            graph.get(courseB).add(courseA);

            indegree[courseA]++;
        }


        Queue<Integer> q = new LinkedList<>();

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.add(i);
            }
        }

        // bfs

        int ans [] = new int[numCourses];

        

        int k = 0;

        while(!q.isEmpty()){
            int course = q.remove();

            ans[k++] = course;

            // decrease indegree of neighbour


            for(int neighbour : graph.get(course)){

                indegree[neighbour]--;

                if(indegree[neighbour] == 0){
                    q.add(neighbour);
                }

            }
        }

        if(k == numCourses){
            return ans;
        }

        else{
            return new int[0];
        }
        
    }
}
