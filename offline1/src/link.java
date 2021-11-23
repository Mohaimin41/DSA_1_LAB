public class link<E> {
    private E element;
    private link nextLink;

    public link(E element, link nextLink) {
        this.element = element;
        this.nextLink = nextLink;
    }

    public link(link nextLink) {
        this.element = null;
        this.nextLink = nextLink;
    }

    public link() {
        this.element = null;
        this.nextLink = null;
    }

    public E getElement() {
        return element;
    }

    public void setElement(E element) {
        this.element = element;
    }

    public link getNextLink() {
        return nextLink;
    }

    public void setNextLink(link nextLink) {
        this.nextLink = nextLink;
    }
}
