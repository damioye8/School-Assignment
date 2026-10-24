#include <stdio.h>

int main(void)
{
    int angle1, angle2, angle3;

    printf("Enter two angles in whole degrees: ");

    if (scanf("%d %d", &angle1, &angle2) != 2) {
        printf("Invalid input. Enter two whole numbers.\n");
        return 1;
    }

    /* Check each angle before adding them. */
    if (angle1 <= 0 || angle1 >= 180 ||
        angle2 <= 0 || angle2 >= 180) {
        printf("These angles cannot form a triangle.\n");
        return 0;
    }

    angle3 = 180 - (angle1 + angle2);

    if (angle3 <= 0) {
        printf("These angles cannot form a triangle.\n");
    } else if (angle1 == 90 || angle2 == 90 || angle3 == 90) {
        printf("The third angle is %d degrees.\n", angle3);
        printf("It is a right-angled triangle.\n");
    } else {
        printf("The third angle is %d degrees.\n", angle3);
        printf("It is not a right-angled triangle.\n");
    }

    return 0;
}