 #!/bin/bash 
dir=$1
files=( "${@:2}" )

for i in ${files[*]}; do
    echo "Moving $i.cpp"
    echo "//https://$dir/problem/$i\n$(cat $i.cpp)" > $i".cpp"
    mkdir -p "codeforces.com/$dir/" && cp $i".cpp" "$_"
    echo "Formatting $i.cpp"
    cp template.cpp $i".cpp"
    rm "a.out"
done

echo "Complete"