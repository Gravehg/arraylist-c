#include "ArrayList.h"

int main(){
    ArrayList *al = get_array_list(1024);
    printf("%s\n", "The linked list has the following options:");
    printf("%s\n", "Append an element to the end of the list");
    printf("%s\n", "Insert an element at the current position of the list");
    printf("%s\n", "Remove the current element of the list");
    printf("%s\n", "Get the current element of the list");
    printf("%s\n", "Go to the next element of the list");
    printf("%s\n", "Go to the previous element of the list");
    printf("%s\n", "Free the current list");
    printf("%s\n", "Check if the list is empty");
    printf("%s\n", "Check the size of the list");
    printf("%s\n", "Check if the current element is the start of the list");
    printf("%s\n", "Check if the current pointer is at the last element");
    printf("%s\n", "Clear the list of any elements");
    printf("%s\n", "See if an element is in the list");
    printf("%s\n", "Get the current position of the list");
    printf("%s\n", "Go to a specific position of the list");
    printf("%s\n", "Go to the start of the list");
    printf("%s\n", "Go to the end of the list");
    printf("%s\n", "Get a pointer to a linked list");
    printf("%s\n", "Print the linked list");

    printf("%s\n", "Appending elements... ");
    for (int i = 0; i < 10; i++){
        append_array_list(al, i);
    }
    print_array_list(al);
    printf("%s\n", "Removing elements from list..");
    for (go_to_start_array_list(al); !at_end_array_list(al);){ //Its the first time I use this kind of for loop
        printf("%s%i\n","Removing: ", remove_array_list(al));
    }
    print_array_list(al);
    printf("%s\n", "Appending new elements...");
    for (int i = 0; i < 10; i++){
        append_array_list(al, i * 2);
    }
    print_array_list(al);
    printf("%s\n", "Inserting elements...");
    for (int i = 0; i < 10; i++)
    {
        insert_array_list(al, i - 1 );
    }
    print_array_list(al);
    printf("%s\n", "Retrieving elements...");
    for (go_to_start_array_list(al); !at_end_array_list(al); next_array_list(al))
    {
        printf("%s%i\n", "Element at current position is: ", get_element_array_list(al));
    }
    printf("%s%i\n", "Current size of linked list is: ", get_size_array_list(al));
    printf("%s%i\n", "Currently at position: ", get_pos_array_list(al));
    printf("%s\n", "Going to pos 5");
    go_to_pos_array_list(al, 5);
    printf("%s%i\n", "Currently at position: ", get_pos_array_list(al));
    printf("%s%i\n", "Contains -1?", contains_array_list(al, -1));
    printf("%s\n", "Going to start");
    go_to_start_array_list(al);
    printf("%s%i\n", "Currently at position: ", get_pos_array_list(al));
    printf("%s\n", "Going to end");
    go_to_end_array_list(al);
    printf("%s%i\n", "Currently at position: ", get_pos_array_list(al));
    free_array_list(al);
    exit(0);
}