#include <bits/stdc++.h>

using namespace std;

//constexpr int getRandomNum() {return (rand() % 10); } /*this cannot be marked as constexpr because rand() cannot be evaluated at compile time*/

constexpr int add(int x, int y) {return (x + y); } /*this can be marked as constexpr*/

int main(){
    /*compiler error for below line because y can only be assigned from function getRandomNum() if it is entirely expressed in const.
     *In this case getRandomNum() has rand() function which cannot be evaluated at compile time.
     */
    //constexpr int y = getRandomNum(); 

    constexpr int z = add(10, 20);// compiles ok: because add(int, int) has both const arguments and thus can be assigned to constexpr variable z

    const int z_2 = add(10, 20);// compiles ok: because add(int, int) has both const arguments and thus can be assigned to const variable z_2

    int a = 2, b = 3;

    /*
     *
     *constexpr int c = add(a, b);
     *
     * this is a compiler error because a and b as arguments in add(int, int) cannot be evaluated at compile time while assigning to a constexpr variable c
     */
     
    
    /*below line compiles ok: because d is not a constexpr*/
    int d = add(a, b);

    const int e = add(a, b); //compiles ok

    return 0;
}