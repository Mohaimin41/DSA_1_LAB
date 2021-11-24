import java.util.Scanner;

public class tnlMain {
    public static void main(String[] args) {
        int stops, busStops, trainStops;
        int task;

        Scanner input = new Scanner(System.in);
        stops = input.nextInt();
        busStops = input.nextInt();

        boolean[][] hasBusOrTrainStop = new boolean[2][stops]; //row 0 for bus stop, 1 for train stop

        //taking input busStops;
        for (int i = 0; i < busStops; i++) {
            hasBusOrTrainStop[0][input.nextInt()] = true;
        }

        trainStops = input.nextInt();

        //taking input trainStops
        for (int i = 0; i < trainStops; i++) {
            hasBusOrTrainStop[1][input.nextInt()] = true;
        }

        //now create a list for tnlStop, setting current number of stops as chunkSize, append all stops to it
//        ArrList<tnlStop> TNLstops = new ArrList<>(stops);
        LinkedList<tnlStop> TNLstops = new LinkedList<>(stops);

        for (int i = 0; i < stops; i++) {
            TNLstops.append(new tnlStop(hasBusOrTrainStop[0][i], hasBusOrTrainStop[1][i]));
        }

        //task input part
        task = input.nextInt();

        if (task == 1) {
            printTNLstops(TNLstops);
        }

    }

    static void printTNLstops(list<tnlStop> tnlStopsList) {
        //store the list's currPos
        int current = tnlStopsList.currPos();

        //iterate over list 3 times and print for task 1
        for (int i = 0; i < tnlStopsList.length(); i++) {
            System.out.print(i);
            if (i < tnlStopsList.length() - 1)
                System.out.print(",");
        }
        System.out.print("\n");

        for (tnlStopsList.moveToStart(); tnlStopsList.currPos() < tnlStopsList.length(); tnlStopsList.next()) {
            if (tnlStopsList.getValue().isBusStop()) {
                System.out.print(tnlStopsList.currPos());
            }

//            System.out.print(tnlStopsList.getValue().toString());

            if (tnlStopsList.currPos() < tnlStopsList.length() - 1) {
                System.out.print(",");
            }
        }
        System.out.print("\n");

        for (tnlStopsList.moveToStart(); tnlStopsList.currPos() < tnlStopsList.length(); tnlStopsList.next()) {
            if (tnlStopsList.getValue().isTrainStop()) {
                System.out.print(tnlStopsList.currPos());
            }

//            System.out.print(tnlStopsList.getValue().toString());

            if (tnlStopsList.currPos() < tnlStopsList.length() - 1) {
                System.out.print(",");
            }
        }
    }
}
