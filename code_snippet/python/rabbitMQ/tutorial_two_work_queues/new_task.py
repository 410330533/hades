#!/usr/bin/env python
import sys
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='task_queue', durable=True)

message = ' '.join(sys.argv[1:]) or "Hello world!"
for i in range(10):
    channel.basic_publish(exchange='', routing_key='task_queue', body=message+str(i)
        , properties=pika.BasicProperties(
            delivery_mode=2, # make message persistent
    ))
print " [x] Sent %r" % (message,)
connection.close()
