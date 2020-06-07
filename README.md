# htneMiner

## to install
1. download into a repository
2. navigate into the cryptopp824 folder in a terminal or command prompt
3. run make
4. run make install ..

  That will install the library into your outer directory

5. navigate out one level (cd ..)
6. run make

  This should build the executable
 
7. ./main

  This will bootup the program and run the executable
  

## Explanation
main.cpp contains a simple cli wrapper around the blockchain

blockchain.cpp contains the methods for the blockchain object defined in blockchain.hh

block.cpp contains the methods for the block object defined in block.hh

Transaction.hh contains the objects that are stored in the transations
