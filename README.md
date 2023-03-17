# dinning-philosophers
A solution to the dining philosophers problem using POSIX threads.

The dining philosophers problem was originakky formulated in 1965 by Edsger Dijkstra as a student exam exercise. Nowadays there are some variants of the original problem.

The problem is used to show the key points present in concurrent algorithm design, such as synchronization issues and techniques for solving them.

The present program was coded in C and shows a solution to the problem using POSIX threads.



### Usage
The program takes in 4-5 arguments:

◦ number_of_philosophers: The number of philosophers and also the number
of forks

◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the sim-
ulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

```./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <<number_of_times_each_philosopher_must_eat>>```

