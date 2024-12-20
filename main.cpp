#include <algorithm>
#include <cinttypes>
#include <exception>
#include <iostream>

class MinHeap{

  private:
    int capacity = 10;
    int size = 0;

    int items[10] ;   

    int getLeftChildIndex(int parentIndex){

      return 2 * parentIndex + 1;

    }

    int getRightChildIndex(int parentIndex){

      return 2 * parentIndex +2 ;

    }

    int getParentIndex(int childIndex){

      return (childIndex -1 )/2;


    }

    bool hasLeftChild(int index){

      return getLeftChildIndex(index);

    }

    bool hasRightChild(int index){

      return getRightChildIndex(index);

    }

    bool hasParent(int index){

      return getParentIndex(index) >= 0;

    }

    int leftChild(int index){

      return items[getLeftChildIndex(index)];
      
    }

    
    int rightChild(int index){

      return items[getRightChildIndex(index)];
      
    }

    int parent(int index){

      return items[getParentIndex(index)];

    }
    
    void swap(int indexOne , int indexTwo){

      int temp = items[indexOne];
      items[indexOne] = items[indexTwo];
      items[indexTwo] = temp;
    }

  public:
    int peek(){

      if (size == 0) throw new std::exception;
      return items[0];

    }

    int poll(){

      if (size == 0) throw new std::exception;

      int item  = items[0];

      items[0] = items[size - 1];

      size -- ;

      heapifyDown();
      return item;
      

    }

    void add(int item){

      if (size == capacity){
        return;
      }

      items[size] = item ;

      size ++;
      heapifyUp();

    }

    void heapifyUp(){

      int index = size - 1;
      while (hasParent(index) && parent(index) > items[index]){

        swap(getParentIndex(index),index);

        index = getParentIndex(index);
      }

    }

    void heapifyDown(){

      int index = 0 ;

      while (hasLeftChild(index)){

        int smallerChildIndex = getLeftChildIndex(index);

        if (hasRightChild(index) && rightChild(index) < leftChild(index)){

          smallerChildIndex = getRightChildIndex(index);

        }

        if (items[index] < items[smallerChildIndex]){

          break;

        }

        else{

          swap(index, smallerChildIndex);

        }
        index = smallerChildIndex;
        



      }

    }

    void printArray(){

      for (int i =0; i < size; i++){

        std::cout << items[i] <<std::endl;


      }

    }






};

int main() {


  MinHeap m;
  m.add(5);
  m.add(1);
  m.add(4);
  m.add(10);

  
  std::cout << m.peek()<<std::endl;
  std::cout << m.poll()<<std::endl;

  std::cout << m.poll()<<std::endl;
  std::cout << m.poll()<<std::endl;
  return 0;




}
