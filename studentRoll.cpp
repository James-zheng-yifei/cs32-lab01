#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll()
{
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s)
{
  Node* newNode = new Node;
  newNode->s = new Student(s);
  newNode->next = nullptr;
  if(head == nullptr) head = tail = newNode;
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

std::string StudentRoll::toString() const
{
  Node* curr = head;
  std::string result;
  result += '[';
  while(curr) {
    result += curr->s->toString();
    if(curr->next != nullptr) result += ',';
    curr = curr->next;
  }
  result += ']';
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig)
{
  if (orig.head == nullptr)
  {
    this->head = nullptr;
    this->tail = nullptr;
    return;
  }
  this->head = new Node;
  this->head->s = new Student(*(orig.head->s));
  this->head->next = nullptr;

  Node *curr1 = this->head;
  Node *curr2 = orig.head->next;

  while (curr2)
  {
    Node *newNode = new Node;
    newNode->s = new Student(*(curr2->s));
    newNode->next = nullptr;
    curr1->next = newNode;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  tail = curr1;
}

StudentRoll::~StudentRoll() {
  Node* temp;
  while(head != nullptr) {
    temp = head->next;
    delete head->s;
    delete head;
    head = temp;
  }
}

StudentRoll &StudentRoll::operator=(const StudentRoll &right)
{
  if(&right==this)return *this;
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up
  // memory before you copy from it.  (e.g. x = x)

  StudentRoll temp(right);
  std::swap(this->head,temp.head);
  std::swap(this->tail,temp.tail);
  return *this;

/*
  if (&right == this)
    return (*this);

  Node* temp;
  while(head != nullptr) {
    temp = head->next;
    delete head->s;
    delete head;
    head = temp;
  }

  if (right.head == nullptr)
  {
    this->head = nullptr;
    return *this;
  }
  this->head = new Node;
  this->head->s = new Student(*(right.head->s));
  this->head->next = nullptr;

  Node *curr1 = this->head;
  Node *curr2 = right.head->next;

  while (curr2)
  {
    Node *newNode = new Node;
    newNode->s = new Student(*(curr2->s));
    newNode->next = nullptr;
    curr1->next = newNode;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  tail = curr1;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this);
  */
}
