#include <stdio.h>
#include "cluster.h"

int main() {
    printf("📊 Initializing ClusterK-Means Analytical Vector Engine...\n\n");

    // Dynamic Mock Datasets
    DataPoint dataset[4] = {
        {1.0, 1.2, -1}, {1.5, 1.8, -1},
        {8.0, 9.1, -1}, {8.5, 9.5, -1}
    };
    
    // Seed initial configuration parameters for 2 Centroids
    Centroid clusters[2] = { {0.0, 0.0}, {10.0, 10.0} };

    printf("🔄 Executing mathematical clustering optimization updates...\n");
    run_kmeans(dataset, 4, clusters, 2);

    printf("\n🎯 Execution Complete. Cluster Node Mappings:\n");
    for (int i = 0; i < 4; i++) {
        printf("   • Node Data Location (%.1f, %.1f) allocated to Cluster ID: %d\n", 
                dataset[i].x, dataset[i].y, dataset[i].cluster_id);
    }

    return 0;
}
