#pragma once

template <typename T>
class LinkedListBase
   {
      protected:      
         class Node
            {
               public:
                  T data;
                  Node* next;
                  Node(T value) : data(value) , next(nullptr){};
            };  

      Node* head = nullptr;

      LinkedListBase() = default;
      
      //Destructor
      ~LinkedListBase()
         {
            while(head)
               {
                  Node* temp = head;
                  head = head->next;
                  delete temp;
               }
         }

      //Copy semantics
      LinkedListBase(const LinkedListBase& other)
         {
            if(!other.head)
               {
                  head = nullptr;
                  return;
               }
            head = new  Node(other.head->data);
            Node* current = head;
            Node* src = other.head->next;
            while(src)
               {
                  current->next = new Node(src->data);
                  current = current->next;
                  src = src->next; 
               }
         }

      LinkedListBase& operator =(const LinkedListBase& other)
         {
            if(this == &other)
               {
                  return *this;
               }

            while(head)
               {
                  Node* temp = head;
                  head = head->next;
                  delete temp;
               }

            if(!other.head)
               {
                  head = nullptr;
                  return *this;
               }
            head = new Node(other.head->data);
            Node* current = head;
            Node* src = other.head->next;

            while(src)
               {
                  current->next = new Node(src->data);
                  current = current->next;
                  src = src->next;
               }
            return *this;
         }

      //move semantics
      LinkedListBase(LinkedListBase&& other)
         {
            this->head = other.head;
            other.head = nullptr;
         }

      LinkedListBase& operator =(LinkedListBase&& other)
         {
            if(this == &other)
               {
                  return *this;
               }

            while(head)
               {
                  Node* temp = head;
                  head = head->next;
                  delete temp;
               }
            head = other.head;
            other.head = nullptr;
            return *this;
         }

      //Exceptions
      public:
         class IndexOutOfBoundsException
            {
               public:
                  const char* what() const { return "Index out of bounds"; }
            };

         class ListEmptyException
            {
               public:
                  const char* what() const { return "List is empty"; }
            };

         class OutOfLineException
            {
               public:
                  const char* what() const { return "Out of line"; }
            };
   };

template <typename T>
class LinkedList : private LinkedListBase<T>
   {
      public:
         void InsertHead(T value)
            {
               typename LinkedListBase<T>::Node* NewNode = new typename LinkedListBase<T>::Node(value);
               NewNode->next = this->head;
               this->head = NewNode;
            }

         void Insert(int position, T value)
            {
               if(position == 0)
                  {
                     InsertHead(value);
                     return;
                  }

               typename LinkedListBase<T>::Node*  current = this->head;
                  for(int i = 0 ; i < position - 1 ; i++)
                     {
                        if (!current) 
                           {
                              throw typename LinkedListBase<T>::IndexOutOfBoundsException();
                           }
                        current = current->next;               
                     }
               typename LinkedListBase<T>::Node* NewNode = new typename LinkedListBase<T>::Node(value);
               NewNode->next = current->next;
               current->next = NewNode;
            }
         void InsertTail(T value)
            {
               typename LinkedListBase<T>::Node* NewNode = new typename LinkedListBase<T>::Node(value);
               if(!this->head)
                  {
                     this->head = NewNode;
                  }
               else
                  {
                     typename LinkedListBase<T>::Node* current = this->head;
                     while(current->next)
                        {
                           current = current->next;
                        }
                     current->next = NewNode;
                  }
            }
         T Get(int position)
            {
               typename LinkedListBase<T>::Node* current = this->head;    
               for (int i = 0; i < position; i++)
                  {
                     if (!current)
                        {
                              throw typename LinkedListBase<T>::IndexOutOfBoundsException();
                        }
                     current = current->next;
                  }
               if (!current)
                  {
                     throw typename LinkedListBase<T>::IndexOutOfBoundsException();
                  }
               return current->data;
            }
         void Remove(int position)
            {
               if(!this->head)
                  {
                     throw typename LinkedListBase<T>::ListEmptyException();
                  }
               if(position == 0)
                  {
                     typename LinkedListBase<T>::Node* temp = this->head;
                     this->head = this->head->next;
                     delete temp;
                     return;
                  }
               typename LinkedListBase<T>::Node* current = this->head;
                  for(int i = 0 ; i  < position - 1 ; i++)
                     {
                        if(!current || !current->next)
                           {
                              throw typename LinkedListBase<T>::OutOfLineException();
                           }
                        current = current->next;
                     }
               typename LinkedListBase<T>::Node* ToDelete = current->next;
                  if(!ToDelete)
                     {
                        throw typename LinkedListBase<T>::OutOfLineException();
                     }
                  current->next = ToDelete->next;
                  delete ToDelete;
            }
   };
