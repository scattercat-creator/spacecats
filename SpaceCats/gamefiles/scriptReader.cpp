#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// the variable that holds the text file
ifstream myFile;



// the global variable that reads the text line by line
string myString;

// assigns who's collecting points at the current time
int pointCollector;

// the options the player is currently considering
vector<string> options{"","",""};

// the possible points the player can collect choosing the corresponding option in the options vector
vector<int> points{0, 0, 0};

// the points held by each NPC that the character has collected
vector<int> npcpoints{0, 0, 0};

// keeps track of whether or not there was a flag occuring at that time
int flag = 0;

// keeps track of which character corresponds to which index on the vectors
enum characters
{
    BOSS,
    HARVEY,
    TOMMY
};

// keep track of which option was chosen
//int picked = 0;
bool needsInput = false;

// records which return values from the checking function lead to which functions 

enum npcs {
    POSTABLE = 0,
    POINTCOLLECTOR = 1,
    CHOICE = 2,
    CHOICERESULT = 3,
    EVENT = 4,
    DONTPRINT = 5
};

// checks the script to see if it can post the text or has to deal with tags ):
int checkType(string checkString)
{
    if (checkString[0] == '[')
    {
        return POINTCOLLECTOR;
    }
    else if(checkString[0] == '|')
    {
        return CHOICE;
    }
    else if(checkString[0] == '{')
    {
        return CHOICERESULT;
    }
    else if(checkString[0] == '@')
    {
        return EVENT;
    }
    else if(checkString[0] == '}')
    {
        return DONTPRINT;
    }
    else
    {
        return POSTABLE;
    }
}

// sets who's currently collecting points

void setPointCollector(string newPointCollector)
{
    if(newPointCollector == "[BOSS]")
    {
        pointCollector = BOSS;
    }
    else if(newPointCollector == "[HARVEY]")
    {
        pointCollector == HARVEY;
    }
    else if(newPointCollector == "[TOMMY]")
    {
        pointCollector = TOMMY;
    }
}

// seperates the choices line into three seperate choices so i can change the lines and make it fancy in SDL
// also defines how many points can go to the point collector 

void seperateChoices(string choices)
{
    int start = -1;
    options[0] = "";
    options[1] = "";
    options[2] = "";
    points[0] = 0;
    points[1] = 0;
    points[2] = 0;
    for(int i = 0; i < choices.length(); i++)
    {
        if(choices[i] == '|')
        {
            start += 1;
            i += 2;
            points[start] = choices[i] - '0';
            i++;

        }
        else
        {
            options[start] += choices[i];
        }
    }
}

// actually prints the seperated choices to the screen
// as a side thing, this script also takes in user input and assigns points to the point collector

string showChoices()
{
    string returnedString = "";
    int done = 0;
    returnedString += "possible responses: \n";
    while (done < 3)
    {
        returnedString += options[done] + "\n";
        done += 1;
    }
    return returnedString;
}

// this is what changes what storyline the player sees based on what option they chose
// first it skips to that option, then it prints it, and then it skips all the options the player didn't choose

std::string resultChoice(int picked, int* runs)
{
    string skipper;
    int counter = 0;
    bool completed = false;
    counter = 0;
    if(*runs == 1)
    {
        switch (picked)
        {
            case 1:
            npcpoints[pointCollector] += points[0];
            break;
            case 2:
            npcpoints[pointCollector] += points[1];
            break;
            case 3:
            npcpoints[pointCollector] += points[2];
            break;

        }
        
        while(counter < picked)
        {
            getline(myFile, skipper);
            if (skipper[0] == '{')
            {
                counter += 1;
            }
        }
        *runs = 2;
    }
    
    // once you hit a { stop the counter and move into the next while loop
    else if (*runs == 2) // turn off getline from the 
    {
        getline(myFile, skipper);

        if (skipper[0] == '}')
        {
            *runs = 3;
        }
        else
        {
            return skipper;
        }
        
    }
    
    
    else if (*runs == 3)
    {
        while(picked < 3)
        {
            getline(myFile, skipper);
            if (skipper[0] == '}')
            {
                picked += 1;
            }
        }
        *runs = 0;
    }
    return "";

    
}



// this returns true if a player has enough points from a specific character to run an event

bool eventFlag(string line)
{
    int pointsNeeded = line[1] - '0';
    string sub = line.substr(2);
  
    if (sub == "TOMMY" && npcpoints[TOMMY] >= pointsNeeded)
    {
        return true;
    }
    else if (sub == "BOSS" && npcpoints[BOSS] >= pointsNeeded)
    {
        return true;
    }
    else if (sub == "HARVEY" && npcpoints[HARVEY] >= pointsNeeded)
    {
        return true;
    }
    return false;
}

// this will actually run the event if the flag function returns true 
// it'll skip the event otherwise

string runEvent(bool running, int * runs)
{
    string temp;
    getline(myFile, temp);
    if(temp[0] != '@')
    {
        if(running)
        {
            return temp;
        } 
    }
    else
    {
        *runs = 0;
    }
    return "";
}

string runScript(int input, int *runs, bool* needsInput)
{   
    string final;


    while(myFile.good())
    {
        if(flag == 0)
        {
            getline(myFile, myString);
            
            switch (checkType(myString))
            {
                case POSTABLE:
                    return myString;
                
                case EVENT:
                    flag = EVENT;
                    *runs = 1;
                    break; 
                
                case CHOICE:

                    seperateChoices(myString);
                    flag = CHOICE;
                    *runs = 1;
                    *needsInput = true;
                    return showChoices();

                case POINTCOLLECTOR:
                    setPointCollector(myString);
                    break; 
            }
        }

        else if (flag == CHOICE)
        { 
            final = resultChoice(input, runs);
            *needsInput = false;
            if(final != "")
            {
                return final;
            }
            if(*runs == 0)
            {
                flag = 0;
                // reset input here, but like, use the address of the real variable ig...
            }
        }
        else if (flag == EVENT)
        {
            final = runEvent(eventFlag(myString), runs);
            if(final != "")
            {
                return final;
            }
            else if(*runs == 0)
            {
                flag = 0;
            }
            
        }
    }
    return "end";
    
}

void initReader()
{
    myFile.open("res/myDialogue.txt");

}


