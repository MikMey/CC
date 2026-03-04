#!/bin/bash
# valgrind --leak-check=full --log-file=val.log --error-exitcode=42

range=${1:-100}
run=${2:-1}


fails=0
best=199999999
worst=0

rm -rf text.txt
rm -rf averages.txt
rm -rf crash.txt

for i in $(seq 1 $run)
do
    temp=$(shuf -i 0-5000 -n$range)
    echo "----------RUN $i-----$range Nums-----"
    timeout 10s valgrind --leak-check=full --log-file=val.log --error-exitcode=42 ./swap.a ${temp[@]} > text.txt
	checker=$(cat text.txt | ./checker_linux ${temp[@]})
	echo $checker
    status=$?
    if [[ "$status" -gt "0" || $checker == "KO" ]]
    then
        printf "\n\033[31;1m""KO""\033[0m\n"
        printf "Amount of Ints: $range | Exit: $status | Checker: $checker | Input: ${temp[@]}"| tee -a crash.txt
		if [[ "$status" -eq "42" ]]
		then
        	printf " \033[31;1m""MKO""\033[0m\n"
			printf "\n"
		fi
		cat val.log >> crash.txt
        fails=$(($fails + 1))
    else
        printf "\033[36;1m""MOK \n""\033[0m"
        cat text.txt >> averages.txt
    fi
    value=$(cat text.txt | wc -l)
	if [[ "$value" -lt "$best" ]]
	then
		best=$value
	fi
	if [[ "$value" -gt "$worst" ]]
	then
		worst=$value
	fi
	echo $value
    unset temp
done
echo -e "\nAVERAGE" | tee -a result.txt
av=$(cat averages.txt | wc -l)
div=$(($run - $fails))
echo $(($av / $div)) | tee -a result.txt
echo Worst | tee -a result.txt
echo $worst | tee -a result.txt
echo Best | tee -a result.txt
echo $best | tee -a result.txt
echo Fails | tee -a result.txt
echo $fails | tee -a result.txt

