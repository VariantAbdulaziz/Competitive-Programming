// source: https://www.hackerrank.com/challenges/grading/submissions/code/269658590

// strategy: ad hoc solution
vector<int> gradingStudents(vector<int> grades) {

    vector<int> finalMarks;
    int n = grades.size();
    
    for(size_t i{}; i < n; i++){
        int mod = grades[i]%5;
        if(5 - mod >= 3 || mod == 0 || grades[i] < 38)
            finalMarks.push_back(grades[i]);
        else
            finalMarks.push_back(grades[i] - mod + 5);
    }
    
    return finalMarks;
}