/*
Problem: 3709. Design Exam Scores Tracker

You are given a series of exams taken by Alice, and you need to track her scores over time.

Implement the ExamTracker class:

- ExamTracker(): Initializes the ExamTracker object.
- void record(int time, int score): Records an exam at time time with score score.
- long long totalScore(int startTime, int endTime): Returns the total score of all exams between startTime and endTime (inclusive). If there are no exams in the range, return 0.

It is guaranteed that function calls will be made in chronological order.

Approach:
- Step 1: Maintain two vectors 'times' and 'sums':
    - 'times': Tracks the times when Alice took exams.
    - 'sums': Tracks the cumulative sum of scores up to each exam time.
- Step 2: The 'record()' method adds a new score to 'times' and 'sums'.
- Step 3: The 'totalScore()' method calculates the total score within a time range by using binary search to find the start and end indices in 'times' and calculating the total using 'sums'.

Time Complexity: O(log n) for totalScore() due to binary search and O(1) for record().
Space Complexity: O(n), where n is the number of exams, because we store 'times' and 'sums' vectors.
*/

class ExamTracker {
public:
    // Constructor: Initializes the ExamTracker object
    ExamTracker() {
    }
    
    // Vectors to store the times of exams and cumulative scores
    vector<int> times;
    vector<long long> sums;
    
    // Method to record a new exam score at a given time
    void record(int time, int score) {
        times.push_back(time); // Add the exam time to 'times' vector
        // Update the cumulative score vector
        if(sums.empty()){
            sums.push_back(score); // First record, just store the score
        }
        else{
            sums.push_back(score + sums.back()); // Add score to the last cumulative sum
        }
    }
    
    // Method to calculate the total score between a given time range
    long long totalScore(int startTime, int endTime) {
        // Find the start and end indices using binary search
        auto st = lower_bound(times.begin(), times.end(), startTime);
        auto end = upper_bound(times.begin(), times.end(), endTime);
        
        int stIdx = st - times.begin(); // Index of the first element >= startTime
        int endIdx = end - times.begin() - 1; // Index of the last element <= endTime
        
        // If no records exist in the time range, return 0
        if(stIdx > endIdx){
            return 0;
        }
        
        long long total = sums[endIdx]; // Get the cumulative sum up to 'endTime'
        
        // If there are records before 'startTime', subtract them from the total
        if(stIdx > 0){
            total -= sums[stIdx - 1]; // Subtract the sum up to just before 'startTime'
        }
        
        return total; // Return the total score in the given time range
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
