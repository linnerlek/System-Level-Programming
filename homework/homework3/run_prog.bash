# shell script to execute my c file
# Linn Klofta
# 2024

#!/bin/bash

date
./homework3
result=$? # gets the exit status of homework3 after it runs

if [ $result -eq 0 ]; then
    echo "Program executed successfully." # print a good message if no errors occured
else
    echo "Program failed with error code: $result" # if error occured print the error code it gave
fi

cat output.txt # output from homework3 is stored in output.txt so i cat it to show the contents
