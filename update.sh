 #!/bin/bash 
# https://codeforces.com/contest/441/problem/A
dir=$1
# codeforces.com/contest/441/problem/A
dir=${dir:8}
# A
name=${dir:${#dir}-1}

# codeforces.com/contest/441/problem/
dir=${dir::${#dir}-9}

echo "Moving $name.cpp"
mkdir -p "$dir/" && cp $name".cpp" $dir/$name".cpp"
echo "Formatting $name.cpp"
cp template.cpp $name".cpp"
rm "a.out"

echo "Complete"

# Usage /update.sh practice A 30_JAN_Flip_A_BIT