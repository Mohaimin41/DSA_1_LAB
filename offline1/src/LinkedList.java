public class LinkedList<E> implements list<E> {
    private link<E> head;
    private link<E> tail;
    private link<E> curr;
    private int listLength;

    public LinkedList() {
        curr = head = tail = new link<E>(null);
        listLength = 0;
    }

    public LinkedList(int chunkSize, E[] listElements) {
        listLength = listElements.length;
        curr = tail = head = new link<E>(null);

        //set head to point to first of listElements array element link
        head.setNextLink(new link<E>(listElements[0], null));

        //now curr should equal head (curr points to previous elements in linkedList
        curr = head;

        //tail equals last element or element 0 here (which is pointed by head)
        tail = head.getNextLink();

        //append each remaining elements to linkedList;
        for(int i = 1; i < listLength; i++) {
//            //set current link to point at next element;
//            curr.getNextLink().setNextLink(new link<E>(listElements[i], null));
//
//            //advance curr till last -1 elements, last - 1 is for tail
//            if (i < listLength - 1)
//                curr = curr.getNextLink();
//            else
//                tail = curr.getNextLink();

            //or just advance tail
            tail.setNextLink(new link<E>(listElements[i], null));
            tail = tail.getNextLink();
        }
//
//        //set curr equal to head again
//        curr = head;
    }

    @Override
    public void clear() {
        //set head as only link
        head.setNextLink(null);
        //set header
        curr = head = tail = new link<E>(null);
        listLength = 0;
    }

    @Override
    public void insert(E item) {
        //insert at curr a new link
        curr.setNextLink(new link<E>(item, curr.getNextLink()));

        //check if tail is affected
        if(tail == curr)
            tail = curr.getNextLink();

        listLength++;
    }

    @Override
    public void append(E item) {
        tail.setNextLink(new link<E>(item, null));
        listLength++;
    }

    @Override
    public E remove() {
        //store element in temp;
        E res = (E) curr.getNextLink().getElement();

        //check if tail is affected
        if(tail == curr.getNextLink())
            tail = curr;

        //decrease length
        listLength--;

        //make curr skip one link
        curr.setNextLink(curr.getNextLink().getNextLink());

        return res;
    }

    @Override
    public void moveToStart() {
        curr = head;
    }

    @Override
    public void moveToEnd() {
        //first curr equal to tail
        curr = tail;

        //curr goes one step back
        prev();
    }

    @Override
    public void prev() {
        if(curr != head) {
            //start traverse from head
            link<E> temp = head;
            while (temp.getNextLink() != curr)
                temp = temp.getNextLink();
            curr = temp;
        }
    }

    @Override
    public void next() {
        if(curr.getNextLink() != null)
            curr = curr.getNextLink();
    }

    @Override
    public int length() {
        return listLength;
    }

    @Override
    public int currPos() {
        int res = 0;

        //start traverse from head
        link<E> temp = head;
        while (temp != curr) {
            temp = temp.getNextLink();
            res++;
        }

        return res;
    }

    @Override
    public void moveToPos(int pos) {
        //set a counter and curr at start
        curr = head;
        int runningPos = 0;

        //start traverse from head, stop at pos - 1
        while (runningPos < pos) {
            runningPos++;
            curr = curr.getNextLink();
        }

//        //pos is zero-indexed and while stopped at curr - 1, so advance curr once more
//        curr =  curr.getNextLink();
    }

    @Override
    public E getValue() {
        //if curr somehow at tail
        if (curr.getNextLink() == null)
            return null;

        return (E) curr.getNextLink().getElement();
    }

    @Override
    public int search(E item) {
        //set temp link and pos variable
        link<E> temp = head;
        int pos = 0;

        for(; pos < listLength; pos++) {
            if(temp.getNextLink().getElement().equals(item))
                return pos;

            //advance temp
            temp = temp.getNextLink();
        }
        return -1;
    }
}
