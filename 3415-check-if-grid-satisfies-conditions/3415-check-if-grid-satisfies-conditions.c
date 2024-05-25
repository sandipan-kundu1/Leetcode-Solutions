bool satisfiesConditions(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize - 1; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            
            if (grid[i][j] != grid[i + 1][j])
                return false; 
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize - 1; j++) {
            
            if (grid[i][j] == grid[i][j + 1])
                return false; 
        }
    }
    
    
    return true;
}