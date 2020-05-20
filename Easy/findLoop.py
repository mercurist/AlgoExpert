# This is an input class. Do not edit.
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None


def findLoop(head):
    trav = head
	table = dict()
	while trav is not None:
		if trav in table:
			return trav
		table[trav] = 1
		trav = trav.next
	return None