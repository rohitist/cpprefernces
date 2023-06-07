Deadlock situation:

Example 1:
    Thread 1               Thread 2

    Lock1->Lock();         Lock2->Lock();
    WaitForLock2();        WaitForLock1();   <-- Oops!

Example 2:

Funny example of dealock using a story:

    Jack and Jill happens to want to make a sandwich at the same time. Both need a slice of bread, so they both goes to get the loaf of bread and a knife.

    Jack gets the knife first, while Jill gets the loaf of bread first. Now Jack tries to find the loaf of bread and Jill tries to find the knife, but both find that what they need to finish the task is already in use. If they both decide to wait until what they need is no longer in use, they will wait for each other forever. Deadlock.

Example 3:

    thread 1:
    lock(a)
    lock(b)

    thread2:
    lock(b)
    lock(a)

    Assume that thread 1 gets lock A and then goes to sleep. Thread 2 gets lock B and then attempts to get lock A; since lock A is taken, thread 2 will be put to sleep until thread A is unlocked. Now thread 1 wakes back up and tries to get lock B and will be put to sleep.

    For this case, there are a couple of ways to prevent it:

    A thread should never need to hold two locks simultaneously.
    If two locks must be held simultaneously, they must always be acquired in the same order (so in my example above, thread 2 would need to be modified to request lock A before requesting lock B).

