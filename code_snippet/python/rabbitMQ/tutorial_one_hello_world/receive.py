#!/usr/bin/env python
import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')
print ' [*] waiting for messages. To exit press CTRL+C'
count = 0

def callback(ch, method, properties, body):
    global count
    count += 1
    print " [x] Received %r %d" % (body, count)
channel.basic_consume(callback, queue='hello', no_ack=True)
channel.start_consuming()

