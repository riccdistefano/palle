typedef struct
{
    float *elements;
    int length; // num elementi
    int capacity; // grandezza array
} dyn_arr;

dyn_arr create();
void add(dyn_arr *arr, float element);
void remove2(dyn_arr *arr, float element);
void remove_at(dyn_arr *arr, int pos);
void insert(dyn_arr *arr, float element, int pos);
void clear(dyn_arr *arr);
void trim(dyn_arr *arr);
void set_capacity(dyn_arr *arr, int capacity);
void set(dyn_arr *arr, float element, int pos);
float get(dyn_arr *arr, int pos);
int find(dyn_arr *arr, float element);