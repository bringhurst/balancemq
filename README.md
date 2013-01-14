BalanceMQ
=========
BalanceMQ is a continuous workload balancer that knows how to efficiently and automatically distribute work evenly among many (tens of thousands) of servers with minimal communications overhead.

This program is still in development, please come back later if you want to use it for a production need.

Example
-------
This example is a distributed treewalk of a filesystem hierarchy using the STOMP interface. Assuming the underlying filesystem is parallel (i.e. has multiple read heads), this will distribute and balance the stat(2) workload among many nodes.

```
import sys 
import stomp

conn = stomp.Connection()

class TreewalkListener(object):
    def on_error(self, headers, message):
        print 'received an error %s' % message

    def on_message(self, headers, message):

        if os.path.isfile(message):
            print 'F: %s' % message

        if os.path.isdir(message):
            print 'D: %s' % message

            for file in os.listdir(message):
                conn.send(file, destination='/queue/treewalk_example')

conn.set_listener('', TreewalkListener())

conn.start()
conn.connect()

conn.send(sys.argv[1], destination='/queue/treewalk_example')
conn.subscribe(destination='/queue/treewalk_example', ack='auto')

conn.disconnect()
```
