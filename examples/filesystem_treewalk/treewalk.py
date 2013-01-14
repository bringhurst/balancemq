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
            for file in os.listdir(message):
                conn.send(file, destination='/queue/treewalk_example')

conn.set_listener('', TreewalkListener())

conn.start()
conn.connect()

conn.send(sys.argv[1], destination='/queue/treewalk_example')
conn.subscribe(destination='/queue/treewalk_example', ack='auto')

conn.disconnect()
