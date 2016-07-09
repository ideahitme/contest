import sys


class Node():
	def __init__(self, data=None, next_node=None):
		self.data = data
		self.next = next_node


def traverse(head):
	while head:
		print head.data
		head = head.next

def insert_tail(head, data):
	if head is None: 
		head = Node(data)
		return head
	cur = head
	while cur.next:
		cur = cur.next
	cur.next = Node(data)
	return head

def insert_head(head, data):
	new_head = Node(data)
	new_head.next = head
	return new_head

def insert_at(head, data, position):
	if head is None:
		head = Node(data)
		return head
	else:
		if position == 0:
			new_head = Node(data)
			new_head.next = head
			return new_head
		pre = head
		cur = head.next
		while position > 1:
			position -= 1
			pre = cur
			cur = cur.next
		to_insert = Node(data)
		pre.next = to_insert		
		to_insert.next = cur
		return head
def delete_at(head, position):
	if position == 0:
		return head.next
	pre = head
	cur = head.next
	while position > 1:
		position -= 1
		pre = cur
		cur = cur.next
	pre.next = cur.next
	return head

def reverse_print(head):
	if head is None:
		return
	else:
		reverse_print(head.next)
		print head.data
		return head

def reverse(head):
	if head is None:
		return
	else:
		start = head
		after = start.next
		head.next = None
		while after:
			tmp = after.next
			after.next = start
			start = after
			if tmp: after = tmp
			else: break
		return after

def merge_sorted_lists(head1, head2):
	cur1 = head1
	cur2 = head2
	if head1 is None: return head2
	if head2 is None: return head1
	if head1.data < head2.data:
		head = head1
		cur1 = head1
		cur2 = head2
	else:
		head = head2
		cur2 = head1
		cur1 = head2
	while cur1.next is not None and cur2 is not None:
		if cur1.next.data > cur2.data:
			tmp = cur1.next
			cur1.next = cur2
			cur2 = tmp
		cur1 = cur1.next
	if cur1.next is None: 
		cur1.next = cur2

	return head

def get_node_from_end(head, position):
	cur = head
	length = 0
	while cur.next is not None:
		length += 1
		cur = cur.next
	cur = head
	from_top = length - position
	while from_top > 0:
		cur = cur.next
		from_top -= 1
	print cur.data
	return cur.data

def has_cycle(head):
	if head is None or head.next is None: return 0
	retard = head
	genius = head
	has_cycle = 0
	while genius.next is not None:
		if genius.data == retard.data:
			has_cycle = 1
			break
		genius = genius.next
		if genius.next is None: break
		if genius.data == retard.data:
			has_cycle = 1
			break
		genius = genius.next
		retard = retard.next
	return has_cycle

def FindMergePoint(headA, headB):
	curA = headA
	curB = headB
	while curA.data != curB.data:
		curA = curA.next if curA.next is not None else headB
		curB = curB.next if curB.next is not None else headA
	return curA.data

def create():
	head = Node(5)
	cur = head
	cur.next = Node(4)
	cur = cur.next
	cur.next = Node(3)
	return head

def remove_duplicates(head):
	if head is None: return head
	cur = head
	while cur.next is not None:
		pointer = cur
		while pointer.next is not None and pointer.data == pointer.next.data:
			pointer = pointer.next
		if pointer.next is None: 
			break
		else:
			cur.next = pointer.next
			cur = pointer.next
	return head

head1 = insert_at(None, 2, 0)
head1 = insert_at(head1, 4, 1)
head1 = insert_at(head1, 3, 2)
head1 = insert_at(head1, 5, 3)
head1 = insert_at(head1, 7, 4)

head2 = insert_at(None, 6, 0)
head2 = insert_at(head2, 11, 1)
head2 = insert_at(head2, 3, 2)
head2 = insert_at(head2, 5, 3)
head2 = insert_at(head2, 7, 4)

print FindMergePoint(head1, head2)