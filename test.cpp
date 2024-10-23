// Psuedocode
// function estimate_pi(number_of_loop, current_loop, current_value)
//     if current_loop == number_of_loop
//         return current_value
//     else
//         current_sum += 4 / (2 * current_loop + 1) * (-1) ** current_loop
//         return estimate_pi(number_of_loop, current_loop + 1, current_value)
// Complexity: O(n)

#include <stdio.h>

#include <math.h>

float estimate_pi(int number_of_loop, int current_loop, float current_value) {
    if (current_loop == number_of_loop) {
        return current_value;
    } else {
        current_value += 4.0 / (2 * current_loop + 1) * pow(-1, current_loop);
        return estimate_pi(number_of_loop, current_loop + 1, current_value);
    }
}

int main() {
    int number_of_loop;
    printf("Enter the number of loop: ");
    scanf("%d", & number_of_loop);
    printf("The value of pi is: %.10f", estimate_pi(number_of_loop, 0, 0.0));
    return 0;
}