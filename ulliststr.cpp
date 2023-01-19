#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){

  if(head_ == NULL){
    
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->prev = NULL;
    newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    size_++;
    newItem->val[0] = val;
    
  }
  else{
    if(tail_->last == 10){
      Item* newItem = new Item();
      newItem->first = 0;
      newItem->last = 1;
      tail_->next = newItem;

      newItem->prev = tail_;
      newItem->next = NULL;
      tail_ = newItem;
      size_++;
      newItem->val[0] = val;
    }
    else{
      tail_->val[tail_->last] = val;
      size_++;
      (tail_->last)++;
    }
  }
}

void ULListStr::push_front(const std::string& val){
  if(head_ == NULL){
    Item* newItem = new Item();
    newItem->first = 9;
    newItem->last = 10;
    newItem->prev = NULL;
    newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    size_++;
    newItem->val[9] = val;
  }
  else{
    if(head_->first == 0){
      Item* newItem = new Item();
      newItem->first = 9;
      newItem->last = 10;
      head_->prev = newItem;
      newItem->next = head_;
      newItem->prev = NULL;
      head_ = newItem;
      size_++;
      newItem->val[9] = val;
    }
    else{
      head_->val[(head_->first) - 1] = val;
      (head_->first)--;
      size_++;
    }
  }

}

void ULListStr::pop_back(){
  if(size_ == 1 && tail_->last - tail_->first == 1){
    Item* temp = tail_;
    head_ = NULL;
    tail_ = NULL;
    size_--;
    delete temp; 
  }
  else if(tail_->last - tail_->first == 1){
    Item* temp = tail_;
    temp->prev->next = NULL;
    tail_ = temp->prev;
    size_--;
    
    delete temp;
  }
  else{
    tail_->val[(tail_->last) - 1] = "";
    tail_->last--;
    size_--;
  }
}

void ULListStr::pop_front(){
  if(size_ == 1 && head_->last - head_->first == 1){
    Item* temp = head_;
    head_ = NULL;
    tail_ = NULL;
    size_--;
    delete temp;
  }
  else if(head_->last - head_->first == 1){
    Item* temp = head_;
    temp->next->prev = NULL;
    head_ = temp->next;
    size_--;
    delete temp;
  }
  else{
    head_->val[(head_->first)] = "";
    head_->first++;
    size_--;
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[(tail_->last) - 1];

}
std::string const & ULListStr::front() const{
  return head_->val[head_->first];

}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  
  
  if(loc >= size_){
    
    return NULL;
  }
  else{
    
    Item* temp = head_;
    int cnt = 0;
    while(temp != NULL){
      if((temp->last - temp->first) + cnt > loc){

        return &( temp->val[loc-cnt + temp->first] );
      }
      else{
        cnt += temp->last - temp->first;
        temp = temp->next;
      }
      

    }
  }
  return NULL;
}



















void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
