import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Object[] listElements;
        int length;
        int chunkSize;
        int functionNumber;
        Object param;
        Object result = null;

        Scanner input = new Scanner(System.in);
        length = input.nextInt();
        chunkSize = input.nextInt();

        listElements = new Object[length];
        for (int i = 0; i < length; i++)
            listElements[i] = input.nextInt();

        ArrList<Object> testList = new ArrList<>(chunkSize, listElements);
        printList(testList);

        do {
            functionNumber = input.nextInt();
            param = input.nextInt();

            if (functionNumber == 0) {
                break;
            } else if (functionNumber == 1) {
                testList.clear();
            } else if (functionNumber == 2) {
                testList.insert(param);
            } else if (functionNumber == 3) {
                testList.append(param);
            } else if (functionNumber == 4) {
                result = testList.remove();
            } else if (functionNumber == 5) {
                testList.moveToStart();
            } else if (functionNumber == 6) {
                testList.moveToEnd();
            } else if (functionNumber == 7) {
                testList.prev();
            } else if (functionNumber == 8) {
                testList.next();
            } else if (functionNumber == 9) {
                result = testList.length();
            } else if (functionNumber == 10) {
                result = testList.currPos();
            } else if (functionNumber == 11) {
                testList.moveToPos((Integer) param);
            } else if (functionNumber == 12) {
                result = testList.getValue();
            } else if (functionNumber == 13) {
                result = testList.search(param);
                //System.out.print(result);
            }

            printList(testList);
            if (result != null) {
                System.out.println(result);
            } else {
                System.out.println("-1");
            }

            result = null;
        } while (functionNumber != 0);

    }

    static void printList(ArrList test) {
        int current = test.currPos();
        System.out.print(current + " " + test.length() + " ");
        System.out.print("<");

        for (test.moveToStart(); test.currPos() < test.length(); test.next()) {
//            for (test.moveToStart(); test.currPos() < 3; test.next()) {
            if (current == test.currPos())
                System.out.print("| ");
            System.out.print(test.getValue());
            if (test.currPos() < test.length() - 1)
                System.out.print(" ");
        }
//        for (int i = 0; i < test.length(); i++) {
//            if (current == i)
//                System.out.print("| ");
//            test.moveToPos(i);
//            System.out.print(test.getValue());
//
//            if (i < test.length() - 1)
//                System.out.print(" ");
//        }
        System.out.println(">");

        if (current < test.length())
            test.moveToPos(current);
    }
}
