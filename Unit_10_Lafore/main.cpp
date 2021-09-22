#include <iostream>
using namespace std;

enum {ARR_SIZE = 8};

void not_pointer_madness();
void three_arrays();

int main()
{
    //not_pointer_madness();
    three_arrays();
    return 0;
}

void not_pointer_madness()
{
//    float *array_of_elements = new float [ARR_SIZE];
//    float general = array_of_elements[0];
//    for(int i = 0; i < ARR_SIZE; i++)
//    {
//        cout << "Enter " << 1+i << " element: ";
//        cin >> *(array_of_elements+i);
//    }
//
//    for(int i = 0; i < ARR_SIZE; ++i)
//        general += *(array_of_elements + i);
//    cout << "Average: " << general/ARR_SIZE;
}

void three_arrays()
{
    void two_arr_into_one(const float *first, const float *second, float *&third);
    float *first, *second, *third;
    first = new float [ARR_SIZE];
    second = new float [ARR_SIZE];
    third = new float [ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++)
    {
        first[i] = static_cast<float>(i);
        second[i] = static_cast<float>( i + 2);
    }

    two_arr_into_one(first, second, third);

    for(int i = 0; i < ARR_SIZE; i++)
        cout << third[i] << " ";
}
void two_arr_into_one(const float *first, const float *second, float *&third)
{
    for(int i = 0; i < ARR_SIZE; i++)
        *(third + i) = *(second + i) + *(first + i);
}