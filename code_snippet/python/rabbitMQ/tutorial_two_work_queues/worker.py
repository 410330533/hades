#!/usr/bin/env python
import time
import pika

count = 0
def callback(ch, method, properties, body):
    global count
    count += 1
 
    print " [x] Received %r %d" % (body, count)
    time.sleep(body.count('.'))
    print " [x] Done"
    ch.basic_ack(delivery_tag = method.delivery_tag)

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='task_queue', durable=True)
print ' [*] waiting for messages. To exit press CTRL+C'

channel.basic_qos(prefetch_count=1) # Fair dispatch
channel.basic_consume(callback, queue='task_queue')
channel.start_consuming()

