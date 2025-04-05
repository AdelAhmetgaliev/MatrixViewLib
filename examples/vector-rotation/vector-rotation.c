/**
 * Работа с MatrixView на примере разворота вектора на 45°.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrixview.h"

static double degreesToRadians(double degrees);

int main(void) {
    double angleDegrees = 45.0;
    double angleRadians = degreesToRadians(angleDegrees);

    double vectorData[] = { 1, 0 };
    double rotationData[] = {
        cos(angleRadians), -sin(angleRadians),
        sin(angleRadians), cos(angleRadians)
    };

    double *resultData = calloc(2, sizeof(double));
    if (!resultData) {
        fprintf(stderr, "Не удалось выделить память.\n");
        return EXIT_FAILURE;
    }

    MatrixView vector = mv_new(vectorData, 2, 1);
    MatrixView rotationMatrix = mv_new(rotationData, 2, 2);
    MatrixView resultVector = mv_new(resultData, 2, 1);

    mv_dot(&resultVector, &rotationMatrix, &vector);
    mv_print(&resultVector);

    if (resultData) {
        free(resultData);
        resultData = NULL;
    }

    return EXIT_SUCCESS;
}

static double degreesToRadians(double degrees) {
    return degrees * (M_PI / 180.0);
}
