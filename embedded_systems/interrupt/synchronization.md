Sharing data between an ISR (Interrupt Service Routine)

Suppose there is an ISR for UART RX in UART Driver code and there is a task for CLI service that polls and detects if a command is sent from host, that would arrive at UART RX port
    Let's say Srv_UART_Thread() is a thread/ task that runs on an RTOS and will keep on polling data that would arrive at UART RX port by calling PollUart()
        PollUart() will wait on a semaphore key (say x) for some data to arrive on UART RX port

    Let's say, the ISR name is: halUartIsr() and ISR calls halUartReadFifo()
        halUartReadFifo() will detect if there's something to read in FIFO queue (a hardware register). Once it detects, it would call semaphore_put to tell the PollUart() that some data is received at UART RX port