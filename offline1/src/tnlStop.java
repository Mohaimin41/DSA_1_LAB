public class tnlStop {
    private boolean isBusStop;
    private boolean isTrainStop;

    public tnlStop() {
        this.isBusStop = this.isTrainStop = false;
    }

    public tnlStop(boolean isBusStop, boolean isTrainStop) {
        this.isBusStop = isBusStop;
        this.isTrainStop = isTrainStop;
    }

    public boolean isBusStop() {
        return isBusStop;
    }

    public void setBusStop(boolean busStop) {
        isBusStop = busStop;
    }

    public boolean isTrainStop() {
        return isTrainStop;
    }

    public void setTrainStop(boolean trainStop) {
        isTrainStop = trainStop;
    }

    @Override
    public String toString() {
        return "bus : " + isBusStop + " ,train: " + isTrainStop + " ";
    }
}
