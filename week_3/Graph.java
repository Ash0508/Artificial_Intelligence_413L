import java.util.*;

class Graph{
    public int numberOfVertices;
    public int numberOfEdges;

    private Map<Integer, List<Integer> > map = new HashMap<>();
    Graph(int v,int e){
        numberOfEdges = e;
        numberOfVertices = v;
    }
    public void addVertex(int v){
        map.put(v, new ArrayList<>());
    }
    public void addEdge(int a, int b){
        if (!map.containsKey(a))
            addVertex(a);
 
        if (!map.containsKey(b))
            addVertex(b);
 
        map.get(a).add(b);
        map.get(b).add(a);
    }
    public void getVertexCount()
    {
        System.out.println("The graph has " + map.keySet().size() + " vertex");
    }
    public String adjacencyLists()
    {
        StringBuilder builder = new StringBuilder();
 
        for (int v : map.keySet()) {
            builder.append(v.toString() + ": ");
            for (int w : map.get(v)) {
                builder.append(w.toString() + " ");
            }
            builder.append("\n");
        }
 
        return (builder.toString());
    }
    public void adjacencyMatrix(){
        Map<Integer,Integer> indexMap = new HashMap<>();
        int x = 0;
        for (int v: map.keySet()){
            indexMap.put(v, x);
            x++;
        }
        int arr[][] = new int[map.size()][map.size()];
        int i=0,j=0;
        for(i=0;i<map.size();i++){
            for(j=0;j<map.size();j++){
                arr[i][j]=0;
            }
        }
        for (int v : map.keySet()) {
            j=0;
            for (int w : map.get(v)) {
                arr[indexMap.get(v)][indexMap.get(w)] = 1;
            }
            i++;
            
        }
        System.out.println("Adjacency Matrix : ");
        for(i=0;i<map.size();i++){
            for(j=0;j<map.size();j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        
    }
    public void RightToLeft(int source){
        Map<Integer,Boolean> visited = new HashMap<Integer,Boolean>();
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(source);
        for(int v: map.keySet()){
            visited.put(v, false);
        }
        q.add(source);
        while(!q.isEmpty()){
            int s = q.poll();
            if(!visited.get(s)){
                    System.out.print(s+" ");
            }
            visited.replace(s, false, true);
            List<Integer> adjacent = map.get(s);
            for(int i=adjacent.size()-1;i>=0;i--){
                if(visited.get(adjacent.get(i))){
                    break;
                }
                q.add(adjacent.get(i));
            }
        }
        for(int v: visited.keySet()){
            if(!visited.get(v)){
                System.out.print(v + " ");
                visited.replace(v, false, true);
            }
        }
    }
    public void LeftToRight(T source){
        Map<Integer,Boolean> visited = new HashMap<Integer,Boolean>();
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(source);
        for(Integer v: map.keySet()){
            visited.put(v, false);
        }
        q.add(source);
        while(!q.isEmpty()){
            int s = q.poll();
            if(!visited.get(s)){
                    System.out.print(s+" ");
            }
            visited.replace(s, false, true);
            List<Integer> adjacent = map.get(s);
            for(int w: adjacent){
                if(visited.get(w)){
                    break;
                }
                q.add(w);
            }
        }
        for(int v: visited.keySet()){
            if(!visited.get(v)){
                System.out.print(v + " ");
                visited.replace(v, false, true);
            }
        }
        
    }

}

public class LevelOrderTraversal {
    public static void main(String[] args){
        int vertices;
        int edges;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices : ");
        vertices = sc.nextInt();
        System.out.println("Enter the number of edges : ");
        edges = sc.nextInt();
        Graph<Integer> gm = new Graph(vertices,edges);
        System.out.println("Graph has the following nodes : ");
        for(int i=0;i<vertices;i++){
            System.out.print(i+" ");
            gm.addVertex(i);
        }
        System.out.println();
        
        
        System.out.println("Insert edges (a b): ");
        for(int i=0;i<edges;i++){
            int a,b;
            a=sc.nextInt();
            b=sc.nextInt();
            gm.addEdge(a, b);
        }
        System.out.println(gm.adjacencyLists());
        int s;
        System.out.print("Enter the source node : ");
        s = sc.nextInt();
        gm.RightToLeft(s);
    }
    
}
