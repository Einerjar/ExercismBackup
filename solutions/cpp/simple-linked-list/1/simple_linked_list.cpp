#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.

    // Make the new element.
    Element new_elem = Element(entry);
    
    // Set the new element's next to head and the list's head new_elem.
    new_elem.next = head;
    head = &new_elem;

    // Update current size.
    current_size++;

}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.

    int value = head->data;
    head = head->next;

    current_size--;

    return value;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.

    // Traverse list until you reach the end.
    Element* curr = head;
    Element* last = nullptr;

    while (curr != nullptr) {
        // Move curr to the next stage while saving the current spot.
        Element* temp = curr;
        curr = curr->next;

        // Set temp (which is holding onto the last node)'s next value to the last
        // one, and set last to the current temp.
        temp->next = last;
        last = temp;
    }
    head = last;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    Element* curr = head;

    while (curr != nullptr) {
        Element* temp = curr;
        curr = curr->next;
        delete temp;
      
    }
    current_size = 0;
}

}  // namespace simple_linked_list
