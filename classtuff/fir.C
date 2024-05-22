#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};
typedef struct node NODE;


void free_graph(int v, node** adj_list)
{
    for(int i=0;i<v;i++)
    {
        node* head = adj_list[i];
        node* temp = NULL;
        while(head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        adj_list[i] = NULL;
    }
}


int *calculate_indegree(int v, NODE **adj_list)
{
    int *indegree = (int *)malloc(v * sizeof(int));

    for (int i = 0; i < v; i++)
    {
        indegree[i] = 0;
        NODE *current = adj_list[i];
        while (current != NULL)
        {
            indegree[current->val]++;
            current = current->next;
        }
    }

    return indegree;
}

void topological_sort(int v, NODE **adj_list)
{
    int *indegree = calculate_indegree(v, adj_list);
    int *visited = (int *)malloc(v * sizeof(int));

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    printf("Topological Sort: ");

    int count = 0;

    while (count < v)
    {
        int flag = 0;

        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0 && !visited[i])
            {
                printf("%d ", i);
                visited[i] = 1;
                NODE *current = adj_list[i];

                while (current != NULL)
                {
                    indegree[current->val]--;
                    current = current->next;
                }

                flag = 1;
                count++;
            }
        }

        if (!flag)
        {
            printf("\nNot DAG\n");
            break;
        }
    }
}

int main()
{
    int v,e,n,neighbour;
    int count = 0;
    scanf("%d %d",&v,&e);
    node** adj_list = malloc(sizeof(node*)*v);
    while(count<v)
    {
        scanf("%d",&n);
        int count1 = 0;
        node* cur_vertex;
        if(n)
        {
            cur_vertex = calloc(1,sizeof(node));
            cur_vertex->val = -1;
            adj_list[count] = cur_vertex;
        }
        else
            adj_list[count] = NULL;

        while(count1<n)
        {
            scanf("%d",&neighbour);
            if(cur_vertex->val != -1)
            {
                node* temp = malloc(sizeof(node));
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
