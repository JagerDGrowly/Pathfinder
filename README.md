# Pathfinder

This project involves implementing a graph-based solution to find the shortest path between islands connected by bridges. The objective is to simulate the problem of finding the shortest route between two islands, given a map with various distances representing the bridges that connect them. It is essentially a pathfinding problem in which each island is a node in a graph, and each bridge between islands is an edge with a weight representing the distance or cost to travel.

Usage:

Create file which has the same structure like example below:

```
4
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5
```

and after make run the command: ./pathfinder [filename] | cat -e to see the result.
