#!bash
time ./lem-in < $1 >   output
cat output | grep "required\|NOPE\|YES\|flow\|number"
cat output | ./verifier
