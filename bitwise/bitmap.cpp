#include <bits/stdc++.h>

using namespace std;

/*
Use case: I need to maintain a datastructure to know if an LED is turned on, in a collection of 256 LEDs. And imagine if there is no std::map like container available.
Solution: Use bitmap to store such information. 

Note: a 32 bit variable such as uint32_t can store LED information of upto 32 LEDs. So we need an array of uint32_t of multiple 8 to store upto 256 LEDs.

*/

typedef uint32_t word_t;

enum { BITS_PER_WORD = sizeof(word_t) * CHAR_BIT }; // 4 * 8 = 32

#define WORD_OFFSET(b) ((b) / BITS_PER_WORD)
#define BIT_OFFSET(b)  ((b) % BITS_PER_WORD)

void set_bit(word_t* words, uint8_t i){
    words[WORD_OFFSET(i)] |= (1 << BIT_OFFSET(i)); 
}

uint8_t get_bit(word_t* words, uint8_t i){
    word_t word = words[WORD_OFFSET(i)] & (1 << BIT_OFFSET(i));
    return (word != 0);
}

void clear_bit(word_t* words, uint8_t i){
    words[WORD_OFFSET(i)] &= ~(1 << BIT_OFFSET(i));
}

int main(){
    word_t words[8] = {0}; // a bitmap of 32 * 8 = 256 bit length

    set_bit(words, 255); // turn on 255th LED
    set_bit(words, 5); //turn on 5th LED

    printf("0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n", words[7], words[6], words[5], words[4], words[3], words[2], words[1], words[0]);

    return 0;
}
