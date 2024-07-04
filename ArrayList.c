#include "ArrayList.h"

ArrayList *get_array_list(int max_elements){
    ArrayList *al = (ArrayList *)malloc(sizeof(ArrayList));
    if(al == NULL){
        printf("%s\n", "Could not allocate memory for arraylist");
        return NULL;
    }
    al->elements = (int *)malloc(sizeof(int) * max_elements);
    if(al->elements == NULL){
        printf("%s\n", "Could not allocate memory for arraylist elements");
        free(al);
        return NULL;   
    }
    al->size = al->pos = 0;
    al->max_elements = max_elements;
    return al;
}

void insert_array_list(ArrayList *al, int element){
    if(al->size == al->max_elements){
        grow_array_list(al);
    }
    for (int i = al->size; i > al->pos; i--){
        al->elements[i] = al->elements[i - 1];
    }
    al->elements[al->pos] = element;
    al->size++;
}

void append_array_list(ArrayList *al, int element){
    if(al->size == al->max_elements){
        grow_array_list(al);
    }
    al->elements[al->size++] = element;
}

int remove_array_list(ArrayList *al){
    if(al->size == 0){
        printf("%s\n", "Cannot remove element from empty arraylist");
        exit(EXIT_FAILURE);
    }
    int element = al->elements[al->pos];
    for (int i = al->pos; i < al->size - 1; i++){
        al->elements[i] = al->elements[i + 1];
    }
    al->size--;
    return element;
}

int get_element_array_list(ArrayList *al){
    if(al->size == 0){
        printf("%s\n", "Cannot get element from empty arraylist");
        exit(EXIT_FAILURE);
    }
    return al->elements[al->pos];
}

void next_array_list(ArrayList *al){
    if(al->pos == al->size){
        printf("%s\n", "Cannot go to next position");
        return;
    }
    al->pos++;
}

void previous_array_list(ArrayList *al){
    if(al->pos == 0){
        printf("%s\n", "No previous element on position 0");
        return;
    }
    al->pos--;
}

void clear_array_list(ArrayList *al){
    al->pos = al->size = 0;
}

void free_array_list(ArrayList *al){
    free(al->elements);
    al->elements = NULL;
    free(al);
    al = NULL;
}

int get_size_array_list(ArrayList *al){
    return al->size;
}

int is_empty_array_list(ArrayList *al){
    return al->size == 0;
}

int at_end_array_list(ArrayList *al){
    return al->size == al->pos;
}

int at_start_array_list(ArrayList *al){
    return al->pos == 0;
}

void go_to_start_array_list(ArrayList *al){
    al->pos = 0;
}

void go_to_end_array_list(ArrayList *al){
    al->pos = al->size;
}

int get_pos_array_list(ArrayList *al){
    return al->pos;
}

void go_to_pos_array_list(ArrayList *al, int pos){
    if(pos < 0 || pos > al->size){
        printf("%s\n", "Cannot go to invalid position on arraylist");
        exit(EXIT_FAILURE);
    }
    al->pos = pos;
}

int contains_array_list(ArrayList *al, int element){
    for (int i = 0; i < al->size; i++){
        if(al->elements[i] == element)
            return 1;
    }
    return 0;
}

void print_array_list(ArrayList *al){
    printf("%s", "[");
    for (int i = 0; i < al->size; i ++){
        printf("%i ", al->elements[i]);
    }
    printf("%s\n", "]");
}



void grow_array_list(ArrayList *al){
    al->max_elements = al->max_elements * 2;
    al->elements = realloc(al->elements, sizeof(int) * al->max_elements);
    if(al->elements == NULL){
        printf("%s\n", "Could not reallocate memory of array");
        return;
    }
}