#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct ArrayList
{
    int *elements;
    int max_elements;
    int size;
    int pos;
}ArrayList;

ArrayList *get_array_list(int max_elements);
void insert_array_list(ArrayList *al, int element);
void append_array_list(ArrayList *al, int element);
int remove_array_list(ArrayList *al);
int get_element_array_list(ArrayList *al);
void next_array_list(ArrayList *al);
void previous_array_list(ArrayList *al);
void clear_array_list(ArrayList *al);
void free_array_list(ArrayList *al);
int get_size_array_list(ArrayList *al);
int is_empty_array_list(ArrayList *al);
int at_end_array_list(ArrayList *al);
int at_start_array_list(ArrayList *al);
void go_to_start_array_list(ArrayList *al);
void go_to_end_array_list(ArrayList *al);
int get_pos_array_list(ArrayList *al);
void go_to_pos_array_list(ArrayList *al, int pos);
int contains_array_list(ArrayList *al, int element);
void print_array_list(ArrayList *al);
void grow_array_list(ArrayList *al);

#endif