 #!/bin/bash 
dir=$1
files=( "${@:2}" )

for i in ${files[*]}; do
    echo "Moving $i.cpp"
    touch "$i.cpp"
    echo "//https://codeforces.com/$dir/problem/$i\n$(cat $i.cpp)" > $i".cpp"
    mkdir -p "codeforces.com/contest/$dir/" && mv $i".cpp" "$_"
    # echo "Formatting $i.cpp"
    # cp template.cpp $i".cpp"
    # rm "a.out"
done

echo "Complete"


# Delete redundent Notes file
# find . -name "NOTES.md" -delete