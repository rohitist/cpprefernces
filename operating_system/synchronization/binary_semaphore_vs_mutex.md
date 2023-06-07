Mutex vs Binary Semaphore (Ref: https://freertos.org/Embedded-RTOS-Binary-Semaphores.html )
    1. Mutex is used in the context of tasks or threads while binary semaphore is used in the context of task and ISR
    2. Mutex has a property to enable priority inheritence while a binary semaphore doesn't have such property
        Ex: Masters in an I2C network can use mutex with priority inheritence enabled
            While trying to read flash dump, the reader mutex can have priority inhertance enabled
    3. If two tasks T1 and T2 are blocked on a binary semaphore then the task with highest priority will be the task that is unblocked the next time the 
        semaphore become available
    4. Binary semaphore (or semaphore in general) has time out property while a mutex has not. So, tasks could wait on semaphore for certain maximum ticks
        that a task should enter the blocked stae when attempting to take a semaphore
