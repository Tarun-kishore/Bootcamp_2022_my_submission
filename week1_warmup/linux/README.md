### The exercises are done using wsl system not a virtual machine or actual linux

### Exercise 1

command to show all hidden files is `ls -a`
command to rename file after copying is `cp file newFileName`

Output:

![Output of exercise one](/week1_warmup/linux/exercise1output.png)

### Exercise 2

Run command more /proc/cpuinfo and explain the following terms: processor and cores. Use the command lscpu to verify your definitions.

![Output of lscpu](/week1_warmup/linux/lscpuoutput.png)

Processor :
Processor is hardware of computer which is responsible for all computations of processes.

Cores:
Core is the fundamental processing using of processor.

How many CPU sockets, cores, and processors does your machine have?
Machine have 4 processors, each processor has 2 cores. There is one socket in processor and 2 cores in one socket.

What is the frequency of each processor?

Frequency of each processor: 2995.198

How much memory does your machine have?

Total memory : 6206776 kB

How much of it is free and available? What is the difference between them?

Free Memory     :    5971440 kB
Available Memory:    5930060 kB

Available Memory means the total system memory available for programs to use. Free Memory means the remaining memory that is not in use by programs at any given moment, from the available memory.

What is the total number of user-level processes in the system?

There are 3 user level processes in system.

What is the total number of number of forks since the boot in the system ?

There has been 666 forks since boot.

How many context switches has the system performed since bootup?

There has been 12 context switches in system since bootup.

### Exercise 3

![Output of pid](/week1_warmup/linux/pidOutput.png)

What is the PID of the process running the cpu command?

519 

How much CPU and memory does this process consume?

It is using 100% memory and 0.0 memory.

What is the current state of the process? For example, is it running or in a blocked state or a zombie state?
The process is in running state.
