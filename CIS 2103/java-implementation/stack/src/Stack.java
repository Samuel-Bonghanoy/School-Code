
public class Stack implements IStack {
  private int size;
  private char[] data;
  private int top = -1;
  
  public Stack(int capacity) {
    if (capacity < 0) throw new IllegalArgumentException();
    this.data = new char[capacity];
    this.size = capacity - 1;
  }


  public void push(char elem){
    if(top < size) {
      top++;
      data[top] = elem;
    }
  }

  public void pop(){
    if(top >= 0) {
      top--;
    }
  }
  
  public char top(){
    if(Character.getNumericValue(data[top]) < 0){
      throw new ArrayIndexOutOfBoundsException();
    }
    return data[top];
  }
    
  
  public boolean isEmpty(){
    return top == -1;
  }
    /**
    * @brief Returns true (1) if the stack is empty, otherwise false (0).
    * 
    * @return true 
    * @return false 
    */
  
  public boolean isFull(){
    return top == size;
  }
  
  public void displayStack(){
    for(int x = top; x >= 0; x--){
      System.out.println("Index " + (x + 1) + ": " + data[x]);
    }
  }
  
}
