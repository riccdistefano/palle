

typedef struct
{
    float *elements;
    int size;
    int capacity;
} dyn_arr;

dyn_arr create(); // works
void add(dyn_arr *arr, float element); // works
void remove2(dyn_arr *arr, float element); // works
void remove_at(dyn_arr *arr, int pos); // works
void insert(dyn_arr *arr, float element, int pos); // works
void clear(dyn_arr *arr); // works
void trim(dyn_arr *arr);  // works
void set_capacity(dyn_arr *arr, int capacity); // works
int lenght(dyn_arr *arr); // works
void set(dyn_arr *arr, float element, int pos); // works
float get(dyn_arr *arr, int pos); // works
int find(dyn_arr *arr, float element); // works