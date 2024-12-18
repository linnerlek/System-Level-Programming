#!/bin/bash

# Step 1: Add START and EOL to each line of aminegg.txt
sed 's/^/START/' < aminegg.txt | sed 's/$/EOL/' > temp1.txt

# Step 2: Filter out lines with STARTEOL and output to screen
sed 's/^/START/' < aminegg.txt | sed 's/$/EOL/' | grep -v "STARTEOL" | cat

# Step 3: Save the filtered result to lklfta1_aminegg.txt
sed 's/^/START/' < aminegg.txt | sed 's/$/EOL/' | grep -v "STARTEOL" > lklfta1_aminegg.txt

# Step 4: Compare original file and modified file
cmp aminegg.txt lklfta1_aminegg.txt
cat answer.txt

# Step 5: Show differences using diff
diff aminegg.txt lklfta1_aminegg.txt

# Step 6: Remove START and EOL from modified file and output
sed 's/^START//' lklfta1_aminegg.txt | sed 's/EOL$//' | grep -v '^$' | cat

# Step 7: Save cleaned data back to lklfta1_aminegg.txt
sed 's/^START//' lklfta1_aminegg.txt | sed 's/EOL$//' | grep -v '^$' > lklfta1_aminegg.txt

# Step 8: Use diff again to check files
diff aminegg.txt lklfta1_aminegg.txt
cat answer2.txt
# Additional commands
date
ls -1 | wc -l
pwd
ls -l

