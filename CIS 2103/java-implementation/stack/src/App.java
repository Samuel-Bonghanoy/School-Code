public class App {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        Stack s = new Stack(10);
        System.out.println(s.isEmpty());
        s.push('A');
        s.push('B');
        s.push('C');
        s.push('D');
        s.push('E');
        s.push('F');
        s.push('F');
        s.push('F');
        s.push('F');
        s.push('F');
        s.push('F');
        s.push('F');
        s.push('F');
        s.push('F');
        
    
        s.displayStack();
        s.pop();
        System.out.println(s.top());
        System.out.println(s.isEmpty());
        System.out.println(s.isFull());
    }
}
