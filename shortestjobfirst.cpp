#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// structure to describe the attribites of process
struct Process {
    int id;
    int arrivalTime;
    // burst
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};
bool compareBurstTime(Process a , Process b){
    return a.burstTime < b.burstTime;
}
void shortestJobFirst(vector<Process>& Processes){
    sort(Processes.begin(),Processes.end(),compareBurstTime);
    int currentTime = 0;
    for(int i=0;i<Processes.size();i++){
        if(currentTime < Processes[i].arrivalTime){
            currentTime = Processes[i].arrivalTime ;
        }
        Processes[i].waitingTime = currentTime - Processes[i].arrivalTime ;
        Processes[i].turnaroundTime = Processes[i].waitingTime + Processes[i].burstTime;
        currentTime += Processes[i].burstTime;
    }

    }
    void display(const vector<Process> &processes) {
        cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\n";
        for (const auto &process : processes) {
            cout << process.id << "\t" << process.arrivalTime << "\t" << process.burstTime << "\t" 
                 << process.waitingTime << "\t" << process.turnaroundTime << "\n";
        }
    }



int main(){
    vector<Process> Processes = {
        {1, 0, 3, 0, 0},
        {2, 2, 6, 0, 0},
        {3, 4, 4, 0, 0},
        {4, 6, 5, 0, 0},
        {5, 8, 2, 0, 0}
    };
    shortestJobFirst(Processes);
    display(Processes);

    return 0;


}