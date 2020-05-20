def reverseLinkedList(head):
    prev = None
	current = head
	nextToCurrent = head.next
	
	while nextToCurrent is not None:
		store = nextToCurrent.next
		current.next = prev
		nextToCurrent.next = current
		prev = current
		current = nextToCurrent
		nextToCurrent = store
	return current


def reverseLinkedListClean(head):
    p1, p2 = None, head
    while p2 is not None:
        p3 = p2.next
        p2.next = p1
        p1 = p2
        p2 = p3
    return p1