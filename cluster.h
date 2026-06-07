#ifndef CLUSTER_H
#define CLUSTER_H

typedef struct {
    double x, y;
    int cluster_id;
} DataPoint;

typedef struct {
    double x, y;
} Centroid;

void run_kmeans(DataPoint* points, int num_points, Centroid* centroids, int k);

#endif
