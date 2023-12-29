                                                    MINITALK
->This is a 42 project which you construct a mini bipolar chatbox program.
-

We have 2 programs called server and client. 
When we initialize ./server there should pop-up a PID number in the terminal. 
./client takes two arguments. One is PID number and the other is string to be sent to the server. 
To execute these programs first execute server and then client. 

->HOW DO WE SEND STRINGS TO OTHER PROGRAM ?
-

 1) First you should have informations about signals in C. You should search kill(), getpid(), signal().
 2) Second you should be familiar with bit manipulations. You should have information about bitwise operations. >>, <<, |, &.
 3) Static variable.
 4) You should think about how to reconstruct bits to create a 8-bit character.
