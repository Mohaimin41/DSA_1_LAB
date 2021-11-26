public class LinkedList<E> implements list<E> {
    private link<E> head;
    private link<E> tail;
    private link<E> curr;
    private int listLength;

    public LinkedList() {
        curr = head = tail = new link<E>(null);
        listLength = 0;
    }

    public LinkedList(int chunkSize) {
        this();
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
         //then just advance tail
            tail.setNextLink(new link<E>(listElements[i], null));
            tail = tail.getNextLink();
        }
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
        tail = tail.getNextLink();
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

        //if somehow curr == tail, nothing to return, but curr needs to go back one step
        if (curr == tail) {
            res = null;
            prev();
        } else {
            //make curr skip one link
            curr.setNextLink(curr.getNextLink().getNextLink());
        }
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

        if(curr != tail)
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
        if (pos < 0 || pos >= listLength)
            System.out.println("out of bound position");
        else {
            //set a counter and curr at start
            curr = head;
            int runningPos = 0;

            //start traverse from head, stop at pos - 1
            while (runningPos < pos) {
                runningPos++;
                curr = curr.getNextLink();
            }
        }
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
