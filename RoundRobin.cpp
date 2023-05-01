#include<iostream>
using namespace std;
 
void waitTime(int pValue[], int n, 
            int bTime[], int wTime[], int qTime) 
{
    
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bTime[i];
    int t = 0; 
 
    
    while (1)
    {
        bool done = true; 
        for (int i = 0 ; i < n; i++)
        { 
            if (rem_bt[i] > 0)
            {
                done = false; 
                if (rem_bt[i] > qTime)
                {
                    t += qTime;
                    rem_bt[i] -= qTime;
                }
                else
                {
                    t = t + rem_bt[i];
                    wTime[i] = t - bTime[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
        break;
    }
}
void totalAveTime(int pValue[], int n,
                        int bTime[], int wTime[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bTime[i] + wTime[i];
}
void averageTime(int pValue[], int n, int bTime[], int qTime)
{
    int wTime[n], tat[n], total_wt = 0, total_tat = 0;
    waitTime(pValue, n, bTime, wTime, qTime);
    totalAveTime(pValue, n, bTime, wTime, tat);
    cout << "Processes "<< " Burst Time "
        << " Waiting Time " << " Turn Around Time\n";
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wTime[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bTime[i] <<"\t "
            << wTime[i] <<"\t\t " << tat[i] <<endl;
    }
    cout << "Average Waiting Time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage Turn Around Time = "
        << (float)total_tat / (float)n;
}
int main()
{
    int pValue[] = { 1, 2, 3};
    int n = sizeof pValue / sizeof pValue[0];
 
    int burst_time[] = {24, 3, 3};
 
    int qTime = 4;
    averageTime(pValue, n, burst_time, qTime);
    return 0;
} 
