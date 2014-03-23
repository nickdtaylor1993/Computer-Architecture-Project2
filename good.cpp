#include <iostream>

using namespace std;
const int size = 75;
int array[size];
int result = 0;

int main()
{
        for(int i = 0; i < size; i++)
        {
                for(int j = 0; j < 5; j++)
                {
                        array[i] = array[i] + j;
                        result = array[i];
                }
        }
}
