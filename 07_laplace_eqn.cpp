#include<stdio.h>
#include<math.h>

int main() {
    int i, j, k, iter, n;
    float u[20][20], u_prev[20][20];

    printf("Enter n and iter: \n");
    scanf("%d%d", &n, &iter);

    // Initialize boundary conditions and make sure the grid is zero-initialized elsewhere
    for (j = 0; j <= n; j++) {
        u[0][j] = 1000;      // Top boundary
        u[n][j] = (j == 0) ? 1000 : 500;  // Bottom boundary
    }
    for (i = 1; i < n; i++) {
        u[i][0] = 2000;  // Left boundary
        u[i][n] = 500;   // Right boundary
    }#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, iter, n;
    float u[20][20], u_prev[20][20];

    printf("Enter n and iter: \n");
    scanf("%d%d", &n, &iter);

    // Initialize boundary conditions and make sure the grid is zero-initialized elsewhere
    for (j = 0; j <= n; j++) {
        u[0][j] = 1000;      // Top boundary
        u[n][j] = (j == 0) ? 1000 : 500;  // Bottom boundary
    }
    for (i = 1; i < n; i++) {
        u[i][0] = 2000;  // Left boundary
        u[i][n] = 500;   // Right boundary
    }

    // Initialize the interior grid to zero
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            u[i][j] = 0;
        }
    }

    printf("The initial grid is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%5.2f \t", u[i][j]);
        }
        printf("\n");
    }

    // Perform Gauss-Jacobi iterations
    for (k = 0; k < iter; k++) {
        // Copy current values to u_prev for the Jacobi update
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                u_prev[i][j] = u[i][j];
            }
        }

        // Update the interior grid points using Gauss-Jacobi formula
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                u[i][j] = 0.25 * (u_prev[i][j - 1] + u_prev[i][j + 1] + u_prev[i - 1][j] + u_prev[i + 1][j]);
            }
        }

        // Print the grid after each iteration
        printf("After iteration %d:\n", k + 1);
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                printf("%5.2f \t", u[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}


    // Initialize the interior grid to zero
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            u[i][j] = 0;
        }
    }

    printf("The initial grid is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            printf("%5.2f \t", u[i][j]);
        }
        printf("\n");
    }

    // Perform Gauss-Jacobi iterations
    for (k = 0; k < iter; k++) {
        // Copy current values to u_prev for the Jacobi update
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                u_prev[i][j] = u[i][j];
            }
        }

        // Update the interior grid points using Gauss-Jacobi formula
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                u[i][j] = 0.25 * (u_prev[i][j - 1] + u_prev[i][j + 1] + u_prev[i - 1][j] + u_prev[i + 1][j]);
            }
        }

        // Print the grid after each iteration
        printf("After iteration %d:\n", k + 1);
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                printf("%5.2f \t", u[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
