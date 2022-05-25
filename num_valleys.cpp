// source: https://www.hackerrank.com/challenges/counting-valleys/problem

// strategy: semaphores
int countingValleys(int steps, string path) {
    int numVals{}, height{}, semaphore{};
    for(auto dir: path){
        if(dir == 'D'){
            if(height <= 0) semaphore++;
            height--;
        }else {
            if(height < 0) semaphore--;
            height++;
            if(height == 0 and semaphore == 0)
                numVals++;
        }
    }
    return numVals;
}