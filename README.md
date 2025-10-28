[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

When parsing the file, kept the " so it is easier to parse the catagories into a single substring the parse it further with | into multiple catagories. Did parse by ',' so if there was any ASin and brand name they are parsed out of ". used string::npos to tell is | is present, if not then all other catagies are fillded with NA.
Max catagories set to 7, did notice whhen parsing that the last catagories will repeat, this is a fine income. 
