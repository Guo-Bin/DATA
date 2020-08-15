/*
    1997 East-Central ACM regional programming contest
    Held on November 8, 1997

    Is It A Tree? -- Problem 2

    Sample solution by Ed Karrels, Ed@tool.com
    November 1997
*/
#include <stdio.h>

/*
    The node numbers are not necessarily sequential and starting
    with 1.  Keep a list of all the node numbers used so far
    in each case, and assign them indices from 0 to n-1
*/
struct NodeNum {
    int num;
    NodeNum *next;
};
NodeNum *node_num_list = 0;

/*
    Keep a list of all the edges
*/
struct Edge {
    int from, to;
    Edge *next;
    Edge(int f, int t);
};
Edge *edge_list;


    // reset the node list
void ClearNodeNumList() {
    NodeNum *p = node_num_list, *q;
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }
    node_num_list = new NodeNum;
    node_num_list->next = 0;
    node_num_list->num = -42;
}


    // generate an index for a node number; might be a node already
    // assigned an index
int GetNodeNum(int n) {
    NodeNum *p = node_num_list;
    int c = 0;
    while (p->next) {
        p = p->next;
        if (p->num == n) return c;
        c++;
    }
    p->next = new NodeNum;
    p = p->next;
    p->num = n;
    p->next = 0;
    return c;
}


    // return the number of nodes
int NumNodes() {
    NodeNum *p = node_num_list->next;
    int c = 0;
    while (p) {
        c++; p = p->next;
    }
    return c;
}

    // defined just for simplicity
Edge::Edge(int f, int t) {
    from = GetNodeNum(f);
    to = GetNodeNum(t);
}


    // count how many edges are directed to this node
int NumEdgesTo(Edge *p, int node_no) {
    int c = 0;
    while (p) {
        if (p->to == node_no) c++;
        p = p->next;
    }
    return c;
}


    // visit this node and all the nodes it points to
    // when visiting, increment counter in visted[] so we
    // can see how many times the node was visited
void Visit(Edge *edge_list, int node, int visited[]) {
    Edge *p = edge_list;
    visited[node]++;
    while (p) {
        if (p->from == node) {
            Visit(edge_list, p->to, visited);
        }
        p = p->next;
    }
}


    // return 1 if the edge list describes a tree, 0 otherwise
int IsATree(Edge *edge_list) {
    int n_nodes = NumNodes();
    int i, root_node = -1;
    int n_edges_to;

        // if the structure is empty, it's a list
    if (n_nodes == 0) return 1;

    for (i=0; i<n_nodes; i++) {
        n_edges_to = NumEdgesTo(edge_list, i);
            // if there are no edges to this, it's a root node
        if (n_edges_to == 0) {
            if (root_node == -1) {
                root_node = i;
            } else {
                    // if a root node has already been found, die--
                    // can't have more than one root
                return 0;
            }
        } else if (n_edges_to != 1) {
                // can't have more than one edge to any node
            return 0;
        }
    }
        // if no root exists, is not a tree
    if (root_node == -1) return 0;

        // create an array that will note how many times each
        // node was visited
    int *visited = new int[n_nodes];
    for (i=0; i<n_nodes; i++) visited[i] = 0;

        // starting at the root, visit every node recursively
    Visit(edge_list, root_node, visited);

        // make sure every node was visited exactly once
    for (i=0; i<n_nodes; i++) {
        if (visited[i] != 1) {
            delete[]visited;
            return 0;
        }
    }

    delete[]visited;
    return 1;
}


int main() {
    int case_no = 1;
    int from, to;
    // FILE *inf = fopen("prob_2.in", "r");
    FILE *inf = stdin;

    while (fscanf(inf, "%d %d", &from, &to), from != -1 || to != -1) {
            // reset the lists
        edge_list = 0;
        ClearNodeNumList();
            // read in the edge list
        while (from || to) {
            Edge *new_edge = new Edge(from, to);
            new_edge->next = edge_list;
            edge_list = new_edge;
            fscanf(inf, "%d %d", &from, &to);
        }

        int is_tree = IsATree(edge_list);
        printf("Case %d is %sa tree.\n", case_no++, is_tree ? "" : "not ");

            // erase the edge list; never know if the memory might be needed
        while (edge_list) {
            Edge *e = edge_list;
            edge_list = edge_list->next;
            delete e;
        }
    }
    return 0;
}
