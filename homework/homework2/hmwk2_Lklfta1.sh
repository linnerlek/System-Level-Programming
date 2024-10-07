echo "Starting shell script"

echo "Process ID: $$"

echo "Parent process ID: $PPID"

echo "Group ID: $(id -g)"

echo "Welcome $USER!"

echo "First list of processes:"
ps

echo "Sleeping for 3 seconds..."
sleep 3

echo "Sendond list of processes after sleeping:"
ps

echo "Ending shell script"
