# 1. Exploring Ruins

(by [niyaz3](https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/exploring-ruins/ "Hackerearth.com"))

Little robot CJ-17 is exploring ancient ruins. He found a piece of paper with a word written on it. Fortunately, people who used to live at this location several thousand years ago used only two letters of modern English alphabet: ``'a'`` and ``'b'``. It's also known, that no ancient word contains two letter ``'a'`` in a row. CJ-17 has already recognized some of the word letters, the others are still unknown.

CJ-17 wants to look up all valid words that could be written on this paper in an ancient dictionary. He needs your help. Find him the word, which is the first in alphabetical order and could be written on the paper.

### Input format

The first line contains non-empty string _s_

consisting of ``'a'``, ``'b'`` and ``'?'`` characters. Character ``'?'`` corresponds to unrecognized letter.

It's guaranteed, that there exists at least one ancient word, that could be written on the paper.

### Constraints

Length of _s_ is at most 50.

### Output format

Output the first in alphabetical order word, that could be written on the paper, found by CJ-17.


#### Example:
```
Input: ?ba??b 
Output: ababab
```

Words ``ababab``, ``ababbb``, ``bbabab`` and ``bbabbb`` could be written on paper. The first in alphabetical order is ``ababab``.

# 2. Number letter counts

([Project Euler #17](https://projecteuler.net/problem=17 "ProjectEuler.net"))



If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

# 3. Rectangles into Squares

(by [g964](https://www.codewars.com/kata/rectangle-into-squares "codewars.com"))

The drawing below gives an idea of how to cut a given "true" rectangle into squares ("true" rectangle meaning that the two dimensions are different):

![Rectangles](http://i.imgur.com/lk5vJ7sm.jpg "Rectangle example")

Can you translate this drawing into an algorithm?

You will be given two dimensions

1. a positive integer length (parameter named lng)
2. a positive integer width (parameter named wdth)

You will return an array with the size of each of the squares.

#### Examples:

```
sqInRect(5, 5) should return {}  
sqInRect(3, 5) should return {3, 2, 1, 1}
sqInRect(5, 3) should return {3, 2, 1, 1} 
```

# 4. Traveling on a Grid

(by [mmalkavian](https://www.codewars.com/kata/travelling-on-a-grid "codewars.com"))

You have an 8x8 grid with coordinates ranging from 1 to 8. The origin ``[1, 1]`` is in the top left corner. The bottom right corner is ``[8, 8]``.

You are given a string as an input which will contain the 2 coordinates in this format: ``[x1, y1]``, ``[x2, y2]`` , where ``[x1, y1]`` represents point A and ``[x2, y2]`` represents point B. In the inputs provided, point A will always be up and to the left of point B. In other words, x1 < x2 and y1 < y2 will be true for every input.

Your goal is to find out the number of different paths you can take to get from point A to point B by moving one space at a time either down or right.

##### Example:
```
[  x,  x,  x,  x,  x,  x,  x,  x],
[  x,  x,  x,  x,  x,  x,  x,  x],
[  x,  A,  x,  x,  x,  x,  x,  x],
[  x,  x,  x,  x,  x,  x,  x,  x],
[  x,  x,  B,  x,  x,  x,  x,  x],
[  x,  x,  x,  x,  x,  x,  x,  x],
[  x,  x,  x,  x,  x,  x,  x,  x],
[  x,  x,  x,  x,  x,  x,  x,  x],
```
Possible paths:
```
A    A    A x
x    x x    x
x B    B    B
```

# 5. Find whether there is a route between two nodes in a graph

(by [ykagan](https://www.codewars.com/kata/find-whether-there-is-a-route-between-two-nodes-in-a-graph "codewars.com"))

A [directed graph](https://en.wikipedia.org/wiki/Directed_graph "Wikipedia.org - Directed Graph") consistst of a set of nodes and a set of edges that connect it to other nodes: 
```
struct Node = {
  char value = 'a';  // Could be int too
  int *edges = [node1, node2, ...];
}
```

![Directed Graph](http://upload.wikimedia.org/wikipedia/commons/0/03/Directed_acyclic_graph_2.svg "Picture of a directed graph") 

Find whether there is a route between two nodes of the graph.