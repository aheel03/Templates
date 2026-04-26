g++ gen.cpp -o gen
g++ my.cpp -o my
g++ brute.cpp -o brute

for((i=1; i<=10000; ++i)); do
    echo $i
    ./gen $i > in.txt
    ./my < in.txt > out1.txt
    ./brute < in.txt > out2.txt
    
    # Compare outputs; if they differ, stop the loop
    diff -w out1.txt out2.txt || break
done