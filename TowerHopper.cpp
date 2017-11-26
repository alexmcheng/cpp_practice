/*
Nov 25 2017, Alex Cheng
This function uses recursion to decide if a tower is hoppable.
Hoppable means we can hop past the length of the array.
Hopping is moving to a further array index from the current one.
The current array element value determines how many indices can be hopped.
Ex, the '3' at position 0 allows us to move to position 3 at the furthest:
3 2 0 2 3 1
_
0 1 2 3 4 5
From there, we can hop to position 5 because of the '2', and from there, we can hop out of bounds to 6.
*/
#include <iostream>
bool isHoppable(int *tower, int pos, int length)
{;
    //checking if we got stuck and can hop no further
    if (tower[pos] == 0)
        return false;
    //check to see if we've cleared the end of the array
    if (tower[pos] + pos >= length)
    {
        return true;
    }
    //hop to furthest position possible first, then keep hopping less and less.
    for (int i = tower[pos]; i >  0;  i--)
    {
        if (isHoppable(tower, pos+i,length))
            return true;
    }
    //none of the possible hops and children cleared the array.
    return false;
}

int main()
{
    int *tower = new int[6] {3,0,1,2,0,1};

    if (isHoppable(tower, 0, 6))
        std::cout << "Congratulations! Your tower is hoppable.";
    else
        std::cout << "Sorry, your tower is not hoppable";

}
