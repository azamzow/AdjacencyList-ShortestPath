# AdjacencyList/Shortest Path Project

### Description 

This project finds a path from the entrance to the exit in a maze that consists of rooms connected by doors. Each room is enumerated by consecutive integers, from 0 to n^{2} - 1, and it can have no more than 4 doors oriented to North , South , East  or West . The entry to the maze starts at the room 0 and ends at the room n^{2} - 1. The maze can be modeled by an undirected graph, where a vertex corresponds to a room and an edge corresponds to a door, see the maze below with the path and the corresponding graph for the maze.

![Graph](https://github.com/azamzow/AdjacencyList-ShorttestPath/blob/master/Graph.png?raw=true)


### To Run

Using terminal on Mac, you have to make sure you have g++ installed first. Then you can run it...

```sh
$ cd AdjacencyList-ShorttestPath
$ g++ Project.cpp
$ ./a.out
```

### Output

The program asks the user for the filename containing the input and the filename to place the output path on.  This program can read graph data from any user file. In my program there are two inputs, input1.txt and input2.txt. I also have two different output files, output1.txt and output2.txt. After the user enters the file names, displayed on the screen is the algorithm used finds a path from the entrance to the the exit of the maze while also saving it to the output file. Then the program allows the user to choose between 4 different options...

1) Print the adjacency list

2) Find the length of the shortest path

3) Print all the verticies in the shortest path

4) Quit

If the user chooses 1, then the adjacency list is printed. If the user chooses 2, then the paths length is printed. If the user chooses 3, then the verticies (doors) are printed to make the shortest path. Finally if the user wishes to quit, they an press 4. 

The input file used to show as an example looks like this…. using the number of rooms(nodes) as the first number, then the lists each node's 4 doors. If they have a 1, they are open, if they have a 0, they are closed. The doors are in order from North , South , East  or West. 

So take line 2 for example, that is Room 0, and its only opening is the east door. SO using the input file from  input1.txt, its a 3x3 maze and shown in the output file is the shortest path.

![OUTPUTinput1](https://github.com/azamzow/AdjacencyList-ShorttestPath/blob/master/OUTPUTinput1.png?raw=true)

The output on the terminal looks like TERMINAL1.png.

![TERMINAL1](https://github.com/azamzow/AdjacencyList-ShorttestPath/blob/master/TERMINAL1.png?raw=true)

I am displaying the graph in the text format, use zero to denote a vertex (room) on the entry-exit path and x otherwise. As shown in output1.txt

![OUTPUToutput1](https://github.com/azamzow/AdjacencyList-ShorttestPath/blob/master/OUTPUToutput1.png?raw=true)
