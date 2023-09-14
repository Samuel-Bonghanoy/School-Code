public interface IStack {
  public void push(char elem);
    /**
    * @brief Adds the specified element to the top of the stack.
    * 
    * @param ch the element to add to the stack
    */

  public void pop();
   /**
   * @brief Removes the element at the top of the stack.
   * 
   */
  
  public char top();
    /**
    * @brief Returns the element at the top of the stack, otherwise (-1) if the stack is empty.
    * 
    * @return char 
    */
  
  public boolean isEmpty();
    /**
    * @brief Returns true (1) if the stack is empty, otherwise false (0).
    * 
    * @return true 
    * @return false 
    */
  
  public boolean isFull();
    /**
    * @brief Returns true (1) if the stack is full, otherwise false (0).
    * 
    * @return true 
    * @return false 
    */
  
  public void displayStack();
    /**
    * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
    * 
    */

}
