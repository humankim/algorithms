public class LinkedStackOfStrings {

    private Node first = null;

    public LinkedStackOfStrings() {
        first = new Node();
        first.item = "f_item";
    }

    private class Node{
        String item;
        Node next;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public void push(String item) {
        Node oldfirst = first;
        first.item = item;
        first.next = oldfirst;
    }

    public String pop() throws NullPointerException {
        String item = "";
        item = first.item;
        first = first.next;
        return item;
    }
}
