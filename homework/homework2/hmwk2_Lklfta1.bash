# This is a .sh script which prints the process ID, PPID, GID, my username, attempts to grep the /etc/passwd
# that matches my $USER, prints a list of processes, sleeps for 3 seconds then prints another list of processes
#
# Linn Klofta 2024

echo "Starting shell script"

echo "Process ID: $$"

echo "Parent process ID: $PPID"

echo "Group ID: $(id -g)"

echo "Welcome $USER!"
grep $USER /etc/passwd

echo "First list of processes:"
ps

echo "Sleeping for 3 seconds..."
sleep 3

echo "Sendond list of processes after sleeping:"
ps

echo "Ending shell script"
