public class LinkedList<E> implements list<E>{
    private ArrList<E> value;
    private ArrList<Integer> link;

    private int head;
    private int curr;
    private int length;

    public LinkedList(int chunkSize, E[] listElements) {
        value = new ArrList<>(chunkSize, listElements);
        length = listElements.length;

        //set link arrList
        setLinkArrList();

        head = curr = 0;
    }

    public LinkedList(int stops) {
        value = new ArrList<>(stops);
        link = new ArrList<Integer>(stops);
        length = stops;
        head = curr = 0;
    }

    @Override
    public void clear() {
        value.clear();
        link.clear();
        head = curr = length = 0;
    }

    @Override
    public void insert(E item) {
        value.insert(item);
        //first increase length
        length++;

        //reset link arrList
        setLinkArrList();
    }

    @Override
    public void append(E item) {
        value.append(item);

        //first increase length
        length++;

        //reset link arrList
        setLinkArrList();
    }

    @Override
    public E remove() {
        //decrease length
        length--;
        //reset link arrList
        setLinkArrList();

        //return and remove value
        return value.remove();
    }

    @Override
    public void moveToStart() {
        value.moveToStart();
        link.moveToStart();
        curr = 0;
    }

    @Override
    public void moveToEnd() {
        value.moveToEnd();
        link.moveToEnd();
        curr = length -1;
    }

    @Override
    public void prev() {
        if (curr != 0) {
            value.prev();
            link.prev();
            curr--;
        }
    }

    @Override
    public void next() {
        if(curr < length - 1) {
            value.next();
            link.next();
            curr++;
        }
    }

    @Override
    public int length() {
        return length;
    }

    @Override
    public int currPos() {
        return curr;
    }

    @Override
    public void moveToPos(int pos) {
        if(pos < 0 || pos > length - 1) {
            System.out.println("index out of bound at moveToPos call in LinkedList");
        } else {
            curr = pos;
            value.moveToPos(pos);
            link.moveToPos(pos);
        }
    }

    @Override
    public E getValue() {
        return value.getValue();
    }

    @Override
    public int search(E item) {
        return value.search(item);
    }

    private void setLinkArrList() {
        //integer array of current length
        Integer[] linkElem = new Integer[length];
        for (int i = 1; i < length - 1; i++)
            linkElem[i-1] = i;

        //reset link arrList
        link = new ArrList<>(length, linkElem);
        link.append(-1);
    }
}
