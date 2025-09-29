#include <stdio.h>
#define SIZE 100

int main() {
    int arr[SIZE], n = 0, choice, elem, pos, I;

    while (1) {
        printf("\n-- Array Operations Menu --\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                if (n > SIZE) {
                    printf("Maximum limit exceeded!\n");
                    break;
                }
                printf("Enter %d elements:\n", n);
                for (I = 0; I < n; I++) {
                    scanf("%d", &arr[I]);
                }
                break;

            case 2:
                if (n == 0)
                    printf("Array is empty.\n");
                else {
                    printf("Array elements are:\n");
                    for (I = 0; I < n; I++) {
                        printf("arr[%d] = %d\n", I, arr[I]);
                    }
                }
                break;

            case 3:
                if (n == SIZE) {
                    printf("Array is full. Cannot insert.\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (I = n; I > pos; I--) {
                        arr[I] = arr[I - 1];
                    }
                    arr[pos] = elem;
                    n++;
                    printf("Element inserted.\n");
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty. Cannot delete.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);

                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    elem = arr[pos];
                    for (I = pos; I < n - 1; I++) {
                        arr[I] = arr[I + 1];
                    }
                    n--;
                    printf("Element %d deleted.\n", elem);
                }
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again!\n");
        }
    }
}