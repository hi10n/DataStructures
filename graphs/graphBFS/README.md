Graph BFS Algorithm:

To find the shortest route from some source node to some sink node:

1. Creates a digraph using adjacency list
2. Graph is represented as a node with pointers to other adjacent nodes to which it is connected
3. Run the BFS algorithm to determine the shortest path from one node to another
	a) Push the start node in the BFS queue at the head
	b) Check the out edges of the node at the head of the BFS queue and put the nodes' adjacent nodes at the tail of the queue. Also indicate which "parent" node added the adjacent nodes in the queue. If a node has been visited before we dont add it to the queue. 
	c) If we add the sink node in the BFS queue, we are done so go to last step
	d) Increment the head pointer in the BFS queue
	e) Goto step (b)

	last step) We added the sink node at the tail of the queue - so we simply backtrace from the sink node to the source node to know the shortest path from source to sink
