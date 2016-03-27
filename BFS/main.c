#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int num_enq = 0;
typedef struct entity {
    int node;
    int cost;
    int parent;
} entity_t;

typedef struct Q {
    entity_t ent;
    struct Q *next;
} Q_t;

Q_t *head, *rear;

void init_q()
{
    head = rear = NULL;
}

void enq(entity_t el)
{
    if (rear == NULL) {
	rear = (Q_t *)malloc(sizeof(Q_t));
	if (rear == NULL) {
		printf("Memory full. Cannot proceed\n");
		exit(0);
	}

	rear->ent = el;
	rear->next = NULL;
	head = rear;
	return ;
    }
    rear->next = (Q_t *)malloc(sizeof(Q_t));
    if (rear->next == NULL) {
          printf("Memory full. Cannot proceed\n");
	  exit(0);
    }

    rear = rear->next;
    rear->ent = el;
    rear->next = NULL;
}

entity_t deq()
{
    entity_t ent;
    Q_t *tmp;
    ent = head->ent;
    tmp = head->next;
    free(head);
    head = NULL;
    head = tmp;

    if (head == NULL)
	rear = NULL;
    return ent; 
}
int is_empt()
{
    return head == NULL;
}
int graph[1000][1000];

void clean_matrix(int n)
{
    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
}
void print_graph(int n)
{
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf(" %d ", graph[i][j]);
        printf("\n");
    }
}

void find_distance(int n, int S)
{
    int cost[n];

    /* I initially thought that it might be possible that we might visit
     * a node from a far neighbour than nearer one before. Careful observation
     * shows that it is not possible. If we visit a node it is from the nearest node.
     * Don't visit this node again. Otherwise Algorithm won't converge.
     *   1---->2-->X-->3
     *   |            /|\
     *  \|/	       |
     *   4-------------
     *
     *   In the above graph, 3 is first visited from the nearest node i.e. 4.
     *   That is the shorted distance to it. No other edge can make it any shorter.
     *   When we are dealing with "X" node we don't need to take care of node 3 because it was
     *   already covered by 4.
     *   becaue we are using BSF. 
     **/
    int t_enq[n]; 
    int current_cost = 6;
#define MAGIC (1<<((sizeof(int)*8 -3)))
    for(int i = 0; i < n; i++) {
        cost[i] = MAGIC;
	t_enq[i] = 0;
    }
    
    init_q();
    entity_t ele;
    ele.node = S;
    ele.cost = current_cost;
    ele.parent = -1;
    enq(ele);
    while (!is_empt()) {
        ele = deq();
        int i = 0;
        while(i < n) {
            if (graph[ele.node][i] == 1) {
                current_cost = ele.cost;
                //printf("Element = %d\n", graph[ele.node][i]);
                /* Mark the distance from S = current_cost */
                /* If current_cost < earlier_cost. Update the cost = current_cost */
                if( cost[i] > current_cost) {
                    //printf("%d..i=%d\n", current_cost, i);
                    cost[i] = current_cost;
                }
		if (ele.parent != i && !t_enq[i]) {
                	entity_t ent;
                	ent.node = i;
                	ent.cost = current_cost + 6;
			ent.parent = ele.node;
		        t_enq[i] = 1;
                	enq(ent);
		}
            }
            i++;
        }
    }
    /* Print cost array */
    for(int j = 0; j < n; j++) {
        if (j == S) 
            continue;
        if(cost[j] == MAGIC)
            printf("%d ", -1);
        else
            printf("%d ", cost[j]);
    }
}
int main() {
    int T, n, m;
    int S;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &n);
        scanf("%d", &m);
        clean_matrix(n);
        for(int j = 0; j < m; j++) {
            int from, to;
            scanf("%d %d", &from, &to);
            graph[from-1][to-1] = 1;
            graph[to-1][from-1] = 1;
        }
        scanf("%d", &S);
        find_distance(n, S-1);
        //print_graph(n);
        printf("\n");
    }
    return 0;
}
