#include<stdio.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}


int isEmpty(node_t **head) {
	if (*head == NULL) return 1;
	else return 0;
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

void dfs_tree(int graph[7][7], int v,int n, int visited[]) {
	visited[v]=1;
	int i;
	for(i=1;i<=n;i++){
		if(graph[v][i] ==1 && visited[i]==0) {
			dfs_tree(graph,i,n,visited);
		}
	}
}

int dfs(int graph[7][7], int v,int n){
	int i;
	int visited[n+1];
	for(i=0;i<=n;i++){visited[i]=0;}
	
	dfs_tree(graph, v,n, visited);
	for(i=1;i<=n;i++){
		if(visited[i] == 0){
			return 0;
		}
	}
	return 1;	
}

int bfs(int graph[7][7], int v, int n) {
	int visited[n+1];	
	int i=0;
	for(i=0;i<=n;i++){visited[i]=0;}
	node_t *head = NULL;
	enqueue(&head, v);
	int node;
	while (!isEmpty(&head)) {
		node = dequeue(&head);
		visited[node]=1;
		for(i = 1; i <= n; i++){
        	if(graph[node][i] > 0 && visited[i] == 0) {
        		visited[i] = 1;
        		enqueue(&head, i);
			}
		}	
	}
	for(i=1;i<=n;i++){
		if(visited[i] == 0){
			return 0;
		}
	}
	return 1;
}
int main() {
	int adj[7][7] = {
		{0,0,0,0,0,0,0},	
		{0,1,1,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,0,0,1,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,0,0,1,1,1},
		{0,1,0,0,0,0,1}
		};
	int v=1;
	int n=6;
	printf("Algo: BFS \n");
	for (v=1;v<=n;v++){
		printf("Starting Vertex: %d \n", v);
		if(bfs(adj,v,n)){
			printf("Root Vertex is: %d \n",v);
		}
	}
    printf("Algo: DFS \n");
	for(v=1;v<=n;v++){
		printf("Starting Vertex: %d \n", v);
		if(dfs(adj,v,n)){
			printf("Root Vertex is: %d \n",v);
		}
	}
}

