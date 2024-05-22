#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

void topological_sort(int v, node **adj_list)
{
    int in_deg[v];
    for (int i = 0; i < v; i++)
        in_deg[i] = 0;

    for (int i = 0; i < v; i++)
    {
        node *current = adj_list[i];
        while (current != NULL)
        {
            in_deg[current->val]++;
            current = current->next;
        }
    }

    int visited[v];
    int count = 0;

    while (count < v)
    {
        int lower_val = -1;

        for (int i = 0; i < v; i++)
        {
            if (in_deg[i] == 0)
            {
                lower_val = i;
                break;
            }
        }

        if (lower_val == -1)
        {
            printf("Not DAG\n");
            return;
        }
        visited[count++] = lower_val;
        in_deg[lower_val] = -1;
        node *current = adj_list[lower_val];
        while (current != NULL)
        {
            in_deg[current->val]--;
            current = current->next;
        }
    }
    for (int i = 0; i < v; i++)
        printf("%d ", visited[i]);
    printf("\n");
}

void free_graph(int v, node **adj_list)
{
    for (int i = 0; i < v; i++)
    {
        node *head = adj_list[i];
        node *temp = NULL;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        adj_list[i] = NULL;
    }
}

int main()
{
    int v, e, n, neighbour;
    int count = 0;
    scanf("%d %d", &v, &e);
    node **adj_list = malloc(sizeof(node *) * v);
    while (count < v)
    {
        scanf("%d", &n);
        int count1 = 0;
        node *cur_vertex;
        if (n)
        {
            cur_vertex = calloc(1, sizeof(node));
            cur_vertex->val = -1;
            adj_list[count] = cur_vertex;
        }
        else
            adj_list[count] = NULL;

        while (count1 < n)
        {
            scanf("%d", &neighbour);
            if (cur_vertex->val != -1)
            {
                node *temp = malloc(sizeof(node));
                temp->val = neighbour;
                temp->next = NULL;
                cur_vertex->next = temp;
                cur_vertex = cur_vertex->next;
            }
            else
            {
                cur_vertex->val = neighbour;
                cur_vertex->next = NULL;
            }
            count1 += 1;
        }
        count += 1;
    }
    topological_sort(v, adj_list);
    free_graph(v, adj_list);
    free(adj_list);
    adj_list = NULL;
    return 0;
}