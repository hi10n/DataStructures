#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

static const uint32_t MaxJobsPersons = 30;

uint32_t FindOptimalDays(vector<vector<uint32_t>>* pAllDays,
                         vector<vector<uint32_t>>* pAllDaysIndices,
                         vector<uint32_t>          jobsTaken,
                         uint32_t                  person,
                         uint32_t                  accumSoFar,
                         uint32_t                  maxPersonsJobs)
{
    static int32_t totalDays = -1;
    
    if (accumSoFar > totalDays)
    {
        return totalDays;
    }
    
    vector<vector<uint32_t>>::iterator itIndices = pAllDaysIndices->begin();
    vector<uint32_t> personJobIndices = *(itIndices + person);
    vector<uint32_t>::iterator it;
    
    for (it = jobsTaken.begin(); it != jobsTaken.end(); it++)
    {
        vector<uint32_t>::iterator delIt;
        delIt = find(personJobIndices.begin(), personJobIndices.end(), *it);
        personJobIndices.erase(delIt);
    }
    
    for (it = personJobIndices.begin(); it != personJobIndices.end(); it++)
    {
        vector<vector<uint32_t>>::iterator perPersonItr = pAllDays->begin();
        vector<uint32_t> perPersonDays = *(perPersonItr + person);
        
        jobsTaken.push_back(*it);
        
        if ((person + 1) < maxPersonsJobs)
        {
            if ((accumSoFar + perPersonDays[*it]) < totalDays)
            {
                FindOptimalDays(pAllDays, pAllDaysIndices, jobsTaken, person + 1, accumSoFar + perPersonDays[*it], maxPersonsJobs);
            }
        }
        else
        {
            if (totalDays > (accumSoFar + perPersonDays[*it]))
            {
                totalDays = (accumSoFar + perPersonDays[*it]);
            }
        }
        
        jobsTaken.pop_back();
    }
    
    return totalDays;
}

int main(int argc, const char * argv[])
{
    uint32_t                 numTestcases;
    uint32_t                 numPersonsJobs;
    vector<vector<uint32_t>> allDays;
    vector<vector<uint32_t>> allDaysIndices;
    vector<uint32_t>         personDays;
    uint32_t                 optimalDays;
    vector<uint32_t>         jobsTaken;
    
    cin >> numTestcases;
    
    for (uint32_t i = 0; i < numTestcases; i++)
    {
        cin >> numPersonsJobs;
    
        allDaysIndices.clear();
        allDays.clear();
        jobsTaken.clear();

        for (uint32_t person = 0; person < numPersonsJobs; person++)
        {
            vector<uint32_t> indices;
            
            personDays.clear();
            indices.clear();
            
            for (uint32_t jobs = 0; jobs < numPersonsJobs; jobs++)
            {
                uint32_t numDays;
                
                cin >> numDays;
                personDays.push_back(numDays);
                indices.push_back(jobs);
            }
            
            sort(indices.begin(), indices.end(), [&personDays](int a, int b) { return personDays[a] < personDays[b]; });
            allDaysIndices.push_back(indices);
            allDays.push_back(personDays);
        }
        
        jobsTaken.clear();
        optimalDays = FindOptimalDays(&allDays, &allDaysIndices, jobsTaken, 0, 0, numPersonsJobs);
        
        cout << optimalDays << "\n";
    }
    
    cout << "\n";
    
    return 0;
}



