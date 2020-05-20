def mergeLists(headOne, headTwo):
    p1 = headOne
    p1prev = None
    p2 = headTwo

    while p1 is not None and p2 is not None:
        if p1.value < p2.value:
            p1prev = p1
            p1 = p1.next
        else:
            if p1prev is not None:
                p1prev.next = p2
            p1prev = p2
            p2 = p2.next
            p1prev.next = p1

    if p1 is None:
        p1prev.next = p2

    return headOne if headOne.value < headTwo.value else headTwo


def mergeLinkedLists(headOne, headTwo):
    result = None
	trav = result
	while (headOne is not None and headTwo is not None):
		if (headOne.value <= headTwo.value):
			if trav is None:
				trav = LinkedList(headOne.value)
			else:
				trav.next = LinkedList(headOne.value)
			headOne = headOne.next
		else:
			if trav is None:
				trav = LinkedList(headTwo.value)
			else:
				trav.next = LinkedList(headTwo.value)
			headTwo = headTwo.next
			
	while(headOne is not None):
		trav.next = LinkedList(headOne.value)
		headOne = headOne.next
		
	while(headTwo is not None):
		trav.next = LinkedList(headTwo.value)
		headTwo = headTwo.next
	
	return result