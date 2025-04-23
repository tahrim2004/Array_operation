#include <stdio.h>

void insert_arr(int arr[], int n) {
    printf("Please input your values:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void update(int arr[], int n) {
    printf("Update value\n");
    int position, value;
    printf("Input your array position: ");
    scanf("%d", &position);
    if (position >= 1 && position <= n) {
        printf("Input your new value: ");
        scanf("%d", &value);
        arr[position - 1] = value;
    } else {
        printf("Invalid position!\n");
    }
}

int delete_arr(int arr[], int n) {
    printf("Delete value\n");
    int position;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &position);
    if (position >= 1 && position <= n) {
        for (int i = position - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Element deleted.\n");
    } else {
        printf("Invalid position!\n");
    }
    return n;
}

void search(int arr[], int n) {
    printf("Search array value\n");
    int value;
    printf("Enter the value to search for: ");
    scanf("%d", &value);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Value %d found at position: %d\n", value, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d not found in the array\n", value);
    }
}

void sort(int arr[], int n) {
    printf("Sorting array values...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

void print_array(int arr[], int n) {
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, arr[100];

    printf("Please enter your array size (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size. Must be between 1 and 100.\n");
        return 1;
    }

    insert_arr(arr, n);
    print_array(arr, n);

    int choice;

    while (1) {
        printf("\nChoose an option:\n 1. Update\n 2. Delete\n 3. Search\n 4. Sort\n 5. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            update(arr, n);
        } else if (choice == 2) {
            n = delete_arr(arr, n);
        } else if (choice == 3) {
            search(arr, n);
        } else if (choice == 4) {
            sort(arr, n);
        } else if (choice == 5) {
            printf("Thank you! Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        print_array(arr, n);
    }

    return 0;
}