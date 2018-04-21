/*
Avery Zamzow
221.202 
alz005
*/

#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include<fstream>

using namespace std;

int c = 0;

void print_list(vector<vector<int> > graph , int n) 		//function prints adjacency list of graph 
{															 
    for(int i=0;i<graph.size();i++)							
    {
        cout << i << "-> " ;
        for(int j=0;j<graph[i].size();j++)					//counts doors on nodes
        {
            if(graph[i][j] == 0)							// goes north
            {
                cout << i - n << " ";						//then node above (n is the square root of the node verticie)
            }
            else if(graph[i][j] == 1)						// goes east
            {
                cout << i + 1 << " ";						//then next node
            }
            else if(graph[i][j] == 2)						// goes south
            {
                cout << i + n << " ";						//then node below (n is the square root of the node verticie)
            }
            else											// goes west
            {
                cout << i - 1 << " ";						//then last node
            }
        }
        cout<<endl;
    }
}

vector<int> path(vector<vector<int> > graph ,int n)			// this function does a breadth first search on the graph
{
    queue<int > q;											//make a queue
    vector<int> visited(n*n , 0);							// visited vector is created to mark the visited block
    q.push(0);
    vector<int> parent(n*n);								// parent block stores the parent of each block
    parent[0] = -1;											// parent of first block is none so -1
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        visited[v] = 1;	
		c++;

        for(int i=0;i<graph[v].size();i++)			// insert the child of the current verticy so all the doors which can be visited through this door
        {													//checkes doors of each verticy
            if(graph[v][i] == 0)							//if door on north
            {
                if(!visited[v - n])							//check to see if its visited
                {
                    q.push(v - n);							//push the node above (n is the square root of the node verticie)
                    parent[v - n] = v;						//put it in the vector of the path
                }
            }
            else if(graph[v][i] == 1)						//if door on east
            {
                if(!visited[v + 1])							//check to see if its visited
                {
                    q.push(v + 1);							//push the next node
                    parent[v+1] = v;						//put it in the vector of the path
                }
            }
            else if(graph[v][i] == 2)						//if door on south
            {
                if(!visited[v + n])							//check to see if its visited
                {
                    q.push(v + n);							//push the node below (n is the square root of the node verticie)
                    parent[v+n] = v;						//put it in the vector of the path
                }
            }
            else											//if door on west
            {
                if(!visited[v - 1])							//check to see if its visited
                {
                    q.push(v - 1);							//push the last node
                    parent[v - 1] = v;						//put it in the vector of the path
                }
            }
        }
    } return parent;
}

vector<int> get_path(vector<int> parent, int n)				// this function return the vector of the path obtained from parent vector
{
    int i = n*n - 1;										//i is the exit node
    vector<int> s;											//creates a new vector to put the shortest path
    s.push_back(i);											
    while(parent[i] != -1)									//while the path in the parent vector is not at the exit node
    {
        s.push_back(parent[i]);								//add a new element to the vector each time a new node is read
        i = parent[i];										//incrament node
    }
    return s;
}

void display_path(vector<int> path ,int n)					// this function displays the path in output as well as create the file to store the output 
{
    cout << "Enter the filename for output : "<<endl;			//output file where you will put the path of the graph
    string s;
    cin >> s;
    ofstream file(s);
    cout << "-------------SHORTEST PATH--------------";			//prints to screen
    file << "---------------SHORTEST PATH---------------";		//prints to file

    sort(path.begin(),path.end());								//sorts the path
    int k = 0;
    for(int i = 0; i<n*n;i++)									//go through each verticy
    {
        if(i%n == 0)											//if end verticy then go to the next line
        {	
            cout << endl;										//prints to screen
            file << endl;										//prints to file
        }
        if(i == path[k])										//if this node is on the path print 0
        {
            cout <<"O ";										//prints to screen
            file <<"O ";										//prints to file
            k++;
        }
        else													//if this node isnt on the path print X
        {
            cout << "X ";										//prints to screen
            file << "X ";										//prints to file
        }
    }
    file.close();
    cout << endl;
}

int main() 										//main fucntion
{
    string s;									//creating a value s to hold the files name
    cout << "Enter file name : "<<endl;
    cin >> s;
    fstream file(s);							//reads file input
    vector<vector<int> > graph;					//represents the graph as an vector of vectors
    int num;

    file >> num;
    int n = sqrt(num);
    for(int i=0;i<num;i++)
    {
        vector<int> temp;						//initialize a graph according to the given number of nodes
        graph.push_back(temp);					//initialize the graph
        for(int j=0;j<4;j++)					//Read number of nodes and doors in the file
        {										//j being doors
            int curr;							
            file >> curr;						//copy the file's node to curr
            if(curr == 1)
            {
                graph[i].push_back(j);			// creates an adjacency list to stores all the doors
            }
        }
    }

    vector<int> parent = path(graph,n);			//creates a vector parent to search the graph for a path
    vector<int> path = get_path(parent,n);		//Creates a vector path obtained from the parent vector
    display_path(path,n);						//displays the path

    while(1)									// simple menu function to print and list the graph
    {
        cout << "\nEnter the option : \n";
        cout << "1 : Print adjacency list of graph\n2: Find length of the path\n3: Print all vertices in shortest path\n4: Quit\n";
        int a;									// your option you want to choose
        cin >> a;
        switch(a)
        {
        case 1:									//Print adjacency list of graph
			cout << "\n" << endl;
            print_list(graph,n);
            break;
        case 2:									//Print all vertices in shortest path				
        {
            cout << "\nLength : " << path.size() << endl;	//prints the length of the path
			cout << "How many times it traveres through : " << c << endl;
            break;
        }
        case 3:									//Print all vertices in shortest path				
        {
			cout << "\n" << endl;
            vector<int> s(path);				//creates a vector for the adjacency list and gets the path
            for(int i=0;i<s.size();i++)			//print out the adjacency list based off size
            {
                cout << s[s.size()-i-1] << " ";
            }
            cout << endl;
            break;
        }
        default:									//terminates the program
            exit(1);

        }
    }

    return 0;
}
