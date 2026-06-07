#include <math.h>
#include <float.h>
#include "cluster.h"

void run_kmeans(DataPoint* points, int num_points, Centroid* centroids, int k) {
    // Step 1: Assignment Phase
    for (int i = 0; i < num_points; i++) {
        double min_dist = DBL_MAX;
        int closest_centroid = 0;
        
        for (int c = 0; c < k; c++) {
            double dx = points[i].x - centroids[c].x;
            double dy = points[i].y - centroids[c].y;
            double dist = sqrt(dx*dx + dy*dy);
            
            if (dist < min_dist) {
                min_dist = dist;
                closest_centroid = c;
            }
        }
        points[i].cluster_id = closest_centroid;
    }

    // Step 2: Update Phase (Recalculate Centroid Coordinates)
    for (int c = 0; c < k; c++) {
        double sum_x = 0, sum_y = 0;
        int count = 0;
        
        for (int i = 0; i < num_points; i++) {
            if (points[i].cluster_id == c) {
                sum_x += points[i].x;
                sum_y += points[i].y;
                count++;
            }
        }
        if (count > 0) {
            centroids[c].x = sum_x / count;
            centroids[c].y = sum_y / count;
        }
    }
}
