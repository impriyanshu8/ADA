#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Activity {
    int start;
    int finish;
    int index; 
};


bool activityCompare(const Activity &a1, const Activity &a2) {
    return (a1.finish < a2.finish);
}


vector<Activity> selectActivities(vector<Activity> &activities) {
   
    sort(activities.begin(), activities.end(), activityCompare);
    
    vector<Activity> selected;
    
    
    selected.push_back(activities[0]);
    int lastSelected = 0;
    
    
    for (int i = 1; i < activities.size(); i++) {
       
        if (activities[i].start >= activities[lastSelected].finish) {
            selected.push_back(activities[i]);
            lastSelected = i;
        }
    }
    
    return selected;
}


void displayActivities(const vector<Activity> &activities) {
    cout << "Selected Activities:\n";
    cout << "Index\tStart\tFinish\n";
    for (const auto &activity : activities) {
        cout << activity.index << "\t" << activity.start << "\t" << activity.finish << endl;
    }
}

int main() {

    vector<Activity> activities = {
        {5, 9, 1},
        {1, 2, 2},
        {3, 4, 3},
        {0, 6, 4},
        {5, 7, 5},
        {8, 9, 6}
    };
    
    vector<Activity> selected = selectActivities(activities);
    displayActivities(selected);
    
    cout << "\nTotal activities selected: " << selected.size() << endl;
    
    return 0;
}