Basic idea:

1. Figure out the first dip in the stock price by scanning the array left to right
2. As we do each comparision of next-to-next array elements - if we dont see dip keep track of the lowest number index 
3. As soon as we see the dip: print (lowest_number_index, traverse_index)
4. Make buyIndex = traverseIndex = traverseIndex + 1
5. Repeat step (1)
