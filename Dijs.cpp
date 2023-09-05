#include<bits/stdc++.h>
using namespace std;
int arr[20][20],n,src;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;

    for(int k=0;k<6;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[][20],int src) // adjacency matrix
{
    int distance[n]; // // array to calculate the minimum distance for each node
    bool Tset[n];// boolean array to mark visited and unvisited for each node

    for(int k = 0; k<n; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0;   // Source vertex distance is set 0

    for(int k = 0; k<n; k++)
    {
        int m=miniDist(distance,Tset);
        Tset[m]=true;
        for(int k = 0; k<n; k++)
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<n; k++)
    {
        cout<<k<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
 int i, edge, origin, destin;

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the source Vertex: ";
    cin >> src;
    cout << "Enter no of Edge " ;
    cin >> edge;
    for (i = 1; i <= edge; i++)
    {
        cout << "Enter edge " << i << endl;
        cin >> origin >> destin;

        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            cout << "Invalid Edge " << endl;
            i--;
        }
        else
        {
            cin >> arr[origin][destin];
        }
    }
    DijkstraAlgo(arr,src);
    return 0;
}