import java.util.Scanner;
import java.util.Vector;
 
class Node
{
    int             name; // node ID, started from 0 to n-1
    Vector<Integer> preds; // predecessors (String)
    Vector<Integer> neibs; // neighbors (String)
    Vector<Integer> backs; // backward edges -node is end vertex (Integer)
    Vector<Integer> fors; // forward edges -node is start vertex (Integer)
    int             pNode; // previous node on the augmenting path
    int             pEdge; // from which edge this node comes on the augmenting
                           // path
 
    public Node(int id)
    {
        name = id;
        backs = new Vector<Integer>();
        fors = new Vector<Integer>();
        pNode = -1;
        pEdge = -1;
    }
}
 
class Edge
{
    int name;    // edge ID, started from 0 to n-1
    int start;   // start vertex of this edge
    int end;     // end vertex of this edge
    int direct;  // forwards (+1) or backwards (-1) on augmenting path
                  // if 0 then not part of augmenting path
    int capacity; // capacity
    int flow;    // current flow
 
    public Edge(int id)
    {
        name = id;
        start = -1;
        end = -1;
        direct = 0; // default is neither
        capacity = 0;
        flow = 0;
    }
 
    public String toString()
    {
        return name + ": s=" + start + " e=" + end + " d=" + direct;
    }
}
 
class LongestPathinDAG
{
    int    n;                      // number of nodes
    int    target;                 // destination node
    int    minLength;              // the minimal length of each path
    Node[] v;                      // used to store Nodes
    Edge[] e;                      // used to store Edges
    int[]  path;                   // used to store temporary path
    int    length       = 0;       // length of the path
    int    distance     = 0;       // distance of the path
    int[]  bestPath;               // used to store temporary path
    int    bestLength   = 0;       // length of the longest path
    int    bestDistance = -1000000; // distance of the longest path
    int[]  visited;                // used to mark a node as visited if set as
    static int    pStart = 0;
    static int    pEnd = 0;
                                    // 1
 
    public LongestPathinDAG()
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();//n
        int m = sc.nextInt();//m
        v = new Node[n+1];
        e = new Edge[m+1];
        pStart = sc.nextInt();  //A
        pEnd = sc.nextInt();    //B
        for (int i = 0; i <= n; i++)
            v[i] = new Node(i);
        int i = 0;
        while (i < e.length)
        {
            Edge edge = new Edge(i);
            int sVal = sc.nextInt();
            edge.start = sVal;// sc.nextInt();
            int eVal = sc.nextInt();
            edge.end = eVal;// sc.nextInt();
            edge.capacity = 1;
            edge.flow = 0;
            e[i] = edge;
            v[sVal].fors.add(i);
            v[eVal].backs.add(i);
            i++;
            if (i == m)
                break;
        }
        visited = new int[v.length];
        path = new int[v.length];
        bestPath = new int[v.length];
        sc.close();
    }
 
    /*
     * this function looks for a longest path starting from being to end,
     * using the backtrack depth-first search.
     */
    public boolean findLongestPath(int begin, int end, int minLen)
    {
        /*
         * compute a longest path from begin to end
         */
        target = end;
        bestDistance = -100000000;
        minLength = minLen;
        dfsLongestPath(begin);
        if (bestDistance == -100000000)
            return false;
        else
            return true;
    }
 
    private void dfsLongestPath(int current)
    {
        visited[current] = 1;
        path[length++] = current;
        if (current == target && length >= minLength)
        {
            if (distance > bestDistance)
            {
                for (int i = 0; i < length; i++)
                    bestPath[i] = path[i];
                bestLength = length;
                bestDistance = distance;
            }
        }
        else
        {
            Vector<Integer> fors = v[current].fors;
            for (int i = 0; i < fors.size(); i++)
            {
                Integer edge_obj = (Integer) fors.elementAt(i);
                int edge = edge_obj.intValue();
                if (visited[e[edge].end] == 0)
                {
                    distance += e[edge].capacity;
                    dfsLongestPath(e[edge].end);
                    distance -= e[edge].capacity;
                }
            }
        }
        visited[current] = 0;
        length--;
    }
 
    // public String toString()
    // {
    //     String output = "v" + bestPath[0];
    //     for (int i = 1; i < bestLength; i++)
    //         output = output + " -> v" + bestPath[i];
    //     return output;
    // }
 
    public static void main(String arg[])
    {
        LongestPathinDAG lp = new LongestPathinDAG();
        /*
         * find a longest path from vertex 0 to vertex n-1.
         */
        // if (lp.findLongestPath(0, lp.n - 1, 1))
        //     System.out.println("Longest Path is " + lp
        //             + " and the distance is " + lp.bestDistance);
        // else
        //     System.out.println("No path from v0 to v" + (lp.n - 1));
        /*
         * find a longest path from vertex 3 to vertex 5.
         */
        if (lp.findLongestPath(pStart-1, pEnd-1, 1))
            System.out.println(lp.bestDistance);
    }
}