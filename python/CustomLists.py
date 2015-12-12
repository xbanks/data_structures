class Node():
	"""docstring for Node"""
	def __init__(self, element = None, prev = None, nxt = None):
		self.element = element
		self.prev = prev
		self.next = nxt
		
	def __str__(self):
		return "Node [%s]" % str(self.element)

class LinkedList(object):
	"""docstring for LinkedList"""
	def __init__(self, element = None):
		self.head = None if element is None else Node(element)
		self.tail = self.head
		self.length = 0 if self.head is None else 1

	# adds to the tail of the list
	def add(self, element):
		if self.head is None:
			self.head = Node(element)
			self.tail = self.head
		else:
			tail = Node(element, self.tail)
			self.tail.next = tail
			self.tail = tail

		self.length += 1
		# returns the list to allow for chaining
		return self

	def get(self, index):
		node = self.head
		while node is not None and index > 0:
			node = node.next
			index -= 1

		return node

	def remove(self, index):
		if index >= self.length:
			return self
		if index is 0:
			self.head = self.head.next
		else:
			node = self.head
			while index > 0 and node is not None:
				node = node.next
				index -= 1

			if index is 0:
				if node.prev is not None:
					node.prev.next = node.next
				if node.next is not None:
					node.next.prev = node.prev
		return self

	def __str__(self):
		lst = []
		node = self.head
		while node is not None:
			lst += [node.element]
			node = node.next
		return str(lst)

