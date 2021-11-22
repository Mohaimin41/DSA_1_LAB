public class ArrayList<E> implements List<E> {
    private final int chunkSize; //given chunkSize
    private int curr; //current position in the list
    private int length; //current length of list
    private E[] listArray;

    ArrayList() {
        curr = length = chunkSize = 0;
        listArray = (E[]) new Object[0];
    }

    ArrayList(int chunkSize, E[] listElements) {
        this.chunkSize = chunkSize;
        this.length = listElements.length;
        curr = 0;
        listArray = (E[]) new Object[chunkSize];
        for (int i = 0; i < length; i++)
            listArray[i] = listElements[i];
    }

    @Override
    public void clear() {
        curr = length = 0;
    }

    @Override
    public void insert(E item) {

        //create a temp array to swap values
        E[] temp = (E[]) new Object[length];
        for (int i = 0; i < length; i++)
            temp[i] = listArray[i];

        //check if current length is enough, if not, do a bigger listArray initialization;
        if ((length % chunkSize) == 0) {
            //check how much current length is over chunkSize
            int t = length / chunkSize;

            //reset listArray
            listArray = (E[]) new Object[(t + 1) * chunkSize];

            //copy till curr is reached
            for (int i = 0; i < curr; i++) {
                listArray[i] = temp[i];
            }
        }

        //insert
        listArray[curr] = item;

        //copy from curr position to length - 1 from temp to listArray, here listArray index is +1 of temp index
        for (int i = curr; i < length; i++)
            listArray[i+1] = temp[i];

        //increase length by 1
        length++;
    }


    @Override
    public void append(E item) {
        //first check if current length is enough, if not, do a bigger listArray initialization;
        if ((length % chunkSize) == 0) {
            extendSizeAndCopy();
        }
        //append and increase length
        listArray[length++] = item;
    }

    @Override
    public E remove() {
        //store current element
        E temp = listArray[curr];

        //from curr to length -1  position, shift array elements one step left
        for (int i = curr; i < length - 1; i++)
            listArray[i] = listArray[i + 1];

        //decrease length
        length--;

        //return current element
        return temp;
    }

    @Override
    public void moveToStart() {
        curr = 0;
    }

    @Override
    public void moveToEnd() {
        curr = length - 1;
    }

    @Override
    public void prev() {
        if (curr > 0)
            curr--;
    }

    @Override
    public void next() {
        if (curr < length - 1)
            curr++;
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
        if (pos >= 0 && pos < length)
            curr = pos;
        else
            System.out.println("Given position out of bounds");
    }

    @Override
    public E getValue() {
        return listArray[curr];
    }

    @Override
    public int search(E item) {
        for (int i = 0; i < length; i++) {
            if (listArray[i].equals(item))
                return i;
        }
        return -1;
    }

    private void extendSizeAndCopy() {
        //check how much current length is over chunkSize
        int t = length / chunkSize;

        //create a temp array to swap values
        E[] temp = (E[]) new Object[length];
        for (int i = 0; i < length; i++)
            temp[i] = listArray[i];

        //reset listArray
        listArray = (E[]) new Object[(t + 1) * chunkSize];

        //copy from temp
        for (int i = 0; i < length; i++)
            listArray[i] = temp[i];
    }
}
