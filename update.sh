 #!/bin/bash 
dir=$1
name=$2
to = $3

echo "Moving $2.cpp"
mkdir -p "codeforces.com/$dir/$name/" && cp $2".cpp" "codeforces.com/"$dir"/"$name"/"$3".cpp"
echo "Formatting $2.cpp"
cp template.cpp $2".cpp"
rm "a.out"


echo "Complete"