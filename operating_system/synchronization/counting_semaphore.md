counting semaphores are typically used for two things (Ref: https://freertos.org/Real-time-embedded-RTOS-Counting-Semaphores.html ):

Just as binary semaphore can be thought as of queues f lenght one, counting semaphores can be thought of as queues of length greater than one.
Again, users of the semaphore are not interested in the data that is stores in the queue - just whether or not the queue is empty or not.

1. counting events:

    In this usage scenario an event handler will give a semaphore each time an event occurs (increment the semaphore count value), and a handler task will 
    take a semaphore each time it processes an event (decrementing the sempahore count value). The count value is therefore the difference between the number
    of events that have occurred and the number that have been processed. In this case it is desirable for the count value to be zero when the semaphore is created

2. Resource Management

    In this usage scenario the count value indicates the number of resources available. To obtain control of a resource, a tak must first obtain a semaphore -
    decrement the samaphore count value. When the count value reaches zero, there are not free resources. When a task finishes with the resource it gives the
    semaphore back - incrementing the semaphore count value. In this case it is desirable for the count value to be zero when the semaphore is created

3. Connection management in an embedded systems

    Master node/ task could keep a track of slaves using counting semaphore. Suppose if a slave is turned off then the count will be decremented and a slave is added
    then the count could be increaaed
