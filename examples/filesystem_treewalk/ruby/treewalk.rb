# This example is a distributed treewalk of a filesystem hierarchy. Assuming
# the underlying filesystem is parallel (i.e. has multiple read heads), this
# will distribute and balance the stat(2) workload among many nodes.

# FIXME: This file is mostly psuedocode. It really needs fixing so it actually
#        compile and works.

require 'stomp'

queue = '/queue/treewalk_example'
client = Stomp::Client.open "stomp://localhost:1625"

# Enqueue the root item.
client.send queue, "#{ARGV[1]}"

# Process items.
client.subscribe(queue) do |msg|

  if File.file? msg
    print "F: #{msg}"
    next
  end

  if File.directory? msg
    print "D: #{msg}"

    Dir.foreach('/path/to/dir') do |item|
      next if item == '.' or item == '..'

      if File.file? item
        print "F: #{item}"
        next
      end

      if File.directory? item
        client.publish queue, item
      end
    end

  end
end

client.close
