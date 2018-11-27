# 单链表反转

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkList:
    def __init__(self, head):
        self.head = head
        self.tail = head
        self.len  = 0
    def append(self, node):
        self.tail.next = node
        self.tail      = node
        self.len += 1
    def __str__(self):
        s = '[len = %d] ' % (self.len)
        cur = self.head.next
        while(cur != None):
            s += str(cur.data) + '-'
            cur = cur.next
        return s

if __name__ == '__main__':
    head = Node(-1)
    l = LinkList(head)
    print(l)

    for i in range(10):
        l.append(Node(i))
    print(l)